//main.c
//Jakub Dąbek

#include "palindrome.h"

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

int main(int argc, const char **args)
{
	char text[BUFFER_SIZE];
	if(argc > 1)
		strcpy(text, args[1]);
	else
	{
		fgets(text, BUFFER_SIZE, stdin);
		if(text[strlen(text) - 1] == '\n')
			text[strlen(text) - 1] = '\0';
	}

	printf("\"%s\" is %s a palindrome\n", text, is_palindrome(text) ? "\b" : "not");
}
