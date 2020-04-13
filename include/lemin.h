/*
** EPITECH PROJECT, 2020
** lem-in
** File description:
** .h
*/

#ifndef _LEMIN_H_
#define _LEMIN_H_

//////////////////////
//    STRUCTURES    //
//////////////////////
typedef struct anthill_s
{
    int nb_ant;
    char *start;
    char *end;
    char **rooms;
    char **tunnels;
} anthill_t;

typedef struct values_s
{
    int lines;
    char **str;
    anthill_t *ant;
} values_t;

//////////////////////
//  OPEN AND READ   //
//////////////////////
char **read_file(values_t *v);

//////////////////////
//  DISPLAY VALUES  //
//////////////////////
int first_display(values_t *v);
void fill_struct_for_algo(values_t *v);
void fill_rooms(anthill_t *ant, values_t *v, int k);

//////////////////////
//  ERROR HANDLING  //
//////////////////////
int multi_cmp(char *str);
char **check_buff(values_t *v);

//////////////////////
//  UTIL FUNCTIONS  //
//////////////////////
void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcat(char *dest, char *src);
int write_error(char const *str);
int my_strcmp(char const *str1, char const *str2);
int my_atoi(char const *str);

//////////////////////
//  ERROR MESSAGES  //
//////////////////////
static const char STR_ERROR_ARG[] = "this program takes no arguments\n";

//////////////////////
//  RETURN VALUES   //
//////////////////////
static const int ERROR = 84;
static const int SUCCESS = 0;
static const int TRUE = 1;
static const int FALSE = 0;

#endif
