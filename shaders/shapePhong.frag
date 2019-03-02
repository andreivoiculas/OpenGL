
#version 460 core

out vec4 color;

in vec3 aNormal;
in vec3 aColor;
in vec4 aPosition;

uniform vec3 ambient;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 cameraPos;


void main()
{
    vec3 position = aPosition.xyz;
    vec3 normal = normalize(aNormal);
    vec3 lightDir = normalize(lightPos - position);
    vec3 diffuse = max(dot(lightDir,normal),0.0)*lightColor;

    vec3 reflectDir = reflect(-lightDir,normal);
    vec3 viewDir = normalize(cameraPos- position);
    vec3 specular = 0.5*max(pow(dot(reflectDir,viewDir),20),0.0)*lightColor;
    vec3 result = (ambient+diffuse+specular)*aColor;
    color = vec4(result,1.0);
}