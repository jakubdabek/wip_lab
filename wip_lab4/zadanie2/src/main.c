//main.c
//Jakub Dąbek

#include "io_utility.h"
#include "utility.h"

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*x))

int main()
{
    int i;
    do
    {
        bool possibilities[MAX6_4];
        for(i = 0; i < MAX6_4; i++)
            possibilities[i] = true;
        
        for(i = 0; i < MAX6_4; i++)
        {
            if(possibilities[i])
            {
                int combination[4];
                get_combination(i, combination);
                int well_placed;
                int well_colored;
                query(combination, &well_placed, &well_colored);
                if(well_placed == 4 && well_colored == 0)
                    break;

                for(int j = i + 1; j < MAX6_4; j++)
                {
                    int buffer[4];
                    if(possibilities[j] && !check(combination, get_combination(j, buffer), well_placed, well_colored))
                    {
                        possibilities[j] = false;
                    }
                }
            }
        }
    } while(query_continue(i < MAX6_4));
}
