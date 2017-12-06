#include <stdio.h>

#define BUFFER_LENGTH 40
int main(void)
{
	float a, b;
	char buff[BUFFER_LENGTH];
	printf("Enter 2 real numbers\n");
	scanf("%f %f", &a, &b);
	printf( "sum:\t\t %f + %f = %f\n"
		"difference:\t %f - %f = %f\n"
		"product:\t %f * %f = %f\n"
		"quotient:\t %s\n", 
		a, b, a + b,
		a, b, a - b,
		a, b, a * b,
		b != 0 ? snprintf(buff, BUFFER_LENGTH, "%f ÷ %f = %f", a, b, a / b), buff : "You can't divide by 0");
}
