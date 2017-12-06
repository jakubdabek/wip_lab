//main.c
//Jakub Dąbek

#include "solution.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
	return cos(x / 2);
}

int main(int argc, char **args)
{
	double a = 2.0, b = 4.0;
	double epsilon = 1.0 / 10.0;

	switch(argc)
	{
	default:
	case 4:
		epsilon = atof(args[3]);
	case 3:
		b = atof(args[2]);
	case 2:
		a = atof(args[1]);
	case 1:
	case 0:
		break;
	}

	for(int i = 1; i <= 8; i++)
	{
		printf("solution for f(x) = cos(x / 2) "
			   "for x in [%f, %f], epsilon = %1.8f: f(x) = 0 when x = %.10f\n",
						   a,  b,		  epsilon, solution(f, a, b, epsilon));

		epsilon /= 10.0;
	}

	return 0;
}
