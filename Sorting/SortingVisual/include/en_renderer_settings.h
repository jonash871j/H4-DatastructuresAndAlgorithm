#pragma once
#include "en_def.h"

namespace GLEngine
{
	class RendererSettings
	{
	public:
		enum class CullFace
		{
			None,
			Front = 0x0404,
			Back = 0x0405,
			FrontAndBack = 0x0408,
		};

	public:
		export void SetDefault();
		export void SetCullFace(CullFace cullFace);
	};
}