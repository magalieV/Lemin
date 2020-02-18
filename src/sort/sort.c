/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** __DESCRIPTION__
*/

#include "lemin_hd.h"

static bool init_way(char **tab, info_way_t *info)
{
    (*info).nb_room = found_size_list(tab);
    if (info->nb_room == -1)
        return (false);
    (*info).name_start = found_start_end(tab, true);
    info->nb_start = 0;
    info->nb_end = 0;
    info->start = 0;
    info->end = 0;
    info->security = 0;
    (*info).name_end = found_start_end(tab, false);
    if (!info->name_start || !info->name_end)
        return (false);
    (*info).total_anthill = my_getnbr(tab[0]);
    info->arival = 0;
    return (true);
}

void loop_moove(link_t *list, util_t util, info_way_t info, moove_t moove)
{
    int security = 0;

    while (util.info.nb_end != info.total_anthill && security < 60) {
        util.info.arival = 0;
        util.info.security = 0;
        move_node(list, &util, moove, &moove_ant_position);
        util.turn += 1;
        my_putstr("\n");
        security++;
    }
}

static util_t ini_util(info_way_t info, char **room, char **tunnels)
{
    util_t util = {0};
    char **tmp = NULL;
    char **tmp2 = NULL;
    int i = 0;
    bool choice = false;
    int j = 0;

    tmp = my_str_to_word_array_tab(info.name_start, false);
    tmp2 = my_str_to_word_array_tab(info.name_end, false);
    1 ? util.depth = 0, util.turn = 0 : 0;
    util.start_id = info.start_id;
    util.end_id = info.end_id;
    util.choice = false;
    util.info = info;
    for (i = 0; tunnels[i]; i++);
    for (j = 0; room[j]; j++);
    if (i > j && (i / j >= 4)) {
        util.choice = true;
        util.nb = 1;
    }
    return (util);
}

int start_algo(void)
{
    char **tab = NULL;
    char **room = NULL;
    char **tunnels = NULL;
    info_way_t info = {0};
    link_t *list = NULL;
    bool bol = false;
    util_t util = {0};
    moove_t moove = {0};

    if ((handling(&tab, &bol) == 84) || (bol == true) ||
        (init_way(tab, &info) == false) || ((room = remove_info(tab)) == NULL))
        return (84);
    if ((tunnels = found_tunnels(tab)) == NULL)
        return (84);
    1 ? moove.history = NULL, moove.depth = 0 : 0;
    list = create_tree(room, &info, tunnels);
    util = ini_util(info, room, tunnels);
    move_node(list, &util, moove, &count_lapss);
    loop_moove(list, util, info, moove);
    1 ? destroy_double_tab(tab), destroy_double_tab(room) : 0;
    destroy_double_tab(tunnels);
}
