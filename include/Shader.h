//
// Created by andreivoiculas on 28/01/19.
//

#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H
#include <iostream>


class Shader {
private:
    std::string ParseShader(const std::string& filepath);
    unsigned int CompileShader(unsigned int type,const std::string& source);
    unsigned int ID;

public:
    Shader(unsigned int type,const std::string& filepath);
    ~Shader() = default;
    unsigned int  getID();
};


#endif //OPENGL_SHADER_H
