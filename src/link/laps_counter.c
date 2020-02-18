/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** __DESCRIPTION__
*/

#include "lemin_hd.h"

void moove_start(link_t *node, info_way_t *info, int tour, int end)
{
    for (int i = 0; i < node->tunnels_size; i++) {
        if (node->tunnels[i]->taken == false
            && info->nb_start < info->total_anthill && node->way[i] != 10000) {
            info->nb_start += 1;
            node->tunnels[i]->nb_anthill = info->nb_start;
            display_moove(node->tunnels[i]);
            node->tunnels[i]->name_last = my_strcpy_my(node->name);
            if (node->tunnels[i]->id == end)
                info->nb_end++;
            else
                node->tunnels[i]->taken = true;
            node->tunnels[i]->tour = tour;
        }
    }
}

int found_last_path(int *history, link_t *node)
{
    int len = my_tab_len(history) - 1;
    int id = 0;

    id = history[len];
    for (int i = 0; i < node->tunnels_size; i++) {
        if (node->tunnels[i]->id == id)
            return (i);
    }
    return (-1);
}

void count_lapss(link_t *node, util_t *util, int *history, int depth)
{
    int len = 0;

    if (depth == 0) {
        for (int i = 0; i < node->tunnels_size; i++)
            node->way[i] = 0;
    } else if ((len = found_last_path(history, node)) != -1) {
        if (node->way[len] > depth)
            node->way[len] = depth;
    }
}
