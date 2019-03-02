#version 460
layout(points) in;
layout(triangle_strip,max_vertices = 4) out;

uniform mat4 view;
uniform mat4 projection;

void main() {
    vec4 center = gl_in[0].gl_Position;
    gl_Position = projection*view*(center + vec4(-0.05,-0.05,0.0,0.0));
    EmitVertex();
    gl_Position = projection*view*(center + vec4(0.05,-0.05,0.0,0.0));
    EmitVertex();
    gl_Position = projection*view*(center + vec4(-0.05,0.05,0.0,0.0));
    EmitVertex();
    gl_Position = projection*view*(center + vec4(0.05,0.05,0.0,0.0));
    EmitVertex();
    EndPrimitive();
}
