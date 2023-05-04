#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include "stopwatch.h"
#include "sorting.h"
#include "graphic.h"

#define NUMBER_SIZE 50

int randomNumbers[NUMBER_SIZE];


void TestSortingAlgorithm(const char* name, void(*SortAlgorithmCallback)(int* numbers, int size))
{
	Stopwatch stopwatch;
	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		randomNumbers[i] = rand() % 320;
		Sleep(25);
	}

	Stopwatch_Start(&stopwatch);
	SortAlgorithmCallback(randomNumbers, NUMBER_SIZE);
	Stopwatch_Stop(&stopwatch);
	printf("\n%s finished sorting in %lf seconds with %i random numbers.\n", name, stopwatch.seconds, NUMBER_SIZE);

	Sleep(1000);
}

void SortThread()
{
	while (window.GetIsRunning())
	{
		TestSortingAlgorithm("BubbleSort", BubbleSort);
		TestSortingAlgorithm("SlectionSort", SlectionSort);
		TestSortingAlgorithm("InsertionSort", InsertionSort);
		TestSortingAlgorithm("MergeSort", MergeSort);
		TestSortingAlgorithm("QuickSort", QuickSort);
	}
}

void HueToRgb(int H, int& R, int& G, int& B)
{
	float s = 100 / 100;
	float v = 100 / 100;
	float C = s * v;
	float X = C * (1 - abs(fmod(H / 60.0, 2) - 1));
	float m = v - C;
	float r, g, b;
	if (H >= 0 && H < 60) {
		r = C, g = X, b = 0;
	}
	else if (H >= 60 && H < 120) {
		r = X, g = C, b = 0;
	}
	else if (H >= 120 && H < 180) {
		r = 0, g = C, b = X;
	}
	else if (H >= 180 && H < 240) {
		r = 0, g = X, b = C;
	}
	else if (H >= 240 && H < 300) {
		r = X, g = 0, b = C;
	}
	else {
		r = C, g = 0, b = X;
	}
	R = (r + m) * 255;
	G = (g + m) * 255;
	B = (b + m) * 255;
}

void main()
{
	window.Initialize("./Shaders/");
	window.SetIsFullScreen(false);
	input.SetIsMouseDeltaMode(true);
	std::thread t(SortThread);

	while (window.GetIsRunning())
	{
		vec3 cameraPos = camera.GetPosition();
		float camSpeed = 128.0f * ptime.GetDeltaTime();
		cameraPos += (input.KeyState(Key::W) - input.KeyState(Key::S)) * camSpeed * camera.GetMovementX();
		cameraPos += (input.KeyState(Key::D) - input.KeyState(Key::A)) * camSpeed * camera.GetMovementZ();
		cameraPos += (input.KeyState(Key::Space) - input.KeyState(Key::LeftShift)) * camSpeed * camera.GetMovementY();
		camera.SetYaw(camera.GetYaw() + input.MouseDelta().x / 16.0f);
		camera.SetPitch(camera.GetPitch() + input.MouseDelta().y / 16.0f);
		camera.SetPosition(cameraPos);

		modifier.SetDefault();
		for (int i = 0; i < NUMBER_SIZE; i++)
		{
			int r, g, b;
			HueToRgb(randomNumbers[i], r, g, b);

			modifier.SetColor(r,g,b);
			renderer.Draw3DCube({ i * 16, 0, 0 }, { 12, randomNumbers[i] * 2, 12 });
		}

		window.Update();
	}
	t.join();
}
