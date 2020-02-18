/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** __DESCRIPTION__
*/

#include "lemin_hd.h"

int found_tab_len(char **str)
{
    int i = 0;

    if (!str)
        return (0);
    for (i = 0; str[i]; i++);
    return (i);
}

int found_end_list(link_t **tmp, info_way_t info)
{
    int i = 0;
    char **tmp_string = my_str_to_word_array_tab(info.name_end, false);

    for (i = 0; tmp[i]; i++) {
        if (!my_strncmp(tmp[i]->name, tmp_string[0]))
            return (i);
    }
    return (0);
}

int found_start_list(link_t **tmp, info_way_t info)
{
    int i = 0;
    char **tmp_string = my_str_to_word_array_tab(info.name_start, false);

    for (i = 0; tmp[i]; i++) {
        if (!my_strncmp(tmp[i]->name, tmp_string[0]))
            return (i);
    }
    return (0);
}

link_t *add_node(link_t *begin, char *name, int nb, int id)
{
    link_t *tree = malloc(sizeof(link_t));

    if (!tree)
        return (NULL);
    tree->name = my_strcpy_my(name);
    tree->taken = false;
    tree->id = id;
    tree->name_last = NULL;
    tree->last_id = -1;
    tree->open = true;
    tree->pass = false;
    tree->nb_anthill = 0;
    tree->tour = -1;
    tree->way = malloc(sizeof(unsigned int) * (nb + 1));
    for (int i = 0; i < nb; i++)
        tree->way[i] = 10000;
    tree->tunnels_size = 0;
    tree->tunnels = malloc(sizeof(link_t) * (nb + 1));
    tree->prev = NULL;
    return (tree);
}

void connect_link(link_t *link1, link_t *link2)
{
    int size = 0;

    if (!link1 || !link2)
        return;
    size = link1->tunnels_size;
    link1->tunnels[size] = link2;
    link1->tunnels_size += 1;
}
