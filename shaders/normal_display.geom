
#version 460 core
layout (triangles) in;
layout (line_strip,max_vertices = 6) out;

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
    vec4 position;
} gs_out;

uniform mat4 view;
void main()
{
    vec3 normal = cross(gs_in[0].position.xyz - gs_in[2].position.xyz,gs_in[0].position.xyz - gs_in[1].position.xyz);
    normal = normalize(normal);
//    vec4 center = (gs_in[0].position + gs_in[1].position+ gs_in[2].position)/3.0;
    for(int i = 0; i< 3;i++)
    {
        gs_out.color = vec3(1.0,0.0,1.0);
        gs_out.texCoord = gs_in[i].texCoord;
        gs_out.position = vec4(0.0,0.0,0.0,0.0);
        gl_Position = view*gs_in[i].position;
        EmitVertex();


        gs_out.color = vec3(1.0,0.0,1.0);
        gs_out.texCoord = gs_in[0].texCoord;
        gs_out.position = vec4(0.0,0.0,0.0,0.0);
        gl_Position = view*(gs_in[i].position + vec4(normal,0.0)*0.4);
        EmitVertex();
        EndPrimitive();
    }
}
