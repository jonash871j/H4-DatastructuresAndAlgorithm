#pragma once
#include "en_def.h"
#include "en_texture.h"
#include "en_font.h"

namespace GLEngine
{
	class BitmapFont : public Font
	{
	private:
		Texture* _textures[255]{ nullptr };
		Texture* _texture = nullptr;
		string _characterOrder  = "";
		const char* _path = nullptr;
		int _characterWidth = 0;
		int _characterHeight = 0;
		int _xCharacterAmount = 0;
		int _yCharacterAmount = 0;
		int _asciiOffset = 0;

	private:
		export BitmapFont(int characterWidth, int characterHeight, int xCharacterAmount, int yCharacterAmount);

	public:
		export static BitmapFont* Create(int characterWidth, int characterHeight, int xCharacterAmount, int yCharacterAmount);

	public:
		export BitmapFont* LoadAsAsciiFormat(const char* path, int asciiOffset = 0);
		export BitmapFont* LoadAsCustomFormat(const char* path, const char* characterOrder);
		export Texture** GetCharacterTextures();
		export Texture* GetCharacterTexture();
		export vec2 GetCharacterSize();
		export ivec2 GetCharacterAmount();
		export int GetAsciiOffset();
		export int GetCharacterWidth();
		export int GetCharacterHeight();

	private:
		void Load();
		void PutCharacterIntoBuffer(int cx, int cy, ImageData& imageData, ImageData& characterData);
	};
}


