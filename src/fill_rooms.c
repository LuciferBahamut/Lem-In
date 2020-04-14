/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** fill_struct
*/

#include <stdlib.h>
#include "lemin.h"

static int del_cmd_bis(values_t *v, int i, int j)
{
    v->str[i] = NULL;
    for (j = i; j != v->lines - 1; j++)
        v->str[j] = v->str[j + 1];
    v->str[j] = NULL;
    i--;
    return (i);
}

static void del_cmd(values_t *v)
{
    int j = 0;
    for (int i = 0; v->str[i] != NULL; i++)
        if (v->str[i][0] == '#')
            i = del_cmd_bis(v, i, j);
}

void fill_rooms(anthill_t *ant, values_t *v)
{
    int j = 0;
    int k = 1;

    del_cmd(v);
    for (int m = 1; check_tunnel(v->str[m]) != TRUE; j++, m++)
        ant->rooms[j] = malloc(sizeof(char) * my_strlen(v->str[m]));
    for (j = 0; check_tunnel(v->str[k]) != TRUE; j++, k++)
        for (int m = 0; v->str[k][m] != '\0'; m++)
            ant->rooms[j][m] = v->str[k][m];
    ant->rooms[j] = NULL;
}
