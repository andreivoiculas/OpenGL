//
// Created by andreivoiculas on 19/02/19.
//

#ifndef OPENGL_SHAPE_H
#define OPENGL_SHAPE_H


#include <glm/glm.hpp>
#include "Program.h"
#include "Camera.h"

//CHANGE THIS HERE AND IN SOURCE TO ADD OR REMOVE COLOR AND NORMALS
#include "Vertex.h"

class Shape {
protected:
//    array of vetex data,typically contains
//    data about points,structured based on some rule
    std::vector<Vertex> vertex_array;
//    shader used to render the shape
    Program* program;
//    camera object used to explore the world
    Camera* camera;
//    position is world
    glm::mat4 model;
//    ambient light
    glm::vec3 ambient = glm::vec3(0.3f,0.3f,0.3f);

//    vertex array object and vertex buffer object
    unsigned int VAO,VBO;
//    vertex attribute IDs
    GLint positionID,colorID,normalID;
//    uniform IDs
    GLint modelID,viewID,projectionID;

    GLint ambientID,lightColorID,lightPosID,cameraPosID;
public:
    Shape(std::vector<Vertex> _vertex_array,Program* _program, Camera* _camera);
    Shape(std::vector<Vertex> _vertex_array,Program* _program,Camera* _camera,glm::mat4 model);
    virtual void draw();
    virtual void draw(glm::vec3 ambient,glm::vec3 lightPos,glm::vec3 lightColor);

};


#endif //OPENGL_SHAPE_H
