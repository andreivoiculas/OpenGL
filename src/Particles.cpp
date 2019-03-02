//
// Created by andreivoiculas on 28/02/19.
//
#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/gtc/type_ptr.hpp>
#include "include/Particles.h"

#define CHANGE_TIME 0.014

#define GRAVITY glm::vec3(0.0f,0.001f,0.0f)

//void CheckOpenGLError(const char* stmt, const char* fname, int line)
//{
//    GLenum err = glGetError();
//    if (err != GL_NO_ERROR)
//    {
//        printf("OpenGL error %08x, at %s:%i - for %s\n", err, fname, line, stmt);
//        abort();
//    }
//}
//
//
//#define GL_CHECK(stmt) do { \
//            stmt; \
//            CheckOpenGLError(#stmt, __FILE__, __LINE__); \
//        } while (0)

Particles::Particles(std::vector<Vertex> _vertex_array, Program *_program, Camera *_camera) : MovingShape(_vertex_array,
                                                                                                          _program,
                                                                                                          _camera) {

}

Particles::Particles(std::vector<Vertex> _vertex_array, Program *_program, Camera *_camera, glm::mat4 model)
        : MovingShape(_vertex_array, _program, _camera, model) {

}

void Particles::draw() {
    glUseProgram(program->getID());
    camera->updateView();
    glUniformMatrix4fv(modelID,1,GL_FALSE,glm::value_ptr(model));
    glUniformMatrix4fv(viewID,1,GL_FALSE,glm::value_ptr(camera->getView()));
    glUniformMatrix4fv(projectionID,1,GL_FALSE,glm::value_ptr(camera->getProjection()));

    glBindVertexArray(VAO);
    updateVertexArray();
    glDrawArrays(GL_POINTS,0,(GLsizei)vertex_array.size());


    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
}

void Particles::draw(glm::vec3 ambient, glm::vec3 lightPos, glm::vec3 lightColor) {
    MovingShape::draw(ambient, lightPos, lightColor);
}

void Particles::updateVertexArray() {
    for(int i = 0; i < vertex_array.size(); i++) {
        if ((glfwGetTime() - vertex_array[i].last_changed) > CHANGE_TIME) {
            vertex_array[i].position += vertex_array[i].velocity;
            vertex_array[i].velocity -= GRAVITY;
            vertex_array[i].last_changed = glfwGetTime();
        }

        if(vertex_array[i].position.y < 0){
            vertex_array[i].position.y = 0.0f;
            vertex_array[i].velocity = -0.6f*vertex_array[i].velocity;
        }
        if(vertex_array[i].velocity.y < 0.001f && vertex_array[i].velocity.y > -0.001f && vertex_array[i].position.y < 0)
            vertex_array[i].velocity.y = 0;
    }
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferSubData(GL_ARRAY_BUFFER,0,vertex_array.size()* sizeof(Vertex),vertex_array.data());
    glBindBuffer(GL_ARRAY_BUFFER,0);
}
