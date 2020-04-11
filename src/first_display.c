/*
** EPITECH PROJECT, 2020
** lem-in
** File description:
** first display
*/

#include <stdlib.h>
#include "lemin.h"

static int multi_cmp(char *str)
{
    if (my_strcmp(str, "##start"))
        return (TRUE);
    if (my_strcmp(str, "##end"))
        return (TRUE);
    return (FALSE);
}

static void after_display(values_t *v, int i)
{
    my_putstr("#tunnels\n");
    for (; i != v->lines; i++) {
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
        if (v->str[i][0] == '#')
            i++;
        for (int j = 0; v->str[i][j] != '\0'; j++)
            if (v->str[i][j] == '#')
                v->str[i][j] = '\0';
    }
}

void first_display(values_t *v)
{
    int i = 1;

    my_putstr("#number_of_ants\n");
    my_putstr(v->str[0]);
    my_putchar('\n');
    my_putstr("#rooms\n");
    check_value(v);
    for (; v->str[i][1] != '-'; i++) {
        if (v->str[i][0] == '#')
            if (multi_cmp(v->str[i]) == FALSE)
                i++;
        my_putstr(v->str[i]);
        my_putchar('\n');
    }
    after_display(v, i);
}
