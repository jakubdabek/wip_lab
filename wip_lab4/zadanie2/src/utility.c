#include "utility.h"

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

void get_combination_status(
    const int desired[4], 
    const int checked[4], 
    int *const well_placed_out, 
    int *const well_colored_out)
{
    // print_combination(desired);
    // printf("      ");
    // print_combination(checked);
    // printf("  b:%d w:%d", well_placed, well_colored);
    bool found[2][4] = { { 0,0,0,0 }, { 0,0,0,0 } };
    int count = 0;
    for(int i = 0; i < 4; i++)
    {
        if(desired[i] == checked[i])
        {
            count++;
            found[0][i] = true;
            found[1][i] = true;
        }
    }
    *well_placed_out = count;
    count = 0;
    for(int j = 0; j < 4; j++)
    {
        if(!found[1][j])
        {
            for(int i = 0; i < 4; i++)
            {
                if(!found[0][i] && checked[j] == desired[i])
                {
                    count++;
                    found[0][i] = true;
                    found[1][j] = true;
                    break;
                }
            }
        }
    }

    *well_colored_out = count;
}

bool check(const int desired[4], const int checked[4], int well_placed, int well_colored)
{
    int well_placed_tmp, well_colored_tmp;
    get_combination_status(desired, checked, &well_placed_tmp, &well_colored_tmp);

    return well_placed == well_placed_tmp && well_colored == well_colored_tmp;
}
