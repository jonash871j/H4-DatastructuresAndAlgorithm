#pragma once
#include "en_def.h"
#include "en_geometry.h"
#include "en_modifer.h"

namespace GLEngine
{
	class GeometryBinder
	{
	public:
		export static void Bind(GLEngine::Drawing::Geometry& geometry, GLEngine::Drawing::VertexType vertexType);
	};
}

