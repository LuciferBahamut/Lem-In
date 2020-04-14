/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** fill struct for algo
*/

#include <stdlib.h>
#include "lemin.h"

static int recup_pos(values_t *v, char *str)
{
    int i = 0;

    for (; v->str[i] != NULL; i++)
        if (my_strcmp(v->str[i], str))
            break;
    i = i + 1;
    return (i);
}

static void fill_start(anthill_t *ant, char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        ant->start[i] = str[i];
    ant->start[i] = '\0';
}

static void fill_end(anthill_t *ant, char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        ant->end[i] = str[i];
    ant->end[i] = '\0';
}

static void fill_tunnels(anthill_t *ant, int j, values_t *v)
{
    int k = 0;

    for (k = 0; v->str[j] != NULL; j++, k++) {
        if (v->str[j][0] == '#')
            j++;
        for (int i = 0; v->str[j][i] != '\0'; i++)
            ant->tunnels[k][i] = v->str[j][i];
    }
    ant->tunnels[k] = NULL;
}

void fill_struct_for_algo(values_t *v)
{
    int i = recup_pos(v, "##start");
    int j = recup_pos(v, "##end");

    v->ant->nb_ant = my_atoi(v->str[0]);
    v->ant->start = malloc(sizeof(char) * (my_strlen(v->str[i]) + 1));
    fill_start(v->ant, v->str[i]);
    v->ant->end = malloc(sizeof(char) * (my_strlen(v->str[j]) + 1));
    fill_end(v->ant, v->str[j]);
    for (; check_tunnel(v->str[j]) != TRUE; j++);
    i = 0;
    for (int k = j; v->str[k] != NULL; i++, k++);
    v->ant->tunnels = malloc(sizeof(char *) * (i + 1));
    for (int m = 0, k = j; v->str[k] != NULL; m++, k++)
        v->ant->tunnels[m] = malloc(sizeof(char) * (my_strlen(v->str[k]) + 1));
    fill_tunnels(v->ant, j, v);
    i = 0;
    for (int k = 1; check_tunnel(v->str[k]) != TRUE; i++, k++);
    v->ant->rooms = malloc(sizeof(char *) * (i + 1));
    fill_rooms(v->ant, v);
}
