//rectangle.c
//Jakub Dąbek

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **args)
{
	int n;
	if(argc > 1)
	{
		n = atoi(args[1]);
	}
	else
	{
		printf("Enter the rectangle's height:\n");
		scanf("%d", &n);
	}

	if(n < 0)
	{
		printf("Height cannot be negative!\n");
		return EXIT_FAILURE;
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n * 2; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
