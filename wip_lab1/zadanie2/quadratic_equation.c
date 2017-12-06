//quadratic_equation.c
//Jakub Dąbek

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 0.0000000001

int main(int argc, const char **args)
{
	double a, b, c;

	if(argc >= 4)
	{
		a = atof(args[1]);
		b = atof(args[2]);
		c = atof(args[3]);
	}	
	else
	{
		printf("Enter a, b and c for the equation a*x^2 + b*x + c = 0 :\n");
		scanf("%lf %lf %lf", &a, &b, &c);
	}

	if(fabs(a) < EPSILON)
	{
		printf("a = 0 - this is not a quadratic equation.\n");
	}

	double delta = b * b - 4 * a * c;

	if(delta < 0)
	{

		printf("There is no solution for %f*x^2 + %f*x + %f = 0 in real numbers\n", a, b, c);
		return 0;
	}

	double delta_sqrt = sqrt(delta);
	double solution1 = (-b + delta_sqrt) / (2 * a);

	if(delta < EPSILON)
	{
		printf("There is 1 solution for %f*x^2 + %f*x + %f = 0 :\nx = %f\n", a, b, c, solution1);
		return 0;
	}

	double solution2 = (-b - delta_sqrt) / (2 * a);
	printf("There are 2 solutions for %f*x^2 + %f*x + %f = 0 :\nx = %f and x = %f\n", a, b, c, solution1, solution2);

	return 0;
}
