#pragma once
#include <windows.h>

typedef struct Stopwatch
{
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double seconds;
}Stopwatch;

void Stopwatch_Start(Stopwatch* stopwatch);
void Stopwatch_Stop(Stopwatch* stopwatch);