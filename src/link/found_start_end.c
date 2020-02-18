/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** __DESCRIPTION__
*/

#include "lemin_hd.h"

bool string_search(char const *str, int j, bool word)
{
    char *start = "##start";
    char *end = "##end";

    if (word) {
        for (int i = 0; start[i]; i++) {
            if (start[i] != str[j++])
                return (false);
            }
        return (true);
    } else if (!word) {
        for (int i = 0; end[i]; i++)
            if (end[i] != str[j++])
                return (false);
        return (true);
    }
    return (false);
}

char *found_start_end(char **tab, bool bol)
{
    if (!tab)
        return (NULL);
    for (int i = 0; tab[i]; i++) {
        for (int j = 0; tab[i][j]; j++) {
            if (tab[i][j] == '#' && string_search(tab[i], j, bol)) {
                return (tab[i + 1]);
            }
        }
    }
    return (NULL);
}

char **remove_no_tunnels(char **tab)
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
        if (i != 0 && size == 1)
            new[k++] = my_strcpy_my(tab[i]);
    }
    new[k] = 0;
    return (new);
}

char **found_tunnels(char **tab)
{
    char **tmp = NULL;

    if ((tmp = remove_no_number(tab)) == NULL)
        return (NULL);
    if ((tmp = remove_no_tunnels(tmp)) == NULL)
        return (NULL);
    return (tmp);
}
