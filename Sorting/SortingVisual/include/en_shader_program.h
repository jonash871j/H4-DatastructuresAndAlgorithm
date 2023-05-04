#pragma once
#include "en_def.h"
#include "en_shader.h"
#include "en_window.h"
#include "en_modifer.h"
#include "en_camera.h"

namespace GLEngine
{
	class export ShaderProgram abstract
	{
	protected:
		Modifier& modifier;
		Camera& camera;
		Window& window;
		Shader shader;

	public:
		ShaderProgram(Window& window, Shader shader);

	public:
		virtual void Run(GLEngine::Drawing::Geometry& geometry) = 0;

	protected:
		void SetProjection2D();
		void SetProjection3D();
	};
}