#include <stdio.h>
#include <stdlib.h>
#include "stopwatch.h"
#include "sorting.h"

#define NUMBER_SIZE 100000

void TestSortingAlgorithm(const char* name, void(*SortAlgorithmCallback)(int* numbers, int size))
{
    Stopwatch stopwatch;
    int* randomNumbers = (int*)malloc(NUMBER_SIZE * sizeof(int));
    for (int i = 0; i < NUMBER_SIZE; i++)
    {
        randomNumbers[i] = rand() % 100;
    }

    Stopwatch_Start(&stopwatch);
    SortAlgorithmCallback(randomNumbers, NUMBER_SIZE);
    Stopwatch_Stop(&stopwatch);
    printf("\n%s finished sorting in %lf seconds with %i random numbers.\n", name, stopwatch.seconds, NUMBER_SIZE);

    Stopwatch_Start(&stopwatch);
    SortAlgorithmCallback(randomNumbers, NUMBER_SIZE);
    Stopwatch_Stop(&stopwatch);
    printf("Already sorted %s finished sorting in %lf seconds with %i random numbers.\n", name, stopwatch.seconds, NUMBER_SIZE);

    free(randomNumbers);
}

void main()
{
    TestSortingAlgorithm("BubbleSort", BubbleSort);
    TestSortingAlgorithm("SlectionSort", SlectionSort);
    TestSortingAlgorithm("InsertionSort", InsertionSort);
    TestSortingAlgorithm("MergeSort", MergeSort);
    TestSortingAlgorithm("QuickSort", QuickSort);
}
