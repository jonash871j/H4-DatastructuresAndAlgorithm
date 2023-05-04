#pragma once
#include "en_def.h"
#include "en_shader_program.h"

namespace GLEngine
{
	class Basic2DProgram : public ShaderProgram
	{
	public:
		Basic2DProgram(Window& window, Shader shader);
		export virtual void Run(GLEngine::Drawing::Geometry& geometry) override;
	};

	class Basic3DProgram : public ShaderProgram
	{
	public:
		Basic3DProgram(Window& window, Shader shader);
		export virtual void Run(GLEngine::Drawing::Geometry& geometry) override;
	};

	class Textured2DProgram : public ShaderProgram
	{
	public:
		Textured2DProgram(Window& window, Shader shader);
		export virtual void Run(GLEngine::Drawing::Geometry& geometry) override;
	};

	class Textured3DProgram : public ShaderProgram
	{
	public:
		Textured3DProgram(Window& window, Shader shader);
		export virtual void Run(GLEngine::Drawing::Geometry& geometry) override;
	};

	class Light3DProgram : public ShaderProgram
	{
	public:
		Light3DProgram(Window& window, Shader shader);
		export virtual void Run(GLEngine::Drawing::Geometry& geometry) override;
	};

	class TexturedLight3DProgram : public ShaderProgram
	{
	public:
		TexturedLight3DProgram(Window& window, Shader shader);
		export virtual void Run(GLEngine::Drawing::Geometry& geometry) override;
	};

	class BitmapText2DProgram : public ShaderProgram
	{
	public:
		BitmapText2DProgram(Window& window, Shader shader);
		export virtual void Run(GLEngine::Drawing::Geometry& geometry) override;
	};

	class BitmapText3DProgram : public ShaderProgram
	{
	public:
		BitmapText3DProgram(Window& window, Shader shader);
		export virtual void Run(GLEngine::Drawing::Geometry& geometry) override;
	};

	class VoxelModel3DProgram : public ShaderProgram
	{
	public:
		VoxelModel3DProgram(Window& window, Shader shader);
		export virtual void Run(GLEngine::Drawing::Geometry& geometry) override;
	};

	class FrameBufferProgram : public ShaderProgram
	{
	public:
		FrameBufferProgram(Window& window, Shader shader);
		export virtual void Run(GLEngine::Drawing::Geometry& geometry) override;
	};
}