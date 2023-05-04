#pragma once
#include "en_def.h"
#include "en_voxel_model_data.h"

namespace GLEngine::FileHandling
{
	class VoxFileFormat
	{
	public:
		export static void Load(VoxelModelData& voxelModelData, string path);
		export static VoxelModelData* Load(string path);
	};
}
