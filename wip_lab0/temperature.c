//temperature.c
//Jakub Dąbek
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("Enter temperature value in ºC:\n");
	float temperature;
	scanf("%f", &temperature);
	if(temperature < -273.15f)
	{
		printf("There can't be a temperature lower than absolute zero!\n");
		return EXIT_FAILURE;
	}
	if(temperature == -40)
	{
		printf("-40ºC is the same as -40ºF. How cool is that?\n");
	}
	else
	{
		printf("%fºC is the same as %fºF\n", temperature, temperature * 1.8f + 32);
	}

	return 0;
}
