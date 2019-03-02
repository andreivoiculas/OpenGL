//
// Created by andreivoiculas on 19/02/19.
//
#define GLM_ENABLE_EXPERIMENTAL
#include <GL/glew.h>
#include <GL/gl.h>
#include <vector>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <include/Shape.h>

#include "include/Shape.h"

//CHANGE THIS HERE AND IN HEADER TO ADD OR REMOVE COLOR AND NORMALS
#include "include/Vertex.h"



Shape::Shape(std::vector<Vertex> _vertex_array, Program* _program,Camera* _camera) {
    vertex_array = _vertex_array;

    program = _program;
    camera = _camera;

    model = glm::mat4(1.0f);
    glUseProgram(program->getID());

    modelID = glGetUniformLocation(program->getID(),"model");
    viewID = glGetUniformLocation(program->getID(),"view");
    projectionID = glGetUniformLocation(program->getID(),"projection");
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,vertex_array.size()* sizeof(Vertex),vertex_array.data(),GL_STATIC_DRAW);


    if(vertex_array[0].mode == POSITION || vertex_array[0].mode == VELOCITY) {
        positionID = glGetAttribLocation(program->getID(), "position");
        glEnableVertexAttribArray(positionID);
        glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) 0);
    }

    if(vertex_array[0].mode == COLOR) {
        positionID = glGetAttribLocation(program->getID(), "position");
        colorID = glGetAttribLocation(program->getID(), "color");

        glEnableVertexAttribArray(positionID);
        glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) 0);

        glEnableVertexAttribArray(colorID);
        glVertexAttribPointer(colorID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) sizeof(glm::vec3));
    }

    if(vertex_array[0].mode == LIGHT) {
        positionID = glGetAttribLocation(program->getID(), "position");
        colorID = glGetAttribLocation(program->getID(), "color");
        normalID = glGetAttribLocation(program->getID(), "normal");

        ambientID = glGetUniformLocation(program->getID(), "ambient");
        lightColorID = glGetUniformLocation(program->getID(), "lightColor");
        lightPosID = glGetUniformLocation(program->getID(), "lightPos");
        cameraPosID = glGetUniformLocation(program->getID(), "cameraPos");

        glEnableVertexAttribArray(positionID);
        glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) 0);

        glEnableVertexAttribArray(colorID);
        glVertexAttribPointer(colorID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) sizeof(glm::vec3));
        glEnableVertexAttribArray(normalID);
        glVertexAttribPointer(normalID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) (sizeof(glm::vec3) * 2));
    }

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
}

Shape::Shape(std::vector<Vertex> _vertex_array, Program *_program,
             Camera *_camera, glm::mat4 _model): Shape(_vertex_array,_program,_camera){
    model = _model;
}

void Shape::draw() {
    glUseProgram(program->getID());
    camera->updateView();
    glUniformMatrix4fv(modelID,1,GL_FALSE,glm::value_ptr(model));
    glUniformMatrix4fv(viewID,1,GL_FALSE,glm::value_ptr(camera->getView()));
    glUniformMatrix4fv(projectionID,1,GL_FALSE,glm::value_ptr(camera->getProjection()));

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES,0,(GLsizei)vertex_array.size());

    glBindVertexArray(0);
}


void Shape::draw(glm::vec3 ambient, glm::vec3 lightPos, glm::vec3 lightColor) {

    glUniform3fv(ambientID,1,glm::value_ptr(ambient));
    glUseProgram(program->getID());
    camera->updateView();
    glUniformMatrix4fv(modelID,1,GL_FALSE,glm::value_ptr(model));
    glUniformMatrix4fv(viewID,1,GL_FALSE,glm::value_ptr(camera->getView()));
    glUniformMatrix4fv(projectionID,1,GL_FALSE,glm::value_ptr(camera->getProjection()));


    glUniform3fv(lightPosID,1,glm::value_ptr(lightPos));
    glUniform3fv(lightColorID,1,glm::value_ptr(lightColor));
    glUniform3fv(cameraPosID,1,glm::value_ptr(camera->getPosition()));
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES,0,(GLsizei)vertex_array.size());

    glBindVertexArray(0);

}
