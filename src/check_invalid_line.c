/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** check_invalid_line
*/

#include <stdlib.h>
#include "lemin.h"

static char *my_split_special(char *str)
{
    int i = 0;
    char *temp;

    for (i = 0; str[i] != ' '; i++);
    temp = malloc(sizeof(char) * i + 2);
    for (i = 0; str[i] != ' '; i++)
        temp[i] = str[i];
    temp[i] = '\0';
    return (temp);
}

static char **split_alloc_tunnel(char **str, int i)
{
    char **split2;
    int j = 0;

    for (int k = i; str[k] != NULL; k++, j++);
    j *= 2;
    split2 = malloc(sizeof(char *) * (j + 1));
    for (int k = 0; k != j; k++) {
        split2[k] = malloc(sizeof(char) * my_strlen(str[i]));
        if (k % 2 == 1)
            i++;
    }
    return (split2);
}

static char **split_tunnel(char **str, int i, int n)
{
    char **split2 = split_alloc_tunnel(str, i);

    for (int k = i; str[k] != NULL; k++) {
        for (int m = 0, j = 0; str[k][m] != '\0'; m++, j++) {
            if (str[k][m] == '-') {
                split2[n][j] = '\0';
                n++;
                m++;
                j = 0;
            }
            if (str[k][m + 1] == '\0') {
                split2[n][j] = str[k][m];
                split2[n][j + 1] = '\0';
                n++;
                break;
            }
            split2[n][j] = str[k][m];
        }
    }
    split2[n] = NULL;
    return (split2);
}

static char **cmp_str(char **str, char **split, int i)
{
    char **split2 = split_tunnel(str, i, 0);
    int *tab_tunnel;
    int *tab_room;

    tab_tunnel = atoi_parsing(split2);
    tab_room = atoi_parsing(split);
    for (int k = 0; split2[k] != NULL; k++) {
        if (k % 2 == 1)
            i++;
        if (tab_tunnel[k] < 0) {
            str = NULL;
            break;
        }
        if (cmp_value(tab_tunnel[k], tab_room, split)) {
            str[i] = NULL;
            break;
        }
    }
    free(tab_tunnel);
    free(tab_room);
    return (str);
}

char **check_invalid_line(char **str)
{
    int i = 1;
    int j = 0;
    char **split;

    if (str[i][0] == '#')
        i = 2;
    for (; check_tunnel(str[i]) != TRUE; i++);
    split = malloc(sizeof(char *) * i);
    if (str[1][0] == '#')
        i = 2;
    else
        i = 1;
    for (j = 0; check_tunnel(str[i]) != TRUE; i++, j++) {
        if (str[j][0] == '#' && check_tunnel(str[i + 1]) == FALSE)
            i++;
        split[j] = my_split_special(str[i]);
    }
    split[j] = NULL;
    str = cmp_str(str, split, i);
    return (str);
}
