//money.c
//Jakub Dąbek

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BILL_DENOMINATIONS_COUNT 5
#define COIN_DENOMINATIONS_COUNT 9
#define BUFFER_SIZE 10

const char* format_money(char[], int);
void print_money(int[], int[], size_t);

int main(int argc, char **args)
{
	int bill_denominations[] = { 20000, 10000, 5000, 2000, 1000 };
	int coin_denominations[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };

	int bills[BILL_DENOMINATIONS_COUNT] = { 0 };
	int coins[COIN_DENOMINATIONS_COUNT] = { 0 };

	int amount;
	if(argc > 2)
	{
		amount = atoi(args[1]) * 100 + atoi(args[2]);
	}
	else
	{
		int temp;
		printf("enter number of zloty: ");
		scanf("%d", &temp);
		amount = 100 * temp;
		printf("enter number of groszy: ");
		scanf("%d", &temp);
		amount += temp;
	}
	

	for(int i = 0; amount > 0; i++)
	{
		if(i < BILL_DENOMINATIONS_COUNT)
		{
			bills[i] = amount / bill_denominations[i];
			amount = amount % bill_denominations[i];
		}
		else
		{
			int coin_i = i - BILL_DENOMINATIONS_COUNT;
			coins[coin_i] = amount / coin_denominations[coin_i];
			amount = amount % coin_denominations[coin_i];
		}
	}

	printf("Bills:\n");
	print_money(bill_denominations, bills, BILL_DENOMINATIONS_COUNT);

	printf("Coins:\n");
	print_money(coin_denominations, coins, COIN_DENOMINATIONS_COUNT);	
}

void print_money(int denominations[], int values[], size_t max_size)
{
	char buffer[BUFFER_SIZE];

	for(int i = 0; i < max_size; i++)
	{
		if(values[i] > 0)
		{
			printf("%d x %s\n", values[i], format_money(buffer, denominations[i]));
		}
		else if(i == max_size - 1)
		{
			printf("None\n");
		}
	}
}

const char* format_money(char buffer[BUFFER_SIZE], int amount)
{
	if(amount >= 100)
	{
		snprintf(buffer, BUFFER_SIZE, "%d zl", amount / 100);
	}
	else
	{
		snprintf(buffer, BUFFER_SIZE, "%d gr", amount);
	}

	return buffer;
}
