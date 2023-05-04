#version 410 core
out vec4 color;
in vec2 TexCoords;

uniform vec3 globalColor;
uniform float alpha;
uniform sampler2D image;

void main()
{    
    color = vec4(globalColor, alpha) * texture(image, TexCoords);
}  