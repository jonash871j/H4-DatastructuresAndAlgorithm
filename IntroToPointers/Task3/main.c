#include <stdio.h>
#include <string.h>

void Swap(int* v1, int* v2)
{
    int storeV1 = *v1;
    *v1 = *v2;
    *v2 = storeV1;
}

void SortNumbers(int* numbers, int size)
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

void PrintNumbers(int* numbers, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i,", numbers[i]);
    }
}

int main()
{
	int numbers[] = { 3, 6, 1, 2, 6, 3, 2, 9 };
	int size = sizeof(numbers) / 4;
    
    printf("Values before sorting: ");
    PrintNumbers(numbers, size);

    SortNumbers(numbers, size);

    printf("\nValues after sorting: ");
    PrintNumbers(numbers, size);
}