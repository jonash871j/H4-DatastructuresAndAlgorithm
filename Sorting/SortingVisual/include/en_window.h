#pragma once
#include "en_def.h"
#include "en_input.h"

namespace GLEngine
{
	class Window abstract
	{
	protected:
		int _width = 800;
		int _height = 600;
		int _windowWidth = 800;
		int _windowHeight = 600;
		Renderer* _renderer = nullptr;
		SoundSystem* _soundSystem = nullptr;
		Time* _time = nullptr;
		Input* _input = nullptr;

	public:
		export Window();
		export Window(int windowWidth, int windowHeight);

	public:
		export virtual void SetLogicalSize(int width, int height) = 0;
		export void Update();
		export int GetWidth();
		export int GetHeight();
		export int GetWindowWidth();
		export int GetWindowHeight();
		export Renderer& GetRenderer();
		export SoundSystem& GetSoundSystem();
		export Time& GetTime();
		export Input& GetInput();

	public:
		export virtual void Initialize(string glEngineShaderPath) = 0;
		virtual void InternalSwapBuffers() = 0;

	protected:
		virtual void LoadDefaultShaders(string path);
		virtual void InternalUpdate() = 0;
	};
}
