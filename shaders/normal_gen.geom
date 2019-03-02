
#version 460 core
layout (triangles) in;
layout (triangle_strip,max_vertices = 3) out;

in VertexData
{
    vec3 color;
    vec2 texCoord;
    vec4 position;
} gs_in[];

out VertexData
{
    vec3 color;
    vec2 texCoord;
    vec3 normal;
    vec4 position;
} gs_out;

uniform mat4 view;
void main()
{
    vec3 normal = cross(gs_in[0].position.xyz - gs_in[2].position.xyz,gs_in[0].position.xyz - gs_in[1].position.xyz);
    normal = normalize(normal);
    for(int i = 0; i< 3;i++)
    {
        gs_out.color = gs_in[i].color;
        gs_out.texCoord = gs_in[i].texCoord;
        gs_out.position = gs_in[i].position;
        gs_out.normal = normal;
        gl_Position = view*gs_in[i].position;
        EmitVertex();
    }
    EndPrimitive();
}
