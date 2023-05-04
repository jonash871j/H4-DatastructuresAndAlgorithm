#include "en_pch.h"

#ifndef EN_DEF

#define export __declspec(dllexport)

#include "en_logger.h"
#include "en_core.h"


#define ASSERT(x) if ((!x))	__debugbreak();


#define GL_CALL(x)										 \
		Core::GLLogClearError();						 \
		x ; 											 \
		ASSERT(Core::GLLogCall(#x, __FILE__, __LINE__))	 \


#ifndef NDEBUG
#define D_CALL(x) x;
#define DGL_CALL(x) GL_CALL(x)
#else
	#define D_CALL(x) 
	#define DGL_CALL(x)
#endif

using std::string;
using std::vector;
using std::map;

using glm::vec2;
using glm::ivec2;
using glm::vec3;
using glm::ivec3;
using glm::vec4;
using glm::ivec4;
using glm::mat4;

#endif 

namespace GLEngine
{
	class Window;
	class GlfwWindow;
	class Win32Window;
	class GlfwInput;
	class Win32Input;
	class Renderer;
	class Modifier;
	class FrameBuffer;
	class SoundSystem;
	class Mixer;
	class Channel;
	class Sound;
	class Texture;
	class Shader;
	class ShaderProgram;
	class Font;
	class BitmapFont;
	class Time;
};

namespace GLEngine::Drawing
{
	struct VoxelModel;
	struct Geometry;
};

#define EN_DEF