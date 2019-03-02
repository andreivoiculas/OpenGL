//
// Created by andreivoiculas on 24/02/19.
//

#ifndef OPENGL_VERTEXCOLOR_H
#define OPENGL_VERTEXCOLOR_H

#include <glm/glm.hpp>

struct Vertex{
    glm::vec3 position;
    glm::vec3 color;
    Vertex(glm::vec3 _position,glm::vec3 _color) : position(_position),color(_color){};
};

#endif //OPENGL_VERTEX_H
