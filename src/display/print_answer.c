/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** __DESCRIPTION__
*/

#include "lemin_hd.h"

static int search_after_tunnel(char **tab, int i)
{
    static int bol = 0;

    for (int j = 0; tab[i][j]; j++) {
        if (tab[i][j] == '-' && bol == 0) {
            bol = 1;
            return (1);
        }
    }
    return (0);
}

int try(char **tab)
{
    my_putstr("#number_of_ants\n");
    my_putstr(tab[0]), my_putstr("\n");
    my_putstr("#rooms\n");
    for (int i = 1; tab[i]; i++) {
        if (search_after_tunnel(tab, i))
            my_putstr("#tunnels\n");
        my_putstr(tab[i]), my_putstr("\n");
    }
    my_putstr("#moves\n");
    return (0);
}
