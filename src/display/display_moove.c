/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** __DESCRIPTION__
*/

#include "lemin_hd.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 +48);
    }
    else
        my_putchar(nb +48);
    return (0);
}

void display_moove(link_t *node)
{
    my_putstr("P");
    my_put_nbr(node->nb_anthill);
    my_putstr("-");
    my_putstr(node->name);
    my_putstr(" ");
}

int found_arival(link_t *node, util_t *util)
{
    if (node->id == util->start_id) {
        if (util->choice) {
            util->info.arival += 1;
            return (1);
        }
        return (2);
    }
    return (0);
}

bool if_start_tunnel(link_t *node, util_t *util, moove_t moove,
    void (*ptr)(link_t *, util_t *, int *, int))
{
    bool recup = false;

    for (int i = 0; i < node->tunnels_size; i++) {
        if (util->start_id == node->tunnels[i]->id) {
            moove.depth += 1;
            recup = move_node(node->tunnels[i], util, moove, ptr);
            if (recup)
                return (true);
        }
        if (recup && util->info.arival == util->nb)
            return (true);
    }
    return (false);
}

bool moove_on_tunnel(link_t *node, util_t *util, moove_t moove,
    void (*ptr)(link_t *, util_t *, int *, int))
{
    bool recup = false;

    for (int i = 0; i < node->tunnels_size; i++) {
        util->info.security += 1;
        if (util->info.security > 3000) {
            util->info.arival = util->nb;
            return (true);
        }
        if (!check_history(node->tunnels[i]->id, moove.history)) {
            moove.depth += 1;
            recup = move_node(node->tunnels[i], util, moove, ptr);
        }
        if (recup && node->id != util->end_id)
            return (true);
        else if (recup && node->id == util->end_id
            && util->info.arival == util->nb)
            return (true);
    }
    return (false);
}
