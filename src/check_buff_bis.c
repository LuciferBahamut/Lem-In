/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** check the buffer
*/

#include <stdlib.h>
#include "lemin.h"

static int check_command(char **str)
{
    int nb = 0;

    for (int i = 0; str[i] != NULL; i++) {
        if (my_strcmp(str[i], "##start")) {
            if (my_strcmp(str[i + 1], "##end"))
                return (TRUE);
            nb++;
        }
        if (my_strcmp(str[i], "##end")) {
            if (my_strcmp(str[i + 1], "##start"))
                return (TRUE);
            nb++;
        }
    }
    if (nb != 2)
        return (TRUE);
    return (FALSE);
}

static int check_tunnels(char **str)
{
    int nbr = 0;

    for (int i = 0; str[i] != NULL; i++)
        for (int j = 0; str[i][j] != '\0'; j++)
            if (str[i][j] == '-')
                nbr++;
    if (nbr == 0)
        return (TRUE);
    return (FALSE);
}

int check_buff_bis(char **str)
{
    if (check_command(str))
        return (TRUE);
    if (check_tunnels(str))
        return (TRUE);
    return (FALSE);
}
