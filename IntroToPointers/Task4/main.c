#include <stdio.h>
#include <stdlib.h>

typedef enum { false = 0, true = 1 } bool;

bool IsLetter(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int CountWords(const char* str)
{
	int wordCount = 0;
	size_t size = strlen(str);
	bool isWordFound = false;

	for (int i = 0; i < size; i++)
	{
		if (IsLetter(str[i]))
		{
			isWordFound = true;
		}
		else if (isWordFound)
		{
			wordCount++;
			isWordFound = false;
		}
	}
	return wordCount;
}

void main()
{
	const char* str = "This is a test on how many words there     are.\nThis ";
	int wordAmount = CountWords(str);
	printf("There is %i words in this sentence: %s\n", wordAmount, str);
}
