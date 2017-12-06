//main.c
//Jakub Dąbek

#include "phi.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 0;
	scanf("%d", &n);

	while(n != 0)
	{
		printf("phi(%d) = %d\n", n, phi(n));
		if(!scanf("%d", &n))
			return EXIT_FAILURE;
	}

	return 0;
}
