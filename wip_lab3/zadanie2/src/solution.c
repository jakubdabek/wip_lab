//solution.c
//Jakub Dąbek

#include "solution.h"

#include <math.h>
#include <assert.h>

double solution(double (*f)(double), double a, double b, double epsilon)
{
	assert(a < b);
	assert(f(a) * f(b) < 0);

	double tmp = a;

	while((b - a) > epsilon)
	{
		tmp = (a + b) / 2;
		if(f(a) * f(tmp) < 0)
			b = tmp;
		else if(f(b) * f(tmp) < 0)
			a = tmp;
		else
			return tmp;
	}

	return tmp;
}
