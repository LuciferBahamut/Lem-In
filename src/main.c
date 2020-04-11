/*
** EPITECH PROJECT, 2020
** lem-in
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "lemin.h"

static void free_buff(values_t *v)
{
    for (int i = 0; i != v->lines; i++)
        free(v->str[i]);
    free(v->str);
    free(v);
}

int main(int ac, char **av)
{
    values_t *v = malloc(sizeof(values_t));

    if (v == NULL)
        return (ERROR);
    v->ant = malloc(sizeof(anthill_t));
    if (v->ant == NULL)
        return (ERROR);
    if (ac != 1 || av[0] == NULL)
        return (write_error(STR_ERROR_ARG));
    v->str = read_file(v);
    first_display(v);
    fill_struct_for_algo(v);
    free_buff(v);
    return (SUCCESS);
}
