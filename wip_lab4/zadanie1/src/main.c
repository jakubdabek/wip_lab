//main.c
//Jakub Dąbek

#include "match.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER_SIZE 100

int main(int argc, const char **args)
{
	char pattern[BUFFER_SIZE];
	char str[BUFFER_SIZE];

	if(argc >= 3)
	{
		strncpy(pattern, args[1], BUFFER_SIZE);
		strncpy(str, args[2], BUFFER_SIZE);
		//printf("%s %s\n", pattern, str);
	}
	else
	{
		printf("Enter pattern and string to be checked:\n");
		fgets(pattern, BUFFER_SIZE, stdin);
		fgets(str, BUFFER_SIZE, stdin);
	}

	if(pattern[strlen(pattern) - 1] == '\n')
		pattern[strlen(pattern) - 1] = '\0';
	if(str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';

	printf("%s\n", match(pattern, str) ? "match" : "no match");

	return 0;
}
