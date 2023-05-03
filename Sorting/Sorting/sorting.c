#include "sorting.h"

#include <stdio.h>
#include <stdlib.h>

static void Swap(int* v1, int* v2)
{
	int storeV1 = *v1;
	*v1 = *v2;
	*v2 = storeV1;
}

void BubbleSort(int* numbers, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (numbers[j] > numbers[j + 1])
			{
				Swap(&numbers[j], &numbers[j + 1]);
			}
		}
	}
}

void SlectionSort(int* numbers, int size)
{
	for (int i = 0; i < size; i++)
	{
		int lowestValueIndex = i;
		for (int j = i; j < size; j++)
		{
			if (numbers[j] < numbers[lowestValueIndex])
			{
				lowestValueIndex = j;
			}
		}
		Swap(&numbers[lowestValueIndex], &numbers[i]);
	}
}

void InsertionSort(int* numbers, int size)
{
	for (int i = 1; i < size - 1; i++)
	{
		int j = i;
		while (j > 1 && numbers[j - 1] > numbers[j])
		{
			Swap(&numbers[j], &numbers[j - 1]);
			j = j - 1;
		}
	}
}

static void Merge(int* numbers, int start, int mid, int end)
{
	int i, j, k;
	int n1 = mid - start + 1;
	int n2 = end - mid;

	int* tempLeftNumbers = (int*)malloc(n1 * sizeof(int));
	int* tempRightNumbers = (int*)malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
	{
		tempLeftNumbers[i] = numbers[start + i];
	}
	for (j = 0; j < n2; j++)
	{
		tempRightNumbers[j] = numbers[mid + 1 + j];
	}

	i = 0;
	j = 0;
	k = start;
	while (i < n1 && j < n2)
	{
		if (tempLeftNumbers[i] <= tempRightNumbers[j])
		{
			numbers[k] = tempLeftNumbers[i];
			i++;
		}
		else
		{
			numbers[k] = tempRightNumbers[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		numbers[k] = tempLeftNumbers[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		numbers[k] = tempRightNumbers[j];
		j++;
		k++;
	}

	free(tempLeftNumbers);
	free(tempRightNumbers);
}

static void MergeSortInternal(int* numbers, int start, int end)
{
	if (start < end)
	{
		int mid = start + (end - start) / 2;
		MergeSortInternal(numbers, start, mid);
		MergeSortInternal(numbers, mid + 1, end);
		Merge(numbers, start, mid, end);
	}
}

void MergeSort(int* numbers, int size)
{
	MergeSortInternal(numbers, 0, size - 1);
}

static int Partition(int* numbers, int start, int end)
{
	int pivot = numbers[end];
	int i = (start - 1);

	for (int j = start; j <= end - 1; j++)
	{

		if (numbers[j] < pivot)
		{
			i++;
			Swap(&numbers[i], &numbers[j]);
		}
	}
	Swap(&numbers[i + 1], &numbers[end]);
	return (i + 1);
}

static void QuickSortInternal(int* numbers, int start, int end)
{
	if (start < end)
	{
		int pi = Partition(numbers, start, end);
		QuickSortInternal(numbers, start, pi - 1);
		QuickSortInternal(numbers, pi + 1, end);
	}
}


void QuickSort(int* numbers, int size)
{
	QuickSortInternal(numbers, 0, size - 1);
}
