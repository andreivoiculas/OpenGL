//
// Created by andreivoiculas on 07/01/19.
//

#ifndef OPENGL_CAMERA_H
#define OPENGL_CAMERA_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/detail/type_quat.hpp>

class Camera {
private:
    glm::mat4 view;
    glm::mat4 translation;
    glm::quat view_rotation;
    glm::quat move_rotation;
    float fov;
    float width;
    float height;
    float sensitivity;
    float speed;
    glm::mat4 projection;
    GLFWwindow* window;
    static float bijection(float from1,float to1,float from2,float to2, float x);

public:
    Camera(GLFWwindow* window,float width,float height);
    Camera(glm::vec3 position,GLFWwindow* window,float width,float height);
    Camera(glm::quat rotation,glm::mat4 translation,float fov,float width,float height);
    void keyboardUpdate();
    glm::mat4 getView();
    glm::mat4 getProjection();
    float getWidth();
    float getHeight();
    glm::vec3 getPosition();
    void updateView();
    void mouse_callback(GLFWwindow* window, double xPos, double yPos);
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    typedef void (*mouse_p)(GLFWwindow* window, double xPos, double yPos),
                 (*frame_buff_p)(GLFWwindow* window, int width, int height);
    ~Camera();
};


#endif //OPENGL_CAMERA_H
