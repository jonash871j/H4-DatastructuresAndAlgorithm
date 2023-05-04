#pragma once
#include "en_def.h"
#include "en_bitmap_font.h"

namespace GLEngine
{
	enum class DefaultShaderProgramKey
	{
		Basic2D = -1,
		Basic3D = -2,
		Textured2D = -3,
		Textured3D = -4,
		Light3D = -5,
		TexturedLight3D = -6,
		BitmapText2D = -7,
		BitmapText3D = -8,
		VoxelModel3D = -9,
		FrameBuffer = -10,
	};

	class ResourceManager
	{
	public:
		template<typename Enum>
		static void LoadTexture(Enum key, const char* path)
		{
			LoadTexture((int)key, path);
		}
		export static void LoadTexture(int key, const char* path);

	/*	template<typename Enum>
		static Texture& GetTexture(Enum key)
		{
			return GetTexture((int)key);
		}*/
		export static Texture* GetTexture(int key);

		template<typename Enum>
		static void LoadBitmapFont(Enum key, BitmapFont* bitmapFont)
		{
			LoadBitmapFont((int)key, bitmapFont);
		}
		export static void LoadBitmapFont(int key, BitmapFont* bitmapFont);

		//template<typename Enum>
		//static Font& GetFont(Enum key)
		//{
		//	return GetFont((int)key);
		//}
		export static Font* GetFont(int key);

		template<typename Enum1, typename Enum2>
		static void LoadSound(Enum1 soundKey, Enum2 channelKey, const char* path)
		{
			LoadSound((int)soundKey, (int)channelKey, path);
		}
		export static void LoadSound(int soundKey, int channelKey, const char* path);

		template<typename Enum>
		static void LoadVoxelModel(Enum key, GLEngine::Drawing::VoxelModel* voxelModel)
		{
			LoadBitmapFont((int)key, voxelModel);
		}
		export static void LoadVoxelModel(int key, GLEngine::Drawing::VoxelModel* voxelModel);

		template<typename Enum>
		static Sound& GetSound(Enum soundKey)
		{
			return GetSound((int)soundKey);
		}
		export static Sound& GetSound(int soundKey);

		template<typename Enum>
		static GLEngine::Drawing::VoxelModel& GetVoxelModel(Enum voxelModelKey)
		{
			return GetVoxelModel((int)voxelModelKey);
		}
		export static GLEngine::Drawing::VoxelModel& GetVoxelModel(int voxelModelKey);

		template<typename Enum>
		static void LoadShaderProgram(Enum key, ShaderProgram* shaderProgram)
		{
			LoadShaderProgram((int)key, shaderProgram);
		}
		export static void LoadShaderProgram(int shaderProgramKey, ShaderProgram* shaderProgram);

		template<typename Enum>
		static ShaderProgram& GetShaderProgram(Enum key)
		{
			return GetShaderProgram((int)key);
		}
		export static ShaderProgram& GetShaderProgram(int shaderProgramKey);
	};
}