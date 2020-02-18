/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** __DESCRIPTION__
*/

#include "lemin_hd.h"

int main(void)
{
    if (start_algo() == 84)
        return (84);
    return (0);
}

int if_alphnum_two(char const *str, int i)
{
    if (str[i] >= '0' && str[i] <= '9')
        return (1);
    return (0);
}

int alloc_mem_two(char const *str)
{
    int i = 0;
    int k = 0;

    while (str[i]) {
        if (if_alphnum_two(str, i) && !if_alphnum_two(str, i + 1))
            k++;
        i++;
    }
    return (k);
}

char **my_str_to_word_array_two(char const *str)
{
    char **dest = NULL;
    int i = 0;
    int g = 0;
    int n = 0;

    dest = malloc(sizeof(char *) * (alloc_mem_two(str) + 1) + 1);
    while (str[g]) {
        if (!if_alphnum_two(str, g))
            g++;
        for (n = g; if_alphnum_two(str, n); n++);
        dest[i] = (char *)malloc((n - g) + 2);
        dest[i][0] = 0;
        for (n = 0; if_alphnum_two(str, g); n++)
            dest[i][n] = str[g++];
        dest[i][n] = '\0';
        if (dest[i][0])
            i++;
    }
    dest[i] = 0;
    return (dest);
}
