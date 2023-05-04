#pragma once
#include "en_def.h"
#include "en_math.h"

namespace GLEngine::Drawables
{
	struct Vertex
	{
		float xPos;
		float yPos;
		float xTexPos;
		float yTexPos;

		Vertex(float xPos, float yPos, float xTexPos = 0, float yTexPos = 0)
			: xPos(xPos), yPos(yPos), xTexPos(xTexPos), yTexPos(yTexPos)
		{
		}
	};

	class DrawableElement abstract
	{
	protected:
		size_t _size = 0;
		Vertex* _verticies = nullptr;
		unsigned _VAO = -1;
		unsigned _VBO = -1;

	public:
		export ~DrawableElement();

	public:
		virtual void GenerateVerticies() = 0;
		virtual int GetMode() = 0;
		export void Bind();
		export size_t GetSize();
		export Vertex* GetVerticies();
		export unsigned GetVAO();
		export unsigned GetVBO();
	};
}

