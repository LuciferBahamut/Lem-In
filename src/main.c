/*
** EPITECH PROJECT, 2020
** lem-in
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "lemin.h"

static void free_buff(char **buff, values_t *v)
{
    for (int i = 0; i != v->lines; i++)
        free(buff[i]);
    free(buff);
}

int main(int ac, char **av)
{
    char **buff;
    values_t *v = malloc(sizeof(values_t));
                         
    if (v == NULL)
        return (ERROR);
    if (ac != 1 || av[0] == NULL)
        return (write_error(STR_ERROR_ARG));
    buff = read_file(v);
    free_buff(buff, v);
    return (SUCCESS);
}
