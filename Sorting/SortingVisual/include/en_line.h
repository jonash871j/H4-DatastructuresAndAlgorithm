#pragma once
#include "en_geometry.h"
	
namespace GLEngine::Drawing
{
	struct Line : public Geometry
	{
		vec3 a = { 0, 0, 0 };
		vec3 b = { 16, 16, 0 };

		Line()
		{
		}

		Line(vec2 a, vec2 b)
			: a(a.x, a.y, 0), b(b.x, b.y, 0)
		{
		}

		Line(vec3 a, vec3 b)
			: a(a), b(b)
		{
		}

		export void GenerateVertices(VertexType vertexType) override;
	};
}
