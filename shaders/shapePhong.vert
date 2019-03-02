
#version 460 core

in vec3  position;
in vec3  color;
in vec3  normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 aNormal;
out vec3 aColor;
out vec4 aPosition;

void main()
{
    gl_Position = projection*view*model*vec4(position,1.0);
    aNormal = normal;
    aColor = color;
    aPosition = model*vec4(position,1.0);
}
