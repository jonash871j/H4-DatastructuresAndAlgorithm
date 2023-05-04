#version 410 core
flat in uint vColorId;
out vec4 fColor;

uniform vec3 globalColor;
uniform float alpha;
uniform float[255] uRedColors;
uniform float[255] uGreenColors;
uniform float[255] uBlueColors;

void main()
{    
    fColor = vec4(globalColor * vec3(uRedColors[vColorId], uGreenColors[vColorId], uBlueColors[vColorId]), alpha);
}  