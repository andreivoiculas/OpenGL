//
// Created by andreivoiculas on 28/01/19.
//

#include "include/Shader.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <iostream>
#include <fstream>
#include <sstream>

std::string Shader::ParseShader(const std::string& filepath)
{
    std::ifstream stream(filepath);
    std::string line;
    std::stringstream content;

    if(stream)
        content << stream.rdbuf();
    else
        std::cout << "Failed to load shader " + filepath << std::endl;
    return content.str();

}

unsigned int Shader::CompileShader(unsigned int type,const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id,1,&src, nullptr);
    glCompileShader(id);
    int result;
    glGetShaderiv(id,GL_COMPILE_STATUS,&result);
    if(result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id,GL_INFO_LOG_LENGTH,&length);
        char* message = (char*) alloca(length*sizeof(char));
        glGetShaderInfoLog(id,length,&length,message);
        std::string failed_shader;
        if(type == GL_VERTEX_SHADER)
            failed_shader = "vertex";
        else if (type == GL_GEOMETRY_SHADER)
            failed_shader = "geometry";
        else
            failed_shader = "fragment";

        std::cout<< "Failed to compile " << failed_shader <<
                 " shader"<< std::endl;
        std::cout<< message <<std::endl;

        glDeleteShader(id);
        return 0;
    }

    return id;
}


Shader::Shader(unsigned int type,const std::string &filepath) {
    std::string source = ParseShader(filepath);
    ID = CompileShader(type,source);
}

unsigned int Shader::getID()
{
    return ID;
}
