/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** __DESCRIPTION__
*/

#include "lemin_hd.h"

int found_low_way(link_t *node, int *laps, int end)
{
    int one = 10000;
    int two = 0;
    int save = 0;

    for (int i = 0; i < node->tunnels_size; i++) {
        two = node->way[i];
        if (node->tunnels[i]->id == end)
            return (i);
        if (two <= one && two > (*laps)) {
            one = two;
            save = i;
        }
    }
    *laps = one;
    return (save);
}

int found_len_of_low_path(link_t *node, int end_id, int start_id)
{
    int len = 0;
    int laps = 0;
    int security = 0;

    do {
        len = found_low_way(node, &laps, end_id);
        security++;
        if (node->way[len] == 10000 && end_id == node->tunnels[len]->id)
            return (len);
        else if (security > node->tunnels_size)
            return (-1);
    } while (node->tunnels[len]->taken == true
        || node->tunnels[len]->id == node->tunnels[len]->last_id
        || node->tunnels[len]->id == start_id);
    return (len);
}

void moove_ant(link_t *node, int len, int end_id, int turn)
{
    node->tunnels[len]->nb_anthill = node->nb_anthill;
    node->taken = false;
    display_moove(node->tunnels[len]);
    node->tunnels[len]->last_id = node->id;
    if (end_id != node->tunnels[len]->id) {
        node->tunnels[len]->taken = true;
        node->tunnels[len]->tour = turn;
    }
}

void moove_ant_position(link_t *node, util_t *util, int *history, int depth)
{
    int len = 0;

    if (node->tour < util->turn && node->taken == true
        && node->id != util->start_id) {
        len = found_len_of_low_path(node, util->end_id, util->start_id);
        if (len == -1)
            return;
        moove_ant(node, len, util->end_id, util->turn);
        if (util->end_id == node->tunnels[len]->id)
            util->info.nb_end += 1;
    } else if (node->id == util->start_id) {
        moove_start(node, &util->info, util->turn, util->end_id);
    }
}
