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

	const char * const format = "pattern: %-10s  text: %-10s  result: %s\n";
	FILE * const output = stdout;
	char buffer[BUFFER_SIZE];

	bool expected = true;
	while(fgets(buffer, BUFFER_SIZE, stdin))
	{
		if(*buffer == '\n')
		{
			expected = !expected;
			continue;
		}
		
		if(buffer[strlen(buffer) - 1] == '\n')
			buffer[strlen(buffer) - 1] = '\0';

		bool is_match = match(buffer, "pattern");
		fprintf(output, format, buffer, "pattern", result(is_match, expected));
		if(is_match != expected)
			pass = false;
	}

	fprintf(output, "\n%s\n", pass ? "all tests passed" : "error");
	return pass ? EXIT_SUCCESS : EXIT_FAILURE;
}
