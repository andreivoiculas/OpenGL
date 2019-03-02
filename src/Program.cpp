//
// Created by andreivoiculas on 06/02/19.
//

#include <GL/glew.h>
#include "include/Program.h"

Program::Program(Shader* vertexShader, Shader* fragmentShader) {
    ID = glCreateProgram();
    frag_ID = fragmentShader->getID();
    vert_ID = vertexShader->getID();
    glAttachShader(ID,vert_ID);
    glAttachShader(ID,frag_ID);
    glLinkProgram(ID);
    glValidateProgram(ID);
}

Program::Program(Shader* vertexShader,Shader* geometryShader ,Shader* fragmentShader) {
    ID = glCreateProgram();
    frag_ID = fragmentShader->getID();
    geom_ID = geometryShader->getID();
    vert_ID = vertexShader->getID();
    glAttachShader(ID,vert_ID);
    glAttachShader(ID,geom_ID);
    glAttachShader(ID,frag_ID);
    glLinkProgram(ID);
    glValidateProgram(ID);
}

unsigned int Program::getID() {
    return ID;
}