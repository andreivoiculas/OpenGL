
#version 460 core
layout(location = 0) in vec4 position;
layout(location = 1) in vec3 color;
layout(location = 2) in vec2 texCoord;

out VertexData
{
    vec3 color;
    vec2 texCoord;
    vec4 position;
} vs_out;

uniform mat4 view;
void main()
{
    vs_out.color = color;
    vs_out.position = vec4(20.0*position.xyz,1.0);
//    gl_Position = view*position;
    vs_out.texCoord = texCoord;
}
