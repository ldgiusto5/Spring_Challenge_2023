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
    int neigh[number_of_cells][6];
    int neigh_0[number_of_cells];
    int neigh_1[number_of_cells];
    int neigh_2[number_of_cells];
    int neigh_3[number_of_cells];
    int neigh_4[number_of_cells];
    int neigh_5[number_of_cells];
    for (int i = 0; i < number_of_cells; i++) {
        scanf("%d%d%d%d%d%d%d%d", &type[i], &initial_resources[i], &neigh_0[i], &neigh_1[i], &neigh_2[i], &neigh_3[i], &neigh_4[i], &neigh_5[i]);
        neigh[i][0] = neigh_0[i];
        neigh[i][1] = neigh_1[i];
        neigh[i][2] = neigh_2[i];
        neigh[i][3] = neigh_3[i];
        neigh[i][4] = neigh_4[i];
        neigh[i][5] = neigh_5[i];
    }
    
    //array de index con cristales
    int index_cristals[number_of_cells];
    //array de index con cristales
    int index_eggs[number_of_cells];
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
    int j = -1;
    int x = -1;
    while (i < number_of_cells)
    {
        if (type[i] == 2)
        {
            index_cristals[j + 1] = i;
            j++;
        }
        else if (type[i] == 1)
        {
            index_eggs[x + 1] = i;
            x++;
        }
        i++;
    }
    int p = 0;
    i = 0;
    j = 0;
    x = 0;
    //  composicion -> my_rank[lista][0] (nombre) -- my_rank[lista][1] (rango) -- my_rank[lista][2] (tipo)(tipo3 = NULL)
    int my_rank[number_of_cells][3];
    //inicializo todo a NULL
    for (int i = 0; i < number_of_cells; i++)
    {
        my_rank[i][0] = -2;
        my_rank[i][1] = -2;
        my_rank[i][2] = -2;
    }
    //inicializo la posicion de la base y el rango
    my_rank[0][0] = my_base_index;
    my_rank[0][1] = 0;
    my_rank[0][2] = 0;
    // y es para buscar si ya lo tengo en la lista
    int flag = 0;
    // j lo utilizo para ir saltando de rango
    for (int j = 0; j < (number_of_cells/2); j++) //rango actual
    {
        for (int i = 0; i < number_of_cells; i++)
        {
            if(my_rank[i][1] == j)
            {
                for (int x = 0; x < 6; x++)
                {
                    if (neigh[my_rank[i][0]][x] != -1)
                    {
                        for (int y = 0; y < number_of_cells; y++)
                        {
                            if (neigh[my_rank[i][0]][x] == my_rank[y][0]) //comparo nombres por si ya lo tengo
                            {
                                flag = 1;
                            }
                        }
                        for (int k = 0; k < number_of_cells; k++)
                        {
                            if (flag == 0 && my_rank[k][0] == -2)
                            {
                                my_rank[k][0] = neigh[my_rank[i][0]][x];
                                my_rank[k][1] = j + 1;
                                my_rank[k][2] = type[neigh[my_rank[i][0]][x]];
                                flag = 1;
                            }
                        }
                    }
                    flag = 0;
                }
            }
        }
    }
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
        /*
        if (resources[index_cristals[p]] == 0)
        {
            p++;
        }
        if (resources[index_cristals[j]] == 0)
        {
            j--;
        }
        if (resources[index_eggs[x]] == 0)
        {
            x--;
        }
        */
        while ((my_rank[x][2] != 1) || resources[my_rank[x][0]] == 0)
        {
            x++;
        }
        printf("LINE %i %i 2 \n", my_rank[0][0], my_rank[x][0]);
        printf("LINE %i %i 2 \n", my_rank[0][0], my_rank[x + 1][0]);

        //printf("BEACON %i 1; BEACON %i 1; BEACON %i 1; BEACON %i 1; BEACON %i 1; BEACON %i 1; BEACON %i 1; BEACON %i 1\n", my_rank[0][0], my_rank[1][0], my_rank[2][0], my_rank[3][0], my_rank[4][0], my_rank[5][0], my_rank[6][0], my_rank[7][0]);
    }

    return 0;
}