/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** __DESCRIPTION__
*/

#include "lemin_hd.h"

static int if_alphnum_tab(char const *str, int i, bool bol)
{
    if (str[i] >= '0' && str[i] <= '9')
        return (1);
    if (bol && str[i] == '-')
        return (1);
    return (0);
}

static int alloc_mem_tab(char const *str, bool bol)
{
    int i = 0;
    int k = 0;

    while (str[i]) {
        if (if_alphnum_tab(str, i, bol) && !if_alphnum_tab(str, i + 1, bol))
            k++;
        i++;
    }
    return (k);
}

char **my_str_to_word_array_tab(char const *str, bool bol)
{
    char **dest = NULL;
    int i = 0;
    int g = 0;
    int n = 0;

    if ((dest = malloc(sizeof(char *) * (alloc_mem_tab(str,
        bol) + 1) + 1)) == NULL)
        return (NULL);
    while (str[g]) {
        if (!if_alphnum_tab(str, g, bol))
            g++;
        for (n = g; if_alphnum_tab(str, n, bol); n++);
        dest[i] = (char *)malloc((n - g) + 2);
        dest[i][0] = 0;
        for (n = 0; if_alphnum_tab(str, g, bol); n++)
            dest[i][n] = str[g++];
        dest[i][n] = '\0';
        (dest[i][0]) ? i++ : 0;
    }
    dest[i] = 0;
    return (dest);
}
