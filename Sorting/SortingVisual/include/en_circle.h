#pragma once
#include "en_geometry.h"

namespace GLEngine::Drawing
{
	struct Circle : public Geometry
	{
		vec3 pos = { 0, 0, 0 };
		vec3 radius = { 16, 16, 0 };
		int edges = 32;

		Circle()
		{
		}
		Circle(vec2 pos, vec2 radius, int edges)
			: pos({pos.x, pos.y, 0}), radius(radius.x, radius.y, 0), edges(edges)
		{
		}
		Circle(vec3 pos, vec3 radius, int edges)
			: pos(pos), radius(radius), edges(edges)
		{
		}

		export void GenerateVertices(VertexType vertexType) override;
	};
}
