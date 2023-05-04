#pragma once
#include "en_def.h"
#include "en_window.h"

namespace GLEngine
{
	class GlfwWindow : public Window
	{
	private:
		const char* _title;
		bool _isFullScreen = false;
		GLFWwindow* _glfwWindow;
		GlfwInput* _glfwInput;

	private:
		GlfwWindow();

	public:
		export GlfwWindow(int windowWidth, int windowHeight, const char* title);
		export ~GlfwWindow();

	public:
		export void Initialize(string glEngineShaderPath = "../GLEngineLibResources/Shaders/") override;
		export void Close();

	public:
		export const char* GetTitle();
		export GLFWwindow& GetGlfwWindow();
		export GlfwInput& GetGlfwInput();
		export void SetTitle(const char* title);
		export void SetLogicalSize(int width, int height) override;
		export void SetIsFullScreen(bool isFullScreen);
		export void SetResoulution(int windowWidth, int windowHeight);
		export bool GetIsFullScreen();
		export bool GetIsRunning();

	public:
		void InternalSwapBuffers() override;

	private:
		void InternalUpdate() override;
	};
}
