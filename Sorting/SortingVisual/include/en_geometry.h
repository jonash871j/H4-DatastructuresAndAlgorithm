#pragma once
#include "en_def.h"
#include "en_math.h"
#include "en_vertices_data.h"

namespace GLEngine::Drawing
{
	struct Geometry abstract
	{
		unsigned VBO = -1;
		unsigned VAO = -1;
		bool isLineMode = false;
		bool is3D = false;
		bool isVerticesDataCreated = false;
		VerticesData verticesData;

		export ~Geometry();

		export void UpdateVerticesData(VertexType vertexType, int vertexReserve);
		export void UpdateCustomVertices(int vertexReserve, int vertexSize, vector<int> vertexDefinition);
		export virtual void GenerateVertices(VertexType vertexType) = 0;
		export virtual ShaderProgram& GetShaderProgramBasedOnModifer(Modifier& modifer);
		export virtual VertexType GetVertexTypeBasedOnModifer(Modifier& modifer);
		export virtual vec3 GetCenter();
	};
}