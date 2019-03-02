//
// Created by andreivoiculas on 24/02/19.
//
#include <GL/glew.h>
#include <GL/gl.h>
#include <vector>
#include <glm/gtc/type_ptr.hpp>
#include <include/MovingShape.h>


MovingShape::MovingShape(std::vector<Vertex> _vertex_array, Program *_program, Camera *_camera) : Shape(_vertex_array, _program, _camera){


}

MovingShape::MovingShape(std::vector<Vertex> _vertex_array, Program *_program, Camera *_camera, glm::mat4 model)
        : Shape(_vertex_array, _program, _camera,
                model) {

}

void MovingShape::draw() {
    glUseProgram(program->getID());
    camera->updateView();
    glUniformMatrix4fv(modelID,1,GL_FALSE,glm::value_ptr(model));
    glUniformMatrix4fv(viewID,1,GL_FALSE,glm::value_ptr(camera->getView()));
    glUniformMatrix4fv(projectionID,1,GL_FALSE,glm::value_ptr(camera->getProjection()));

    glBindVertexArray(VAO);
    updateVertexArray();
    glDrawArrays(GL_TRIANGLES,0,(GLsizei)vertex_array.size());

    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
}

void MovingShape::updateVertexArray() {
    for(int i = 0; i < vertex_array.size(); i++)
        vertex_array[i].position.x += 0.0001f;
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferSubData(GL_ARRAY_BUFFER,0,vertex_array.size()* sizeof(Vertex),vertex_array.data());
    glBindBuffer(GL_ARRAY_BUFFER,0);
}


void MovingShape::draw(glm::vec3 ambient, glm::vec3 lightPos, glm::vec3 lightColor) {

    glUniform3fv(ambientID,1,glm::value_ptr(ambient));
    glUseProgram(program->getID());
    camera->updateView();
    glUniformMatrix4fv(modelID,1,GL_FALSE,glm::value_ptr(model));
    glUniformMatrix4fv(viewID,1,GL_FALSE,glm::value_ptr(camera->getView()));
    glUniformMatrix4fv(projectionID,1,GL_FALSE,glm::value_ptr(camera->getProjection()));


    glUniform3fv(lightPosID,1,glm::value_ptr(lightPos));
    glUniform3fv(lightColorID,1,glm::value_ptr(lightColor));
    glUniform3fv(cameraPosID,1,glm::value_ptr(camera->getPosition()));
    MovingShape::updateVertexArray();
    glDrawArrays(GL_TRIANGLES,0,(GLsizei)vertex_array.size());

    glBindVertexArray(0);

    glBindVertexArray(VAO);
}