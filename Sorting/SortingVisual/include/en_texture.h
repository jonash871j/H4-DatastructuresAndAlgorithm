#pragma once
#include "en_def.h"
#include "en_file_reader.h"

namespace GLEngine
{
    class Texture
    {
    private:
        const char* path = nullptr;
        unsigned _id = -1;
        int _width = 0;
        int _height = 0;
        vec2 _size = { 0, 0 };

    public:
        export Texture() { };
        export Texture(const char* path);

    public:
        export void Load(const char* path);
        export void Load(uint8_t* buffer, size_t size);
        export vec2 GetSize();

    public:
        export void Bind(int textureUnit = 0);
        void Generate(ImageData& imageData);
    };
}
