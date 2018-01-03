//match.c
//Jakub Dąbek

#include "match.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 100

bool match_impl(const char*, const char*, size_t, size_t);

bool match(const char *pattern, const char *str)
{
	return match_impl(pattern, str, strlen(pattern), strlen(str));
}

bool match_impl(const char *pattern, const char *str, size_t pattern_len, size_t str_len)
{
	while(*pattern != '*')
	{
		if(pattern_len == 0 || str_len == 0 || *pattern == '\0' || *str == '\0')
		{
			return *pattern == *str;
		}

		if(*pattern == '?' || *pattern == *str)
		{
			pattern++;
			pattern_len--;
			str++;
			str_len--;
		}
		else
		{
			return false;
		}
	}

	while(pattern[pattern_len - 1] != '*')
	{
		if(pattern[pattern_len - 1] == '?' || pattern[pattern_len - 1] == str[str_len - 1])
		{
			pattern_len--;
			str_len--;
		}
		else
		{
			return false;
		}

	}
	
	while(*pattern == '*')
	{
		pattern++;
		pattern_len--;
	}

	for(int i = 0; i <= str_len; i++)
	{
		if(match_impl(pattern, str + i, pattern_len, str_len - i))
		{
			return true;
		}
	}
	
	return false;
}
