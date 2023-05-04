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
    if (texture(bitmapTexture, TexCoords1).xy == 0)
    {
         color = vec4(0);
    }
    else if (!isTextured)
    {
        color = vec4(globalColor, alpha) * texture(bitmapTexture, TexCoords1);
    }
    else
    {
        color = vec4(globalColor, alpha) * mix(texture(bitmapTexture, TexCoords1), texture(overlayTexture, TexCoords2), 1.0);
    }
}  