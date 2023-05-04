#pragma once
#include "en_geometry.h"
#include "en_voxel_model_data.h"
#include "en_vox_file_format.h"

namespace GLEngine::Drawing
{
	struct VoxelModel : public Geometry
	{
		VoxelModelData& voxelModelData;

		VoxelModel(VoxelModelData& voxelModelData)
			: voxelModelData(voxelModelData)
		{
			is3D = true;
		}

		export void GenerateVertices(VertexType vertexType) override;
		export VertexType GetVertexTypeBasedOnModifer(Modifier& modifer) override;
		export ShaderProgram& GetShaderProgramBasedOnModifer(Modifier& modifer);
		export vec3 GetCenter();
	};
}
