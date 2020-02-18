/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** __DESCRIPTION__
*/

#include "lemin_hd.h"

int my_tab_len(int *tab)
{
    int i = 0;

    while (tab && tab[i] != -1)
        i += 1;
    return (i);
}

int *add_to_history(int *history, int id)
{
    int len = my_tab_len(history);
    int *new = malloc(sizeof(int) * (len + 2));
    int i = 0;

    for (i = 0; i < len; i++) {
        new[i] = history[i];
    }
    new[i++] = id;
    new[i++] = -1;
    return (new);
}

bool check_history(int name, int *history)
{
    for (int i = 0; history[i] != -1; i++) {
        if (history[i] == name)
            return (true);
    }
    return (false);
}

bool move_node(link_t *node, util_t *util, moove_t moove,
    void (*ptr)(link_t *, util_t *, int *, int))
{
    bool recup = false;
    int nb = 0;

    (*ptr)(node, util, moove.history, moove.depth);
    nb = found_arival(node, util);
    if (nb != 0)
        return (nb == 1 ? true : false);
    moove.history = add_to_history(moove.history, node->id);
    if (if_start_tunnel(node, util, moove, ptr))
        return (true);
    if (moove_on_tunnel(node, util, moove, ptr))
        return (true);
    return (false);
}
