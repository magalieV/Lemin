/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** __DESCRIPTION__
*/

#include "lemin_hd.h"

void destroy_double_tab(char **tab)
{
    if (!tab)
        return;
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}
