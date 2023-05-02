#include <stdio.h>
#include <stdlib.h>
#include "stopwatch.h"
#include "sorting.h"

#define NUMBER_SIZE 20000

void GenerateArrayWithRandomNumbers(int** numberArray, int size)
{
    if (*numberArray != NULL)
    {
        free(*numberArray);
    }
    int* newNumberArray = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        newNumberArray[i] = rand() % 100;
    }
    *numberArray = newNumberArray;
}

void PrintResults(const char* title, Stopwatch* stopwatch)
{
    printf("%s finished sorting in %lf seconds with %i random numbers.\n", title, stopwatch->seconds, NUMBER_SIZE);
}

void PrintNumbers(int* numbers, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i, ", numbers[i]);
    }
    printf("\n");
}

void main()
{
    Stopwatch stopwatch;
    int* randomNumbers = NULL;

    GenerateArrayWithRandomNumbers(&randomNumbers, NUMBER_SIZE);
    Stopwatch_Start(&stopwatch);
    BubbleSort(randomNumbers, NUMBER_SIZE);
    Stopwatch_Stop(&stopwatch);
    PrintResults("Bubblesort", &stopwatch);

    GenerateArrayWithRandomNumbers(&randomNumbers, NUMBER_SIZE);
    Stopwatch_Start(&stopwatch);
    SlectionSort(randomNumbers, NUMBER_SIZE);
    Stopwatch_Stop(&stopwatch);
    PrintResults("Selectionsort", &stopwatch);

    GenerateArrayWithRandomNumbers(&randomNumbers, NUMBER_SIZE);
    Stopwatch_Start(&stopwatch);
    InsertionSort(randomNumbers, NUMBER_SIZE);
    Stopwatch_Stop(&stopwatch);
    PrintResults("Insertionsort", &stopwatch);

    GenerateArrayWithRandomNumbers(&randomNumbers, NUMBER_SIZE);
    Stopwatch_Start(&stopwatch);
    MergeSort(randomNumbers, NUMBER_SIZE);
    Stopwatch_Stop(&stopwatch);
    PrintResults("Mergesort", &stopwatch);
}
