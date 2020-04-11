/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** fill_struct
*/

#include <stdlib.h>
#include "lemin.h"

void fill_rooms(anthill_t *ant, values_t *v, int i, int k)
{
    int j = 0;

    for (int m = k; v->str[m][1] != '-'; j++, m++) {
        if (v->str[k][0] == '#')
            m++;
        ant->rooms[j] = malloc(sizeof(char) * my_strlen(v->str[m]));
    }
    for (j = 0; v->str[k][1] != '-'; j++, k++) {
        if (v->str[k][0] == '#')
            k++;
        for (int m = 0; v->str[k][m] != '\0'; m++)
            ant->rooms[j][m] = v->str[k][m];
    }
    ant->rooms[j] = NULL;
}
