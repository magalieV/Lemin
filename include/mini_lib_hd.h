/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** __DESCRIPTION__
*/

#ifndef MINI_LIB_HEADER
#define MINI_LIB_HEADER

    //GET_NEXT_LINE
char *get_next_line(int);

    //INI_GAME_BOARD
char **read_doub_file(char const *);

    //LIB_FUNCTION
int my_put_nbr(int);
void my_putstr(char const *);
void my_putchar(char);
int my_strncmp(char const *, char const *);
int my_getnbr(char const *);
int my_strlen(char const *str);

    //MY_STR_TO_WORD_ARRAY
char **my_str_to_word_array(char const *);

    //PRINT_FUNCTION
char *modif_tab(char *);
char *my_strcpy_my(char *);
char **tab_retry(char **);
char **remove_solo_hash(char **);

    //TO_TAB_LINK
char **my_str_to_word_array_tab(char const *, bool);
int my_tab_len(int *tab);

#endif
