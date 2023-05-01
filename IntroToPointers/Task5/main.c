#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

void PrintValues(char** words, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%s, ", words[i]);
	}
}

char* CompareTwoWords(char* w1, char* w2)
{
	int w1Length = strlen(w1);
	int w2Length = strlen(w2);
	int minLength = min(w1Length, w2Length);

	for (int i = 0; i < minLength; i++)
	{
		// Goto next character if characters are the same in both words
		if (w1[i] == w2[i])
		{
			continue;
		}
		// Return the word with the character with the lowest ascii value
		return w1[i] < w2[i] ? w1 : w2;
	}
	// Returns the shortes word if the first parts of the words are the same
	return w1Length == minLength ? w1 : w2;
}

void SortWords(char** words, int size)
{
	// Clones word pointers
	char** tempWords = malloc(size);
	for (int i = 0; i < size; i++)
	{
		tempWords[i] = words[i];
	}

	// Sort words
	for (int i = 0; i < size; i++)
	{
		int currentWordIndex = 0;
		for (int j = 0; j < size; j++)
		{
			// Goto next word if word to check is NULL
			if (tempWords[j] == NULL)
			{
				continue;
			}
			// Increment word index if current word is NULL
			while (tempWords[currentWordIndex] == NULL && currentWordIndex < size - 1)
			{
				currentWordIndex++;
			}

			// Compares two words
			char* wordCompared = CompareTwoWords(tempWords[currentWordIndex], tempWords[j]);
			if (wordCompared != tempWords[currentWordIndex])
			{
				currentWordIndex = j;
			}
		}
		// Add sorted word to main array
		words[i] = tempWords[currentWordIndex];

		// Declare NULL on temp array on sorted word
		tempWords[currentWordIndex] = NULL;
	}
}

int main()
{
	char* words[] = { "apple", "duck", "bat", "air", "cat", "berry", "cake", "carrot", "dog" };

	printf("Before sorting: ");
	PrintValues(words, 9);

	SortWords(words, 9);

	printf("\nAfter sorting: ");
	PrintValues(words, 9);
}