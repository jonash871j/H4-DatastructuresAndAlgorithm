#pragma once
#include "en_def.h"
#include "en_window.h"
#include <Windows.h>
#include <chrono>

namespace GLEngine
{
	class Win32Window : public Window
	{
	private:
		HWND _hWnd;
		HDC _hDC;
		HGLRC _hRC;
		std::chrono::system_clock::time_point _tp1;
		std::chrono::system_clock::time_point _tp2;
		Win32Input* _win32Input;

	public:
		export Win32Window(HWND hWnd, int windowWidth, int windowHeight);

	public:
		export void Initialize(string glEngineShaderPath = "../GLEngineLibResources/Shaders/") override;
		export void SetLogicalSize(int width, int height) override;
		export void SetResoulution(int windowWidth, int windowHeight);
		export HWND GetHWND();

	private:
		virtual void InternalSwapBuffers() override;
		virtual void InternalUpdate() override;

	private:
		 void InitializeHRC();
	};
}
