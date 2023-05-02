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
	for (int i = 0; i < size; i++)
	{
		int j = i;
		while (j >= 0 && numbers[j - 1] > numbers[j])
		{
			Swap(&numbers[j], &numbers[j - 1]);
			j = j - 1;
		}
	}
}

static void Merge(int numbers[], int leftIndex, int mid, int rightIndex)
{
	int i, j, k;
	int n1 = mid - leftIndex + 1;
	int n2 = rightIndex - mid;

	int* tempLeftNumbers = malloc(n1 * sizeof(int));
	int* tempRightNumbers = malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
	{
		tempLeftNumbers[i] = numbers[leftIndex + i];
	}
	for (j = 0; j < n2; j++)
	{
		tempRightNumbers[j] = numbers[mid + 1 + j];
	}

	i = 0;
	j = 0;
	k = leftIndex;
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

static void MergeSortInternal(int arr[], int l, int r)
{
	if (l < r) 
	{
		int mid = l + (r - l) / 2;
		MergeSortInternal(arr, l, mid);
		MergeSortInternal(arr, mid + 1, r);
		Merge(arr, l, mid, r);
	}
}

void MergeSort(int* numbers, int size)
{
	MergeSortInternal(numbers, 0, size - 1);
}