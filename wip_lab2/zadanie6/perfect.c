//perfect.c
//Jakub Dąbek

#include<stdio.h>
#include<stdlib.h>

int MAX = 999 + 1;

int divisor_sum(int);
int main(int argc, char** args)
{
	if(argc > 1)
		MAX = atoi(args[1]) + 1;
	int *divisor_sums = malloc(MAX * sizeof(int));

	for(int i = 1; i < MAX; i++)
	{
		divisor_sums[i] = divisor_sum(i);
	}

	for(int i = 1; i < MAX; i++)
	{
		if(divisor_sums[i] == i)
			printf("%d\n", i);
	}

	printf("\n");

	for(int i = 1; i < MAX; i++)
	{
		int current = divisor_sums[i];
		if(current > MAX)
			continue;
		int other = divisor_sums[current];
		if(current < other && other == i)
			printf("(%d, %d)\n", current, other);
	}

	free(divisor_sums);
	
	return 0;
}

int divisor_sum(int n)
{
	int sum = 0;
	int i;

	for(i = 1; i * i < n; i++)
	{
		if(n % i == 0)
		{
			sum += i + n / i;
		}
	}

	if(i * i == n)
		sum += i;

	return sum - n;
}
