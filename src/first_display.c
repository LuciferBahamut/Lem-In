/*
** EPITECH PROJECT, 2020
** lem-in
** File description:
** first display
*/

#include <stdlib.h>
#include "lemin.h"

static void after_display(values_t *v, int i)
{
    my_putstr("#tunnels\n");
    for (; v->str[i] != NULL; i++) {
        if (v->str[i][0] == '#')
            if (multi_cmp(v->str[i]) == FALSE)
                i++;
        my_putstr(v->str[i]);
        my_putchar('\n');
    }
    my_putstr("#move\n");
}

static void check_value(values_t *v)
{
    for (int i = 0; i != v->lines; i++) {
        if (v->str[i][0] == '#' && v->str[i][1] != '#')
            i++;
        for (int j = 0; v->str[i][j] != '\0'; j++)
            if (v->str[i][j] == '#' && j != 0 && j != 1)
                v->str[i][j] = '\0';
    }
    v->str[v->lines] = NULL;
}

static int del_com_bis(values_t *v, int i, int j)
{
    if (multi_cmp(v->str[i]) == FALSE) {
        v->str[i] = NULL;
        for (j = i; j != v->lines - 1; j++)
            v->str[j] = v->str[j + 1];
        v->str[j] = NULL;
        i--;
    }
    return (i);
}

static void del_com(values_t *v)
{
    int j = 0;

    for (int i = 0; v->str[i] != NULL; i++)
        if (v->str[i][0] == '#' && v->str[i][1] != '#')
            i = del_com_bis(v, i, j);
}

int first_display(values_t *v)
{
    int i = 1;

    check_value(v);
    del_com(v);
    if ((v->str = check_buff(v)) == NULL)
        return (ERROR);
    my_putstr("#number_of_ants\n");
    my_putstr(v->str[0]);
    my_putchar('\n');
    my_putstr("#rooms\n");
    for (; v->str[i][1] != '-'; i++) {
        my_putstr(v->str[i]);
        my_putchar('\n');
    }
    after_display(v, i);
    return (SUCCESS);
}
