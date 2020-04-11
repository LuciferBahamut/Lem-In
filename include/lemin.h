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
typedef struct values_s
{
    int lines;
    char **str;
    // valeurs que l'on a dans le buffer apres la gest d'erreur
} values_t;

//////////////////////
//  OPEN AND READ   //
//////////////////////
char **read_file(values_t *v);

//////////////////////
//  DISPLAY VALUES  //
//////////////////////
void first_display(values_t *v);

//////////////////////
//  UTIL FUNCTIONS  //
//////////////////////
void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcat(char *dest, char *src);
int write_error(char const *str);
int my_strcmp(char const *str1, char const *str2);

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
