//harmonic.c
//Jakub Dąbek

#include<stdio.h>

int main()
{
	double sum = 0.0;
	int i = 0;
	while(sum <= 10)
		sum += 1.0 / ++i;
	printf("∑(1/n) >= 10 for n >= %d\n", i);
}
