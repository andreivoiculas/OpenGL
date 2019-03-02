//
// Created by andreivoiculas on 28/02/19.
//

#ifndef OPENGL_PARTICLES_H
#define OPENGL_PARTICLES_H


#include "MovingShape.h"

class Particles : public MovingShape {
public:
    Particles(std::vector<Vertex> _vertex_array, Program *_program, Camera *_camera);
    Particles(std::vector<Vertex> _vertex_array, Program *_program, Camera *_camera, glm::mat4 model);
    void draw() override;
    void draw(glm::vec3 ambient,glm::vec3 lightPos,glm::vec3 lightColor) override;
    void updateVertexArray() override;
};


#endif //OPENGL_PARTICLES_H
