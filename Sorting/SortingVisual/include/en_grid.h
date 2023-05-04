#pragma once
#include "en_geometry.h"

namespace GLEngine::Drawing
{
	struct Grid : public Geometry
	{
		vec2 size = { 32, 32 };
		vec2 startPos = { 0, 0 };
		vec2 endPos = { 128, 128 };

		Grid()
		{
			isLineMode = true;
		}

		Grid(vec2 size, vec2 startPos, vec2 endPos)
			: size(size), startPos(startPos), endPos(endPos)
		{
			isLineMode = true;
		}

		export void GenerateVertices(VertexType vertexType) override;
	};
}
