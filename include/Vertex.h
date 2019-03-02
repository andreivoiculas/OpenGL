//
// Created by andreivoiculas on 24/02/19.
//

#ifndef OPENGL_VERTEX_H
#define OPENGL_VERTEX_H

#include <glm/glm.hpp>

enum Mode {POSITION,COLOR,LIGHT,VELOCITY};

struct Vertex{
    glm::vec3 position;
    glm::vec3 color;
    glm::vec3 normal;
    glm::vec3 velocity;
    Mode mode;
    double last_changed;
    Vertex(glm::vec3 _position,glm::vec3 _velocity, double creation_time,Mode mode) :
            position(_position),velocity(_velocity),last_changed(creation_time),mode(VELOCITY) {};

    Vertex(glm::vec3 _position,glm::vec3 _color,glm::vec3 _normal,Mode mode)
            : position(_position),color(_color),normal(_normal),mode(LIGHT){};

    Vertex(glm::vec3 _position,glm::vec3 _color,Mode mode) : position(_position),color(_color),mode(COLOR){};

    Vertex(glm::vec3 _position,Mode mode) : position(_position),mode(POSITION){};
};

#endif //OPENGL_VERTEX_H
