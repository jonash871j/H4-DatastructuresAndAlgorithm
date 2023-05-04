#pragma once
#include "en_def.h"

namespace GLEngine
{
	enum class TimerState
	{
		Ready,
		Active,
		Done,
	};

	class Timer
	{
	private:
		unsigned _ms = 0;
		TimerState _timerState = TimerState::Ready;
		std::chrono::system_clock::time_point _start;
		std::chrono::system_clock::time_point _end;

	public:
		export void StartTimer(unsigned ms);
		export void ResetTimer();
		export void ResetTimerWhenDone();
		export TimerState GetTimerState();
	};
}
