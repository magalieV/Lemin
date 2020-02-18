/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** __DESCRIPTION__
*/

#include "lemin_hd.h"

char **remove_no_number(char **tab)
{
    int size = 0;
    char **new = NULL;
    int k = 0;

    for (size = 0; tab[size]; size++);
    if ((new = malloc(sizeof(char *) * (size + 1))) == NULL)
        return (NULL);
    for (int i = 0; tab[i]; i++) {
        if (tab[i][0] <= '9' && tab[i][0] >= '0')
            new[k++] = my_strcpy_my(tab[i]);
            if (new[k - 1] == NULL)
                return (NULL);
    }
    new[k] = 0;
    return (new);
}

char **remove_no_room(char **tab)
{
    int size = 0;
    char **new = NULL;
    char **tmp = NULL;
    int k = 0;

    for (size = 0; tab[size]; size++);
    if ((new = malloc(sizeof(char *) * (size + 1))) == NULL)
        return (NULL);
    for (int i = 0; tab[i]; i++) {
        if ((tmp = my_str_to_word_array_tab(tab[i], true)) == NULL)
            return (NULL);
        for (size = 0; tmp[size]; size++);
        if (size == 3)
            new[k++] = my_strcpy_my(tab[i]);
    }
    new[k] = 0;
    return (new);
}

char **remove_info(char **tab)
{
    char **ned = NULL;

    if ((ned = remove_no_number(tab)) == NULL)
        return (NULL);
    if ((ned = remove_no_room(ned)) == NULL)
        return (NULL);
    return (ned);
}

int found_size_list(char **tab)
{
    char **need = NULL;
    int nb = 0;

    if ((need = remove_info(tab)) == NULL)
        return (-1);
    for (nb = 0; need[nb]; nb++);
    destroy_double_tab(need);
    return (nb);
}
