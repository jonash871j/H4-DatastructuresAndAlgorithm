#pragma once
#include "en_def.h"
#include "en_shader.h"
#include "en_rectangle.h"

namespace GLEngine
{
	class FrameBuffer
	{
	private:
		GLEngine::Drawing::Rectangle frameGeometry = GLEngine::Drawing::Rectangle({ -1, -1 }, { -1, 1 }, { 1, 1 }, { 1, -1 });
		unsigned _FBO = 0;
		unsigned _RBO = 0;
		unsigned _width = 0;
		unsigned _height = 0;
		unsigned _textureColorbuffer = 0;
		vec3 _backgroundColor = { 0.0f, 0.0f, 0.0f };

	public:
		FrameBuffer(unsigned width, unsigned height);

	public:
		void Initialize();
		void UpdateResolution(unsigned width, unsigned height);
		void Draw(unsigned windowWidth, unsigned windowHeight);
		void Reset();
		void SetBackgroundColor(vec3 backgroundColor);
	};
}

