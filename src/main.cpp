#define STB_IMAGE_IMPLEMENTATION
#define GLM_ENABLE_EXPERIMENTAL

#include "include/stb_image.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <string>
#include <iostream>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>
#include <unistd.h>
#include <glm/gtx/string_cast.hpp>
#include <vector>
#include <include/Shape.h>
#include <include/MovingShape.h>
#include <include/Particles.h>
#include "include/Camera.h"
#include "include/Shader.h"
#include "include/Program.h"


void mouse_callback(GLFWwindow* window, double xPos, double yPos);
void framebuffer_size_callback(GLFWwindow*, int width, int height);

void CheckOpenGLError(const char* stmt, const char* fname, int line)
{
    GLenum err = glGetError();
    if (err != GL_NO_ERROR)
    {
        printf("OpenGL error %08x, at %s:%i - for %s\n", err, fname, line, stmt);
        abort();
    }
}


#define GL_CHECK(stmt) do { \
            stmt; \
            CheckOpenGLError(#stmt, __FILE__, __LINE__); \
        } while (0)


static void LoadTexture(unsigned int texturePtr,const char *filepath,GLenum imgFormat,GLenum activeTexture)
{
    glGenTextures(1, &texturePtr);
    glActiveTexture(activeTexture);
    glBindTexture(GL_TEXTURE_2D, texturePtr);
// set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// load and generate the texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load(filepath, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,imgFormat, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}

int _width = 480;
int _height = 480;
Camera* camera;
int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1920, 1060, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    camera = new Camera(glm::vec3(0.0f,0.0f,20.0f),window,_width,_height);
    glfwSetCursorPosCallback(window,mouse_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    if (glewInit() != GLEW_OK)
        printf("GLEW did not initialize correctly");

//    std::vector<Vertex> positions = {
//            Vertex(glm::vec3(-0.5f,-0.5f,-0.5f)),
//            Vertex(glm::vec3(0.5f,-0.5f,-0.5f)),
//            Vertex(glm::vec3(-0.5f,0.5f,-0.5f)),
//
//            Vertex(glm::vec3(0.5f,-0.5f,-0.5f)),
//            Vertex(glm::vec3(0.5f,0.5f,-0.5f)),
//            Vertex(glm::vec3(-0.5f,0.5f,-0.5f))
//
//    };

    std::vector<Vertex> positions = {
            Vertex(glm::vec3(4.5f,5.0f,0.0f),glm::vec3(-0.1f,0.0f,0.0f),glfwGetTime(),VELOCITY),
            Vertex(glm::vec3(1.5f,10.0f,0.0f),glm::vec3(-0.1f,0.0f,0.0f),glfwGetTime(),VELOCITY),
            Vertex(glm::vec3(-1.5f,20.0f,0.0f),glm::vec3(0.1f,0.0f,0.0f),glfwGetTime(),VELOCITY),
            Vertex(glm::vec3(-4.5f,15.0f,0.0f),glm::vec3(0.1f,0.0f,0.0f),glfwGetTime(),VELOCITY)
//            Vertex(glm::vec3(0.0f,10.0f,0.0f),glm::vec3(0.01f,0.0f,0.0f),glfwGetTime(),VELOCITY)


    };

    std::vector<Vertex> cube_vert = {
            Vertex(glm::vec3(-0.5f,-0.5f,0.5f) ,glm::vec3(0.5f,0.5f,0.5f),glm::vec3(0.0f,0.0f,1.0f),LIGHT),
            Vertex(glm::vec3(0.5f,-0.5f,0.5f),glm::vec3(0.5f,0.5f,0.5f),glm::vec3(0.0f,0.0f,1.0f),LIGHT),
            Vertex(glm::vec3(-0.5f,0.5f,0.5f),glm::vec3(0.5f,0.5f,0.5f),glm::vec3(0.0f,0.0f,1.0f),LIGHT),

            Vertex(glm::vec3(0.5f,-0.5f,0.5f),glm::vec3(0.5f,0.5f,0.5f),glm::vec3(0.0f,0.0f,1.0f),LIGHT),
            Vertex(glm::vec3(0.5f,0.5f,0.5f),glm::vec3(0.5f,0.5f,0.5f),glm::vec3(0.0f,0.0f,1.0f),LIGHT),
            Vertex(glm::vec3(-0.5f,0.5f,0.5f),glm::vec3(0.5f,0.5f,0.5f),glm::vec3(0.0f,0.0f,1.0f),LIGHT),


            Vertex(glm::vec3(0.5f,-0.5f,0.5f) ,glm::vec3(0.5f,0.5f,0.5f),glm::vec3(1.0f,0.0f,0.0f),LIGHT),
            Vertex(glm::vec3(0.5f,-0.5f,-0.5f),glm::vec3(0.5f,0.5f,0.5f),glm::vec3(1.0f,0.0f,0.0f),LIGHT),
            Vertex(glm::vec3(0.5f,0.5f,0.5f),glm::vec3(0.5f,0.5f,0.5f),glm::vec3(1.0f,0.0f,0.0f),LIGHT),

            Vertex(glm::vec3(0.5f,0.5f,0.5f),glm::vec3(0.5f,0.5f,0.5f),glm::vec3(1.0f,0.0f,0.0f),LIGHT),
            Vertex(glm::vec3(0.5f,0.5f,-0.5f),glm::vec3(0.5f,0.5f,0.5f),glm::vec3(1.0f,0.0f,0.0f),LIGHT),
            Vertex(glm::vec3(0.5f,-0.5f,-0.5f),glm::vec3(0.5f,0.5f,0.5f),glm::vec3(1.0f,0.0f,0.0f),LIGHT),


    };

    std::vector<Vertex> floor_vert = {
            Vertex(glm::vec3(-5.0f,-0.5f,-5.0f) ,glm::vec3(0.2f,0.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),LIGHT),
            Vertex(glm::vec3(-5.0f,-0.5f,5.0f) ,glm::vec3(0.2f,0.2f,0.2f),glm::vec3(0.0f,1.0f,0.0f),LIGHT),
            Vertex(glm::vec3(5.0f,-0.5f,5.0f) ,glm::vec3(0.2f,0.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),LIGHT),

            Vertex(glm::vec3(5.0f,-0.5f,5.0f) ,glm::vec3(0.2f,0.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),LIGHT),
            Vertex(glm::vec3(5.0f,-0.5f,-5.0f) ,glm::vec3(0.2f,0.2f,0.2f),glm::vec3(0.0f,1.0f,0.0f),LIGHT),
            Vertex(glm::vec3(-5.0f,-0.5f,-5.0f) ,glm::vec3(0.2f,0.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f),LIGHT)

    };

    Shader* vShape = new Shader(GL_VERTEX_SHADER,"./shaders/particle.vert");
    Shader* gShape = new Shader(GL_GEOMETRY_SHADER,"./shaders/particle.geom");
    Shader* fShape = new Shader(GL_FRAGMENT_SHADER,"./shaders/particle.frag");
    Program* programShape = new Program(vShape,gShape,fShape);

    GL_CHECK();
    Particles* shape = new Particles(positions,programShape,camera);
//    Shape* cube = new Shape(cube_vert,programShape,camera);
//    Shape* floor = new Shape(floor_vert,programShape,camera);

    printf("%s\n",glGetString(GL_VERSION));

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glEnable(GL_DEPTH_TEST);
    glPointSize(20.0f);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        camera->keyboardUpdate();
//        floor->draw(glm::vec3(0.2f,0.2f,0.2f),glm::vec3(0.0f,cos(glfwGetTime()/3.0f)*3.0f +3,0.0f),
//                    glm::vec3(1.0,1.0,1.0));
//        cube->draw(glm::vec3(0.2f,0.2f,0.2f),glm::vec3(cos(glfwGetTime()/3.0f)*3.0f,0.0f,sin(glfwGetTime()/3.0f)*3.0f),
//                    glm::vec3(1.0,1.0,1.0));
    if(glfwGetKey(window,GLFW_KEY_R) == GLFW_PRESS)
        shape->draw();


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

    }
    glfwTerminate();
    return 0;
}

bool mouse = true;
void mouse_callback(GLFWwindow* window, double xPos, double yPos){

    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
        mouse = false;
    if(mouse){
        camera->mouse_callback(window,xPos,yPos);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    camera->framebuffer_size_callback(window,width,height);
}