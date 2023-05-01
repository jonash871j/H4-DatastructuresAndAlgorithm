#include <stdio.h>
#include <string.h>

void ReverseString(char* str)
{
	size_t size = strlen(str);
	for (int i = 0; i < size / 2; i++)
	{
		char c1 = str[i];
		char c2 = str[size - i - 1];
		str[i] = c2;
		str[size - i - 1] = c1;
	}
}

int main()
{
	char word[] = "rambuk\0";
	ReverseString(word);
	printf("%s\n", word);
}