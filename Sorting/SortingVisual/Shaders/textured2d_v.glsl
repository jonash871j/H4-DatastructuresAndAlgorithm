#version 410 core
layout (location = 0) in vec2 position;
layout (location = 1) in vec2 texCoords;

out vec2 TexCoords;

uniform vec2 textureScale;
uniform vec2 textureOffset;
uniform mat4 model;
uniform mat4 projection;

void main()
{
    TexCoords = texCoords * textureScale + textureOffset;
    gl_Position = projection * model * vec4(position.xy, 0.0, 1.0);
}