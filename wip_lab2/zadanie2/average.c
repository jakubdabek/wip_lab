//average.c
//Jakub Dąbek

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Input n:\n");
	scanf("%d", &n);
	float array[n];

	printf("Input %d numbers:\n", n);
	for(int i = 0; i < n; i++)
	{
		scanf("%f", &array[i]);
	}

	float sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += array[i];
	}

	printf("The average of these numbers equals %f\n", sum / n);

	return 0;
}
