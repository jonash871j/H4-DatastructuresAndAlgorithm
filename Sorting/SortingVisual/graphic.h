#pragma once
#include "en_engine.h"
#include "en_glfw_window.h"
#include "en_glfw_input.h"
#include <windows.h>

using namespace GLEngine;

inline GlfwWindow window(2560, 1440, "Sorting");
inline Renderer& renderer = window.GetRenderer();
inline Input& input = window.GetInput();
inline Camera& camera = renderer.GetCamera();
inline Modifier& modifier = renderer.GetModifier();
inline Time& ptime = window.GetTime();

enum class FontKey
{
	Default
};


static void InitializeGLEngine()
{
	window.Initialize("./Shaders/");
	window.SetIsFullScreen(false);
	window.SetLogicalSize(window.GetWidth() / 4, window.GetHeight() / 4);
}

static void UpdateView(int* numbers, int size)
{
	Sleep(25);
}