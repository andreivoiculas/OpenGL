
#version 460 core
out vec4 color;

in VertexData
{
    vec3 color;
    vec2 texCoord;
    vec3 normal;
    vec4 position;
} fs_in;

uniform float ambient;
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 cameraPos;

void main()
{
    vec3 lightDir = normalize(lightPos - fs_in.position.xyz);
    float diff = max(dot(fs_in.normal, lightDir), 0.0);
    vec3 diffuse = 0.8*diff * lightColor;

//    vec3 normal = normalize(fs_in.normal);
    float specStrenght = 1.8;
    vec3 viewDir = normalize(cameraPos - fs_in.position.xyz);
    vec3 reflectDir = reflect(-lightDir,fs_in.normal);
    float spec = pow(max(dot(viewDir, reflectDir),0.0),50);
    vec3 specular = spec*specStrenght*lightColor;

    vec3 result = (ambient+diffuse+specular)*fs_in.color;
    color = vec4(result,1.0);

}