/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** check tunnel
*/

#include "lemin.h"

int check_tunnel(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '-') {
            nb++;
            break;
        }
    if (nb != 0)
        return (TRUE);
    else
        return (FALSE);
}
