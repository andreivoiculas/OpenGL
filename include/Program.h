//
// Created by andreivoiculas on 06/02/19.
//

#ifndef OPENGL_PROGRAM_H
#define OPENGL_PROGRAM_H


#include <string>
#include "Shader.h"

class Program {
private:
    unsigned int ID;
    unsigned int vert_ID;
    unsigned int geom_ID;
    unsigned int frag_ID;
public:
    Program(Shader* vertexShader,Shader* fragmentShader);
    Program(Shader* vertexShader,Shader* geometryShader ,Shader* fragmentShader);
    unsigned int getID();

};

#endif //OPENGL_PROGRAM_H
