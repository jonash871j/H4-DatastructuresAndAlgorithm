#pragma once
#include "en_geometry.h"

namespace GLEngine::Drawing
{
	struct Cube3D : public Geometry
	{
		vec3 a = { 0, 0, 0 };
		vec3 b = { 0, 0, 1 };
		vec3 c = { 1, 0, 1 };
		vec3 d = { 1, 0, 0 };

		vec3 e = { 0, 1, 0 };
		vec3 f = { 0, 1, 1 };
		vec3 g = { 1, 1, 1 };
		vec3 h = { 1, 1, 0 };

		Cube3D()
		{
			is3D = true;
		}

		Cube3D(vec3 pos, vec3 size)
		{
			is3D = true;
			a = pos;
			b = pos + vec3{ 0, 0, size.z };
			c = pos + vec3{ size.x, 0, size.z };
			d = pos + vec3{ size.x, 0, 0 };

			e = pos + vec3{ 0, size.y, 0 };
			f = pos + vec3{ 0, size.y, size.z };
			g = pos + vec3{ size.x, size.y, size.z };
			h = pos + vec3{ size.x, size.y, 0 };
		}

		Cube3D(vec3 a, vec3 b, vec3 c, vec3 d, vec3 e, vec3 f, vec3 g, vec3 h)
			: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h)
		{
			is3D = true;
		}

		export void GenerateVertices(VertexType vertexType) override;
	};
}