
#version 460 core
out vec4 color;

in VertexData
{
    vec3 color;
    vec2 texCoord;
    vec4 position;
} fs_in;


uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

void main()
{
    color = vec4(fs_in.color,1.0);
}