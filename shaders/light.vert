
#version 460 core
layout(location = 0) in vec4 position;
layout(location = 1) in vec3 color;
layout(location = 2) in vec2 texCoord;

uniform mat4 transformation;
uniform mat4 view;

out VertexData
{
    vec3 color;
    vec2 texCoord;
    vec4 position;
} vs_out;
void main()
{
    vs_out.color = vec3(1.0,1.0,1.0);
    vs_out.position = transformation*position;
    gl_Position = view*transformation*position;
    vs_out.texCoord = texCoord;

}
