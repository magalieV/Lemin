/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** __DESCRIPTION__
*/

#include "lemin_hd.h"

char *modif_tab(char *str)
{
    char *new = NULL;
    int size = 0;
    int i = 0;

    for (size = 0; str[size]; size++);
    if ((new = malloc(sizeof(char) * (size + 1))) == NULL)
        return (NULL);
    if (!new)
        return (NULL);
    for (i = 0; str[i]; i++)
        if (str[i] != '#')
            new[i] = str[i];
        else
            break;
    if (i != 0)
        new[i] = '\0';
    free(str);
    return (new);
}

char *my_strcpy_my(char *copy)
{
    char *new = NULL;
    int size = 0;
    int i = 0;

    if (!copy)
        return (NULL);
    for (size = 0; copy[size]; size++);
    if ((new = malloc(sizeof(char) * (size + 1))) == NULL)
        return (NULL);
    for (i = 0; copy[i]; i++)
        new[i] = copy[i];
    new[i] = '\0';
    return (new);
}

char **tab_retry(char **tab)
{
    char **str = NULL;
    int size = 0;
    int i = 0;
    int k = 0;

    for (size = 0; tab[size]; size++);
    if ((str = malloc(sizeof(char *) * (size + 1))) == NULL)
        return (NULL);
    for (i = 0; tab[i]; i++) {
        if (tab[i][0] && tab[i][0] != '\0')
            if ((str[k++] = my_strcpy_my(tab[i])) == NULL)
                return (NULL);
    }
    str[k] = 0;
    destroy_double_tab(tab);
    return (str);
}

int check_hash(char **tab, int i, int j)
{
    if (tab[i][j] == '#' && tab[i][j + 1] && tab[i][j + 1] != '#') {
        if ((tab[i] = modif_tab(tab[i])) == NULL)
            return (1);
        return (2);
    } else if (tab[i][j] == '#' && tab[i][j + 1]
    && tab[i][j + 1] == '#')
        return (2);
    return (0);
}

char **remove_solo_hash(char **tab)
{
    char *str = NULL;
    int i = 0;
    int value = 0;

    for (i = 0; tab[i]; i++) {
        for (int j = 0; tab[i][j]; j++) {
            value = check_hash(tab, i, j);
            if (value == 2)
                break;
            else if (value == 1)
                return (NULL);
        }
    }
    return (tab);
}
