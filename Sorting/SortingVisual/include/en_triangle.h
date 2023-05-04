#pragma once
#include "en_geometry.h"

namespace GLEngine::Drawing
{
	struct Triangle : public Geometry
	{
		vec3 a = { 0, 0, 0 };
		vec3 b = { 0, 32, 0 };
		vec3 c = { 32, 32, 0 };

		Triangle()
		{
		}

		Triangle(vec2 a, vec2 b, vec2 c)
			: a(a.x, a.y, 0.0f), b(b.x, b.y, 0.0f), c(c.x, c.y, 0.0f)
		{
		}

		Triangle(vec3 a, vec3 b, vec3 c)
			: a(a), b(b), c(c)
		{
		}

		export void GenerateVertices(VertexType vertexType) override;
	};
}