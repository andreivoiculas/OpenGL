//
// Created by andreivoiculas on 24/02/19.
//

#ifndef OPENGL_VERTEX_H
#define OPENGL_VERTEX_H

#include <glm/glm.hpp>

struct Vertex{
    glm::vec3 position;
    glm::vec3 velocity;
    double last_changed;
    Vertex(glm::vec3 _position,glm::vec3 _velocity, double creation_time) :
           position(_position),velocity(_velocity),last_changed(creation_time) {};
};

#endif //OPENGL_VERTEX_H
