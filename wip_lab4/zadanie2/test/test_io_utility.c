#include "../src/io_utility.h"
#include "../src/utility.h"

#include <stdio.h>
#include <ctype.h>

static int index = 0;
static int counter = 0;
static int current_combination[4];

void query(const int combination[4], int * const well_placed_out, int * const well_colored_out)
{
    get_combination_status(current_combination, combination, well_placed_out, well_colored_out);
    counter++;
}

bool query_continue(bool result)
{
    printf("%d%d%d%d,%d\n", 
        current_combination[0],
        current_combination[1],
        current_combination[2],
        current_combination[3],
        counter);
    
    if(++index < MAX6_4)
    {
        get_combination(index, current_combination);
        counter = 0;
        return true;
    }
    else
    {
        return false;
    }
}
