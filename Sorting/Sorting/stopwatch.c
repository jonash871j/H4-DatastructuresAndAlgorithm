#include "stopwatch.h"

void Stopwatch_Start(Stopwatch* stopwatch)
{
	LARGE_INTEGER l = { 0 };
	stopwatch->end = l;
	stopwatch->start = l;
	stopwatch->frequency = l;
	stopwatch->seconds = 0.0;
	QueryPerformanceFrequency(&stopwatch->frequency);
	QueryPerformanceCounter(&stopwatch->start);
}

void Stopwatch_Stop(Stopwatch* stopwatch)
{
	QueryPerformanceCounter(&stopwatch->end);
	stopwatch->seconds = (double)(stopwatch->end.QuadPart - stopwatch->start.QuadPart) / stopwatch->frequency.QuadPart;
}
