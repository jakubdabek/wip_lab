#pragma once

#include <stdbool.h>

extern const int MAX6_4;

int* get_combination(int, int[4]);
void get_combination_status(const int[4], const int[4], int * const, int * const);
bool check(const int[4], const int[4], int, int);
