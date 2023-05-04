#pragma once
#include "en_def.h"
#include "en_geometry.h"

namespace GLEngine
{
	enum class export PolygonMode
	{
		Point = 0x1B00,
		Line = 1, 
		Triangle = 0x1B01,
		Fill = 0x1B02,
	};

	class Modifier
	{
	private:
		vec3 _offset;
		vec3 _rotation;
		vec3 _scale;
		vec3 _color;
		vec3 _textCursorPos;
		float _fontSize;
		float _alpha;
		float _lineWidth;
		float _pointSize;
		PolygonMode _polygonMode;
		Texture* _texture = nullptr;
		vec2 _textureScale;
		vec2 _textureOffset;
		Font* _font = nullptr;
		bool _isLightMode = false;

	public:
		export Modifier();

	public:
		export Modifier& SetDefault();
		export Modifier& SetOffset(vec2 offset);
		export Modifier& SetOffset(vec3 offset);
		export Modifier& SetRotation(float angle);
		export Modifier& SetRotation(vec3 rotation);
		export Modifier& SetScale(vec2 scale);
		export Modifier& SetScale(vec3 scale);
		export Modifier& SetColor(vec3 color);
		export Modifier& SetColor(uint8_t r, uint8_t g, uint8_t b);
		export Modifier& SetColor(uint8_t w);
		export Modifier& SetTextCursorPos(vec2 textCursorPos);
		export Modifier& SetTextCursorPos(vec3 textCursorPos);
		export Modifier& SetFontSize(float fontSize);
		export Modifier& SetAlpha(float alpha);
		export Modifier& SetLineWidth(float lineWidth);
		export Modifier& SetPointSize(float pointSize);
		export Modifier& SetPolygonMode(PolygonMode polygonMode);
		export Modifier& SetFont(Font* font);
		export Modifier& SetFont(int fontKey);
		export Modifier& SetTexture(Texture* texture);
		export Modifier& SetTexture(int textureKey);
		export Modifier& SetTextureScale(vec2 textureScale);
		export Modifier& SetTextureOffset(vec2 textureOffset);
		export Modifier& SetLightMode(bool isLightMode);
		export vec3 GetOffset();
		export vec3 GetRotation();
		export vec3 GetScale();
		export vec3 GetColor();
		export vec3 GetTextCursorPos();
		export float GetFontSize();
		export float GetAlpha();
		export PolygonMode GetPolygonMode();
		export float GetLineWidth();
		export float GetPointSize();
		export Font* GetFont();
		export Texture* GetTexture();
		export vec2 GetTextureScale();
		export vec2 GetTextureOffset();
		export bool GetLightMode();

	public:
		template<typename Enum>
		Modifier& SetFont(Enum fontKey)
		{
			return SetFont((int)fontKey);
		}
		template<typename Enum>
		Modifier& SetTexture(Enum textureKey)
		{
			return SetTexture((int)textureKey);
		}
	};
}