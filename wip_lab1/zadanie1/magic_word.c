//magic_word.c
//Jakub Dąbek

#include<stdio.h>
#include<string.h>

int main(int argc, char **args)
{
	const char* word = "ABRAKADABRA";
	if(argc > 1)
	word = args[1];
	size_t length = strlen(word);

	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for(int j = 0; j < length - i; j++)
		{
			printf("%c ", word[j]);
		}
		printf("\n");
	}

	return 0;
}
