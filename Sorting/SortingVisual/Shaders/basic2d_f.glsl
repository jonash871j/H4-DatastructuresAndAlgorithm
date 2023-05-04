#version 410 core
out vec4 color;

uniform vec3 globalColor;
uniform float alpha;

void main()
{    
    color = vec4(globalColor, alpha);
}  