//coprimes.c
//Jakub Dąbek

#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b);

int main(int argc, const char **args)
{
	int MAX;
	if(argc > 1)
		MAX = atoi(args[1]);
	else
		MAX = 1000;

	int **gcds = malloc((MAX - 2) * sizeof(int*));
	for(int i = 0; i < MAX - 2; i++)
	{
		gcds[i] = malloc((i + 1) * sizeof(int));
	}

	for(int i = 0; i <= MAX - 3; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			int gcd = GCD(i + 3, j + 2);
			gcds[i][j] = gcd;
			//fprintf(stderr, "%d ", gcd);
		}
		//fprintf(stderr, "\n");
	}

	int *tau = malloc(MAX * sizeof(int));

	tau[1 - 1] = 1; 		// (1,1)
	tau[2 - 1] = tau[1 - 1] + 2; 	// (1,2), (2,1)

	int current_tau = 3;

	for(int i = 0; i <= MAX - 3; i++)
	{
		current_tau += 2;	//(1,i+1), (i+1,1)
		for(int j = 0; j <= i; j++)
		{
			if(gcds[i][j] == 1)
				current_tau += 2;
		}
		//fprintf(stderr, "(%d,%d) ", i, current_tau);
		tau[i + 2] = current_tau;
	}

	//FILE *file = fopen("./values.csv", "w+");
	//if(file != NULL)
	//{
		char buffer[20];

		for(int i = 0; i < MAX; i++)
		{
			int n = i + 1;

			sprintf(buffer, "%d;%f\n", n, tau[i] / (double)(n * n));

			printf("%s", buffer);
			//fputs(buffer, file);
		}

		//fclose(file);
	//}

	for(int i = 0; i < MAX - 2; i++)
	{
		free(gcds[i]);
	}
	free(gcds);
	free(tau);
	return 0;
}

int GCD(int a, int b)
{
	while(b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}
