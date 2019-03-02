//
// Created by andreivoiculas on 24/02/19.
//

#ifndef OPENGL_MOVINGSHAPE_H
#define OPENGL_MOVINGSHAPE_H


#include <vector>
#include "Shape.h"

class MovingShape : public Shape {
public:
    MovingShape(std::vector<Vertex> _vertex_array, Program *_program, Camera *_camera);
    MovingShape(std::vector<Vertex> _vertex_array, Program *_program, Camera *_camera, glm::mat4 model);
    void draw() override;
    void draw(glm::vec3 ambient,glm::vec3 lightPos,glm::vec3 lightColor) override;
    virtual void updateVertexArray();


};


#endif //OPENGL_MOVINGSHAPE_H
