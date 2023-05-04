#version 410 core
layout (location = 0) in vec2 position;
layout (location = 1) in vec2 texCoords;

out vec2 TexCoords1;
out vec2 TexCoords2;

uniform vec2 textureScale;
uniform vec2 textureOffset;
uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

void main()
{
    TexCoords1 = texCoords;
    TexCoords2 = texCoords + textureOffset;
    gl_Position = projection * view * model * vec4(position.xy, 1.0, 1.0);
}