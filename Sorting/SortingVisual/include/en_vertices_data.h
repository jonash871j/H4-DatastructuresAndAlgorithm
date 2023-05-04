#pragma once
#include "en_def.h"
#include "en_math.h"

namespace GLEngine::Drawing
{
	enum class VertexType : unsigned char
	{
		None,
		BasicVertex,
		TexturedVertex,
		LightVertex,
		TexturedLightVertex,
		Custom,
	};

	struct VerticesData
	{
		uint8_t* values = nullptr;
		int valueAmount;
		int valuesIndex = 0;
		std::vector<int> vertexDefinition;
		int vertexAmount = 0;
		int vertexSize = 0;
		bool is3D = false;
		VertexType vertexType = VertexType::None;

		void Add(vec3 position, vec2 textureCoord = { 1, 1 }, vec3 normal = { 1, 1, 1 })
		{
			AddFloat(position.x);
			AddFloat(position.y);
			if (is3D)
			{
				AddFloat(position.z);
			}
			if (vertexType == VertexType::TexturedVertex || vertexType == VertexType::TexturedLightVertex)
			{
				AddFloat(textureCoord.x);
				AddFloat(textureCoord.y);
			}
			if (vertexType == VertexType::LightVertex || vertexType == VertexType::TexturedLightVertex)
			{
				AddFloat(normal.x);
				AddFloat(normal.y);
				if (is3D)
				{
					AddFloat(normal.z);
				}
			}
		}

		void AddVec3(vec3 vec)
		{
			AddFloat(vec.x);
			AddFloat(vec.y);
			AddFloat(vec.z);
		}

		void AddFloat(float value)
		{
			if (valuesIndex + 4 > valueAmount)
			{
				Logger::PrintlnError("Geometry heap error, incorrect reserve value");
				Core::Terminate();
			}

			*(float*)&values[valuesIndex] = value;
			valuesIndex += 4;
		}

		void Add4Bytes(uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4)
		{
			if (valuesIndex + 4 > valueAmount)
			{
				Logger::PrintlnError("Geometry heap error, incorrect reserve value");
				Core::Terminate();
			}

			values[valuesIndex++] = b1;
			values[valuesIndex++] = b2;
			values[valuesIndex++] = b3;
			values[valuesIndex++] = b4;
		}
	};
}
