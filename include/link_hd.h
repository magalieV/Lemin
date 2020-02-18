/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** __DESCRIPTION__
*/

#ifndef LINK_LEMIN
#define LINK_LEMIN

typedef struct link {
    char *name;
    bool taken;
    int tunnels_size;
    bool open;
    bool pass;
    int tour;
    int last_id;
    char *name_last;
    int id;
    int nb_anthill;
    unsigned int *way;
    struct link *prev;
    struct link **tunnels;
} link_t;

typedef struct info_way {
    int total_anthill;
    int nb_way;
    int nb_room;
    int way_max;
    int start_id;
    int end_id;
    int security;
    int nb_start;
    int arival;
    int nb_end;
    int start;
    int tot_start;
    int end;
    char *name_start;
    char *name_end;
} info_way_t;

typedef struct util {
    unsigned depth;
    int turn;
    int start_id;
    bool choice;
    int nb;
    int end_id;
    info_way_t info;
} util_t;

typedef struct moove {
    int *history;
    int depth;
} moove_t;

    //SIZE_LIST
int found_size_list(char **);
char **remove_no_room(char **);
char **remove_no_number(char **);
char **remove_info(char **);

    //START_END
char *found_start_end(char **, bool);
bool string_search(char const *, int, bool);
char **found_tunnels(char **tab);
void count_lapss(link_t *node, util_t *util, int *history, int depth);
void moove_ant_position(link_t *node, util_t *util, int *history, int depth);

link_t *create_tree(char **room, info_way_t *info, char **tunnels);

    //LAPS_COUNTER
link_t *count_laps(link_t *link, char *start_name, char *);
//void move_node(link_t *node, util_t *, int *);
//bool move_node(link_t *node, util_t *, int *);
void moove_start(link_t *node, info_way_t *info, int tour, int end);
bool move_node(link_t *node, util_t *util, moove_t,
    void (*ptr)(link_t *, util_t *, int *, int));
void display_moove(link_t *node);
//void moove_start(link_t *node, info_way_t *info, int, char const *);
int my_strcmp(char const *sa, char const *sb);

        //CREATE_LINK
link_t *add_node(link_t *, char *, int, int);
void connect_link(link_t *, link_t *);
int found_start_list(link_t **, info_way_t);
int found_end_list(link_t **, info_way_t);
int found_tab_len(char **);

    //MOOVE
int found_arival(link_t *, util_t *);
bool if_start_tunnel(link_t *, util_t *, moove_t,
    void (*ptr)(link_t *, util_t *, int *, int));
bool moove_on_tunnel(link_t *, util_t *, moove_t,
    void (*ptr)(link_t *, util_t *, int *, int));
bool check_history(int, int *);

#endif
