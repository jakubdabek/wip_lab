#include "io_utility.h"

#include <stdio.h>
#include <ctype.h>

static void print_combination(const int combination[4])
{
    printf("[%d] [%d] [%d] [%d]", 
        combination[0],
        combination[1],
        combination[2],
        combination[3]);
}

void query(const int combination[4], int * const well_placed_out, int * const well_colored_out)
{
    print_combination(combination);
    printf("\nblack: \n");
    scanf("%d", well_placed_out);
    printf("white: \n");
    scanf("%d", well_colored_out);
}

bool query_continue(bool result)
{    
    if(result)
    {
        printf("I win\n");
    }
    else
    {
        printf("You're cheating!\n");
    }

    printf("Do you want to try again? [Y/N]\n");
    char answer = 'N';
    scanf(" %c", &answer);
    while(getchar() != '\n') { }
    return tolower(answer) == 'y';
}
