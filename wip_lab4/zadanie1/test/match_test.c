//match_test.c
//Jakub Dąbek

#include "../src/match.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 100

const char* const MATCH = "match";
const char* const NOMATCH = "no match";

char result_buffer[BUFFER_SIZE];

const char* result(bool expression, bool expected)
{
	sprintf(result_buffer, "%s, %s", expression ? MATCH : NOMATCH, expression == expected ? "OK" : "ERROR");
	return result_buffer;
}

int main(int argc, const char **args)
{
	bool pass = true;

	const char * const format = "pattern: %-20s  text: %-20s  result: %s\n";
	FILE * const output = stdout;
	char buffer[BUFFER_SIZE];
	char text[BUFFER_SIZE];

	bool expected = false;
	while(fgets(buffer, BUFFER_SIZE, stdin))
	{
		if(buffer[0] == '\n')
		{
			expected = !expected;
			fgets(text, BUFFER_SIZE, stdin);
			if(text[0] == '\n')
				break;
			if(text[strlen(text) - 1] == '\n')
			text[strlen(text) - 1] = '\0';
			continue;
		}
		
		if(buffer[strlen(buffer) - 1] == '\n')
			buffer[strlen(buffer) - 1] = '\0';

		fprintf(stderr, "\nSTART pattern: %-12s  text: %-12s\n", buffer, text);
		bool is_match = match(buffer, text);
		fprintf(output, format, buffer, text, result(is_match, expected));
		if(is_match != expected)
			pass = false;
	}

	fprintf(output, "\n%s\n", pass ? "all tests passed" : "error");
	return pass ? EXIT_SUCCESS : EXIT_FAILURE;
}
