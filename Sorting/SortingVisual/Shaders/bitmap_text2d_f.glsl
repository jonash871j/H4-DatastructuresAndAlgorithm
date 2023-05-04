#version 410 core
out vec4 color;
in vec2 TexCoords1;
in vec2 TexCoords2;

uniform vec3 globalColor;
uniform float alpha;
uniform sampler2D bitmapTexture;
uniform sampler2D overlayTexture;
uniform bool isTextured;

void main()
{    
    color = vec4(globalColor, alpha) * texture(bitmapTexture, TexCoords1);
}  