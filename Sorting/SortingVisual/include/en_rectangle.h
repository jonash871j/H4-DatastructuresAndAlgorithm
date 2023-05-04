#pragma once
#include "en_geometry.h"

namespace GLEngine::Drawing
{
	struct Rectangle : public Geometry
	{
		vec3 a = { 0, 0, 0 };
		vec3 b = { 0, 16, 0 };
		vec3 c = { 16, 16, 0 };
		vec3 d = { 16, 0, 0 };

		Rectangle()
		{
		}

		Rectangle(vec2 a, vec2 b, vec2 c, vec2 d)
			: a(a.x, a.y, 0.0f), b(b.x, b.y, 0.0f), c(c.x, c.y, 0.0f), d(d.x, d.y, 0.0f)
		{
		}

		Rectangle(vec3 a, vec3 b, vec3 c, vec3 d)
			: a(a), b(b), c(c), d(d)
		{
			is3D = true;
		}

		Rectangle(vec3 pos, vec2 size, AxisPlane axisPlane) : Rectangle(
			Math::ByAxisPlane({ pos.x, pos.y, pos.z }, axisPlane), 
			Math::ByAxisPlane({ pos.x, pos.y + size.y, pos.z }, axisPlane),
			Math::ByAxisPlane({ pos.x + size.x, pos.y + size.y, pos.z }, axisPlane),
			Math::ByAxisPlane({ pos.x + size.x, pos.y, pos.z }, axisPlane))
		{
		}

		export void GenerateVertices(VertexType vertexType) override;

		virtual vec3 GetCenter() override
		{
			return a + ((c - a) / 2.0f);
		}
	};
}
