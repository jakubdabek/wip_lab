//main.c
//Jakub Dąbek

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*x))

const int MAX6_4 = 6*6*6*6;

int* get_combination(int index, int buffer[4])
{
    for(int i = 0; i < 4; i++)
    {
        buffer[i] = index % 6;
        index /= 6;
    }

    return buffer;
}

int print_combination(int combination[4])
{
    return printf("[%d] [%d] [%d] [%d]", 
        combination[0],
        combination[1],
        combination[2],
        combination[3]);
}

bool check(int current[4], int checked[4], int well_placed, int well_colored)
{
    // print_combination(current);
    // printf("      ");
    // print_combination(checked);
    // printf("  b:%d w:%d", well_placed, well_colored);
    bool found[2][4] = { { 0,0,0,0 }, { 0,0,0,0 } };
    int count = 0;
    for(int i = 0; i < 4; i++)
    {
        if(current[i] == checked[i])
        {
            count++;
            found[0][i] = true;
            found[1][i] = true;
        }
    }
    if(count != well_placed)
        return false;
    count = 0;
    for(int j = 0; j < 4; j++)
    {
        if(!found[1][j])
        {
            for(int i = 0; i < 4; i++)
            {
                if(!found[0][i] && checked[j] == current[i])
                {
                    count++;
                    found[0][i] = true;
                    found[1][j] = true;
                    break;
                }
            }
        }
    }

    return count == well_colored;
}

int main()
{
    bool possibilities[MAX6_4];
    for(int i = 0; i < MAX6_4; i++)
        possibilities[i] = true;
    
    int i;
    for(i = 0; i < MAX6_4; i++)
    {
        if(possibilities[i])
        {
            int combination[4];
            get_combination(i, combination);
            print_combination(combination);
            printf("\nblack: \n");
            int well_placed;
            scanf("%d", &well_placed);
            printf("white: \n");
            int well_colored;
            scanf("%d", &well_colored);
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

    if(i < MAX6_4)
    {
        printf("I win\n");
    }
    else
    {
        printf("You're cheating!\n");
    }
}
