#pragma once
#include "en_geometry.h"
#include "en_bitmap_font.h"

namespace GLEngine::Drawing
{
	struct BitmapText : public Geometry
	{
		vec2 pos = { 0, 0 };
		vec2 fontSize = { 4, 4 };
		BitmapFont* bitmapFont = nullptr;
		const char* text = "";

		BitmapText()
		{
		}

		BitmapText(vec2 pos, vec2 fontSize, BitmapFont* bitmapFont, const char* text)
			: pos(pos), fontSize(fontSize), bitmapFont(bitmapFont), text(text)
		{
		}

		export void GenerateVertices(VertexType vertexType) override;
		export ShaderProgram& GetShaderProgramBasedOnModifer(Modifier& modifer) override;
		export VertexType GetVertexTypeBasedOnModifer(Modifier& modifer) override;
	};
}
