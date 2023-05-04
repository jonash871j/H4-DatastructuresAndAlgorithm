#pragma once
#include "en_def.h"
#include "en_input.h"

namespace GLEngine
{
	class Win32Input : public Input
	{
	private:
		bool isKeyInputEnabled = false;

	public:
		Win32Input(Window& window);

	public:
		export void EnableKeyInput(bool isKeyInputEnabled);
		export bool IsKeyInputEnabled();
		export bool KeyState(Key key) override;
		export bool MouseState(MouseButton mouseButton) override;
		export void SetIsMouseDeltaMode(bool state) override;
		export bool GetIsMouseDeltaMode() override;

	public:
		void Update() override;
		void Reset() override;

	private:
		vec2 GetMousePosRelToWindow();
		void SetMousePosRelToWindow(vec2 mousePos);
	};
}
