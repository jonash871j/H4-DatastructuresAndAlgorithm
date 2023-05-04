#pragma once
#include "en_def.h"
#include "en_input.h"

namespace GLEngine
{
	class GlfwInput : public Input
	{
	private:
		GLFWwindow* _glfwWindow;

	public:
		GlfwInput(Window& window);

	public:
		export void Initialize(GLFWwindow* glfwWindow);
		export bool KeyState(Key key) override;
		export bool MouseState(MouseButton mouseButton) override;
		export void SetIsMouseDeltaMode(bool state) override;
		export bool GetIsMouseDeltaMode() override;

	public:
		void Update() override;
		void Reset() override;
	};
}
