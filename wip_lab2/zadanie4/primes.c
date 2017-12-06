//primes.c
//Jakub Dąbek

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, const char **args)
{
	int MAX;
	if(argc > 1)
		MAX = atoi(args[1]) + 1;
	else
		MAX = 100000 + 1;

	bool *primality_array = malloc(MAX * sizeof(bool));
	for(int i = 2; i < MAX; i++)
		primality_array[i] = true;
	primality_array[0] = false;
	primality_array[1] = false;

	int limit = sqrt(MAX);
	for(int i = 2; i <= limit; i++)
	{
		if(primality_array[i])
			for(int j = i * i; j <= MAX; j += i)
				primality_array[j] = false;
	}

	int *pi = malloc(MAX * sizeof(int));
	int primes_count = 0;
	for(int i = 0; i < MAX; i++)
	{
		if(primality_array[i])
			primes_count++;
		pi[i] = primes_count;
	}

	//FILE *file = fopen("./values.csv", "w+");
	//if(file != NULL)
	//{
	//	for(int i = 2; i < 1000; i++)
	//	{
	//		fprintf(file, "%d;%f\n", i, pi[i] * log(i) / i);
	//	}
	//	fclose(file);
	//}

	for(int i = 2; i < MAX; i++)
		printf("%d;%f\n", i, pi[i] * log(i) / i);

	free(pi);
	free(primality_array);

	return 0;
}
