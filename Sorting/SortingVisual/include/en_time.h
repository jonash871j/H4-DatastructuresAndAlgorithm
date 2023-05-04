#pragma once
#include "en_def.h"

namespace GLEngine
{
	class Time
	{
		friend Window;
	private:
		float _tick;
		float _lastTime = 0.0001f;
		float _deltaTime = 0.0001f;
		float _fPS = 0.0f;
		float _avgFPS = 0.0f;
		float _avgFPSStore = 0.0f;
		uint8_t _avgFPSInterval = 0;

	public:
		export float GetTick();
		export float GetDeltaTime();
		export float GetFPS();
		export float GetAvgFPS();

	public:
		void Update(float tick);
	};
}