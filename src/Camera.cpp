//
// Created by andreivoiculas on 07/01/19.
//
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/quaternion.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <unistd.h>
#include "include/Camera.h"
#include <stdio.h>
#include <iostream>
#include <include/Camera.h>


float lastXPos;
float lastYPos;

Camera::Camera(GLFWwindow* window,float width,float height) {
    Camera::window = window;
    Camera::width = width;
    Camera::height = height;
    Camera::translation = glm::mat4(1.0f);
    Camera::fov = 45.0f;
    Camera::speed = 1.0f;
    Camera::projection = glm::mat4(1.0f);
    Camera::projection = glm::perspective(glm::radians(Camera::fov), Camera::width/Camera::height, 0.1f, 100.0f);
    Camera::sensitivity = 1.0;
    //cos(0/2),1*sin(0/2),0*sin(0/2),0*sin(0/2)
    Camera::view_rotation = glm::quat(0.0f,0.0f,-1.0f,0.0f);
    Camera::move_rotation = glm::quat(0.0f,0.0f,-1.0f,0.0f);
//    Camera::view_rotation = glm::rotate(Camera::view_rotation,glm::radians(-90.0f),glm::vec3(0.0f,1.0f,0.0f));
//    Camera::view_rotation = glm::rotate(Camera::view_rotation,glm::radians(90.0f),glm::vec3(1.0f,0.0f,0.0f));
    Camera::view = glm::mat4_cast(Camera::view_rotation)*Camera::translation;

    lastXPos = width/2;
    lastYPos = height/2;

}

Camera::Camera(glm::vec3 position, GLFWwindow *window, float width, float height) : Camera(window,width,height){
    translation = glm::translate(translation,position);
}

Camera::Camera(glm::quat rotation, glm::mat4 translation, float fov,float width,float height) {
    Camera::translation = translation;
    Camera::width = width;
    Camera::height = height;
    Camera::fov = fov;
    Camera::speed = 1.0f;
    Camera::projection = glm::mat4(1.0f);
    Camera::projection = glm::perspective(glm::radians(Camera::fov), Camera::width/Camera::height, 0.1f, 100.0f);
    Camera::view_rotation = rotation;
    Camera::move_rotation = rotation;
    Camera::view = glm::mat4_cast(Camera::view_rotation)*Camera::translation;
}

glm::mat4 Camera::getView() {
    return Camera::view;
}

glm::mat4 Camera::getProjection() {
    return Camera::projection;
}

Camera::~Camera() = default;

float Camera::bijection(float from1,float to1,float from2,float to2, float x)
{
    return (to2-from2)*(x-from1)/(to1-from1) + from2;
}


void Camera::mouse_callback(GLFWwindow* window, double xPos, double yPos)
{
    float offsetX = sensitivity*(float)(xPos- lastXPos);
    float offsetY = sensitivity*(float)(yPos - lastYPos);
    float mouse_sensitivity = 0.1;
    lastXPos = (float)xPos;
    lastYPos = (float)yPos;
    float xyRotation = bijection(-Camera::width/2,Camera::width/2,-360,360,offsetX);
    float yzRotation = bijection(-Camera::height/2,Camera::height/2,-90,90,offsetY);
    Camera::view_rotation = glm::rotate(Camera::view_rotation,glm::radians(xyRotation),glm::vec3(0.0f,1.0f,0.0f));
    Camera::move_rotation = glm::rotate(Camera::move_rotation,glm::radians(xyRotation),glm::vec3(0.0f,1.0f,0.0f));
    Camera::view_rotation = glm::rotate(Camera::view_rotation,glm::radians(yzRotation),
                                   glm::vec3(1.0f,0.0f,0.0f)*glm::mat3_cast(Camera::view_rotation));
    printf("%s\n",glm::to_string(move_rotation).c_str());

}

void Camera::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
    Camera::width = (float)width;
    Camera::height = (float)height;
    Camera::projection = glm::perspective(glm::radians(Camera::fov), Camera::width/Camera::height, 0.1f, 100.0f);
}

void Camera::keyboardUpdate() {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        translation = glm::translate(translation,speed*glm::vec3(0.0f,0.0f,0.01f)*glm::mat3_cast(move_rotation));
        usleep(1000);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        translation = glm::translate(translation,speed*glm::vec3(0.0f,0.0f,-0.01f)*glm::mat3_cast(move_rotation));
        usleep(1000);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        translation = glm::translate(translation,speed*glm::vec3(0.01f,0.0f,0.0f)*glm::mat3_cast(move_rotation));
        usleep(1000);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        translation = glm::translate(translation,speed*glm::vec3(-0.01f,0.0f,0.0f)*glm::mat3_cast(move_rotation));
        usleep(1000);
    }
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
        translation = glm::translate(translation,speed*glm::vec3(0.0f,-0.01f,0.0f));
        usleep(1000);
    }
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
        translation = glm::translate(translation,speed*glm::vec3(0.0f,0.01f,0.0f));
        usleep(1000);
    }
}

void Camera::updateView() {
    view = glm::mat4_cast(view_rotation)*translation;
}

glm::vec3 Camera::getPosition() {
    return glm::vec3((-translation)*glm::vec4(0.0f,0.0f,0.0f,1.0f));
}

float Camera::getWidth() {
    return width;
}

float Camera::getHeight() {
    return height;
}

