/*
** EPITECH PROJECT, 2020
** lem-in
** File description:
** check_start_end
*/

#include <stdlib.h>
#include "lemin.h"

int check_start_end(values_t *v)
{
    int i = 0;

    while (v->str[i] != NULL)
        i++;
    i--;
    if (my_strcmp(v->str[i], "##start"))
        return (ERROR);
    else if (my_strcmp(v->str[i], "##end"))
        return (ERROR);
    else
        return (SUCCESS);
}
