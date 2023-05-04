#version 410 core
layout (location = 0) in uint aVoxel;

flat out uint vColorId;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    uint x = aVoxel & 0x000000FF;
    uint y = (aVoxel & 0x0000ff00) >> 8;
    uint z = (aVoxel & 0x00ff0000) >> 16;
    uint colorId = (aVoxel & 0xff000000) >> 24;

    gl_Position = projection * view * model * vec4(x, y, z, 1.0);
    vColorId = colorId;
}
