//phi.c
//Jakub Dąbek

#include "phi.h"

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


int phi(long int n)
{
	int count = 1;

	for(long int i = 2; i < n; i++)
	{
		if(GCD(i, n) == 1)
			count++;
	}

	return count;
}
