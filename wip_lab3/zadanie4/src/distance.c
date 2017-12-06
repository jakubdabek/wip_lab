//distance.c
//Jakub Dąbek

#include "agents.h"

#include <math.h>

double distance(struct agent a1, struct agent a2)
{
	int x = a1.x - a2.x;
	int y = a1.y - a2.y;

	return sqrt((x * x) + (y * y));
}
