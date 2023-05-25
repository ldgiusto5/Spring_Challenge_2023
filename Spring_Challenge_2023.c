#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    // amount of hexagonal cells in this map
    int number_of_cells;
    scanf("%d", &number_of_cells);
    // 0 for empty, 1 for eggs, 2 for crystal
    int type[number_of_cells];
    // the initial amount of eggs/crystals on this cell
    int initial_resources[number_of_cells];
    // the index of the neighbouring cell for each direction
    int neigh_0;
    int neigh_1;
    int neigh_2;
    int neigh_3;
    int neigh_4;
    int neigh_5;
    for (int i = 0; i < number_of_cells; i++) {
        scanf("%d%d%d%d%d%d%d%d", &type[i], &initial_resources[i], &neigh_0, &neigh_1, &neigh_2, &neigh_3, &neigh_4, &neigh_5);
    }
    //array de index con cristales
    int index_cristals[number_of_cells];
    int number_of_bases;
    scanf("%d", &number_of_bases);
    int my_base_index;
    for (int i = 0; i < number_of_bases; i++) {
        scanf("%d", &my_base_index);
    }
    int opp_base_index;
    for (int i = 0; i < number_of_bases; i++) {
        scanf("%d", &opp_base_index);
    }
    int i = 0;
    int j = 0;
    while (i < number_of_cells)
    {
        if (type[i] == 2)
        {
            index_cristals[j] = i;
            j++;
        }
        i++;
    }
    int p = 0;
    // game loop
    while (1) {
        // the current amount of eggs/crystals on this cell
        int resources[number_of_cells];
        // the amount of your ants on this cell
        int my_ants[number_of_cells];
        // the amount of opponent ants on this cell
        int opp_ants[number_of_cells];
        for (int i = 0; i < number_of_cells; i++) {
            scanf("%d%d%d", &resources[i], &my_ants[i], &opp_ants[i]);
        }

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");


        // WAIT | LINE <sourceIdx> <targetIdx> <strength> | BEACON <cellIdx> <strength> | MESSAGE <text>
        if (resources[index_cristals[p]] == 0 || resources[index_cristals[j]] == 0)
        {
            if (resources[index_cristals[p]] == 0)
            {
                p++;
            }
            if (resources[index_cristals[j]] == 0)
            {
                j--;
            }
        }
        printf("LINE %i %i 2; LINE %i %i 2\n", my_base_index, index_cristals[p], my_base_index, index_cristals[j]);

    }

    return 0;
}