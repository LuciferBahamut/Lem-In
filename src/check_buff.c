/*
** EPITECH PROJECT, 2020
** lem_in
** File description:
** check the buffer
*/

#include <stdlib.h>
#include "lemin.h"

static int check_nbr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            continue;
        else
            return (TRUE);
    }
    return (FALSE);
}

static char **check_wrong_cmd(char **str)
{
    for (int i = 0; str[i] != NULL; i++)
        if (str[i][0] == '#' && multi_cmp(str[i]) == FALSE) {
            str[i] = NULL;
            break;
        }
    return (str);
}

static char **check_other_lines(char **str)
{
    int stop = 0;

    for (int i = 0; str[i] != NULL; i++) {
        if (str[i][0] == '#')
            continue;
        for (int j = 0; str[i][j]; j++) {
            if (str[i][j] >= '0' && str[i][j] <= '9')
                continue;
            else if (str[i][j] == '-' || str[i][j] == ' ')
                continue;
            else {
                str[i] = NULL;
                stop++;
                break;
            }
        }
        if (stop != 0)
            break;
    }
    return (str);
}

char **check_buff(values_t *v)
{
    if (check_nbr(v->str[0]))
        return (NULL);
    if (check_start_end(v) == ERROR)
        return (NULL);
    v->str = check_wrong_cmd(v->str);
    v->str = check_other_lines(v->str);
    if (check_buff_bis(v->str))
        return (NULL);
    return (v->str);
}
