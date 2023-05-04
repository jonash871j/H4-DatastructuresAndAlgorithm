#pragma once
#include "en_def.h"

namespace GLEngine
{
	struct VoxelModelPixel
	{
		vec3 pos;
		vec3 color;
		uint8_t colorId;
	};

	struct VoxelModelData
	{
		vector<VoxelModelPixel> pixels;
		vector<float> redColorPalette;
		vector<float> greenColorPalette;
		vector<float> blueColorPalette;
		vec3 center;
		vec3 size;
	};
}
