/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** __DESCRIPTION__
*/

#include "lemin_hd.h"

static int found_error(char **tab, bool *bol)
{
    char **str = NULL;

    if (my_getnbr(tab[0]) <= 0)
        return (84);
    if (!found_start_end(tab, true)) {
        (*bol) = true;
        return (0);
    }
    if (!found_start_end(tab, false)) {
        (*bol) = true;
        return (0);
    }
    return (0);
}

int handling(char ***str, bool *bol)
{
    char **tab = read_doub_file(NULL);

    if (!tab)
        return (84);
    tab = remove_solo_hash(tab);
    if (!tab)
        return (84);
    tab = tab_retry(tab);
    if (!tab)
        return (84);
    if (found_error(tab, bol) == 84)
        return (84);
    try(tab);
    (*str) = tab;
    return (0);
}

int nb_of_way(int **tab, int ant)
{
    int way = 0;

    for (int i = 0; tab[i]; i++) {
        if ((ant - tab[i][0]) > 0)
            way++;
    }
    if (way == 0)
        way = 1;
    return (way);
}
