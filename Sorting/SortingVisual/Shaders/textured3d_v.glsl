#version 410 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoords;

out vec2 TexCoords;

uniform vec2 textureScale;
uniform vec2 textureOffset;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    TexCoords = texCoords * textureScale + textureOffset;
    gl_Position = projection * view * model * vec4(position.xyz, 1.0);
}