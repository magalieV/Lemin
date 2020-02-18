/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** __DESCRIPTION__
*/

#include "lemin_hd.h"

int count_max(link_t **tmp, info_way_t *info)
{
    for (int i = 0; tmp[i]; i++) {
        if (!my_strncmp(tmp[i]->name, info->name_start))
            return (tmp[i]->tunnels_size);
    }
}

bool found_if_already_exist(link_t **tunnels, int i, char *one, char *two)
{
    for (int i = 0; tunnels[i]; i++) {
        if (!my_strncmp(tunnels[i]->name, one)) {
            for (int j = 0; j < tunnels[i]->tunnels_size; j++) {
                if (!my_strncmp(tunnels[i]->tunnels[j]->name, two)) {
                    return (true);
                }
            }
        }
        if (!my_strncmp(tunnels[i]->name, two)) {
            for (int j = 0; j < tunnels[i]->tunnels_size; j++) {
                if (!my_strncmp(tunnels[i]->tunnels[j]->name, one)) {
                    return (true);
                }
            }
        }
    }
    return (false);
}

void loop_c(link_t **tmp, char **tunnels_tmp, link_t **room_1,
    link_t **room_2)
{
    bool bol = false;
    bool bol_2 = false;

    for (int j = 0; tmp[j]; j++) {
        if (!bol && !my_strncmp(tmp[j]->name, tunnels_tmp[0])) {
            1 ? (*room_1) = tmp[j], bol = true : 0;
        } else if (!bol_2 && !my_strncmp(tmp[j]->name, tunnels_tmp[1])) {
            1 ? (*room_2) = tmp[j], bol_2 = true : 0;
        }
    }
}

link_t *associate_link(char **tunnels, link_t **tmp, info_way_t *info)
{
    char **tube = NULL;
    link_t **r1 = NULL;
    link_t **r2 = NULL;
    int size = found_tab_len(tunnels);
    int k = 0;
    int e = 0;
    int n = 0;

    r1 = malloc(sizeof(link_t *) * (size + 1));
    r2 = malloc(sizeof(link_t *) * (size + 1));
    for (int i = 0; tunnels[i]; i++) {
        tube = my_str_to_word_array_tab(tunnels[i], false);
        if (my_strncmp(tube[0], tube[1])
        && found_if_already_exist(tmp, i, tube[0], tube[1]) == false) {
            1 ? loop_c(tmp, tube, &r1[k], &r2[e]), destroy_double_tab(tube) : 0;
            1 ? connect_link(r1[k], r2[e]), connect_link(r2[e++], r1[k++]) : 0;
        }
    }
    n = found_end_list(tmp, (*info));
    info->way_max = count_max(tmp, info);
    return (tmp[n]);
}

link_t *create_tree(char **room, info_way_t *info, char **tunnels)
{
    link_t **tmp = malloc(sizeof(link_t *) * ((*info).nb_room + 1));
    char **room_tmp = NULL;
    link_t *final = NULL;
    int i = 0;
    link_t *end = NULL;
    char **tmp_1 = NULL;
    char **tmp_2 = NULL;

    tmp_1 = my_str_to_word_array_tab(info->name_start, false);
    tmp_2 = my_str_to_word_array_tab(info->name_end, false);
    for (i = 0; i < (*info).nb_room; i++) {
        room_tmp = my_str_to_word_array_tab(room[i], false);
        if (!my_strncmp(room_tmp[0], tmp_1[0]))
            info->start_id = i;
        if (!my_strncmp(room_tmp[0], tmp_2[0]))
            info->end_id = i;
        tmp[i] = add_node(tmp[i], room_tmp[0], (*info).nb_room, i);
        destroy_double_tab(room_tmp);
    }
    1 ? tmp[i] = end, final = associate_link(tunnels, tmp, info) :0;
    return (final);
}
