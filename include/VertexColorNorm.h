//
// Created by andreivoiculas on 24/02/19.
//

#ifndef OPENGL_VERTEXCOLORNORM_H
#define OPENGL_VERTEXCOLORNORM_H

#include <glm/glm.hpp>

struct Vertex{
    glm::vec3 position;
    glm::vec3 color;
    glm::vec3 normal;
    Vertex(glm::vec3 _position,glm::vec3 _color,glm::vec3 _normal)
            : position(_position),color(_color),normal(_normal){};
};

#endif //OPENGL_VERTEX_H
