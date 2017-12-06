//palindrome.c
//Jakub Dąbek

#include "palindrome.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(const char *text)
{
	size_t len = strlen(text);
	if(len < 2)
		return true;

	const char *from_start = text;
	const char *from_end = (text + len - 1);

	for(; from_end > from_start; from_start++, from_end--)
	{
		if(*from_start != *from_end)
			return false;
	}

	return true;
}

