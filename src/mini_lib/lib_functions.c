/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** __DESCRIPTION__
*/

#include "lemin_hd.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int number = 0;
    int a = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            a *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (number == 214748364 && str[i] == 8 + 48 && a == -1 &&
            !(str[i + 1] < 58 && str[i + 1] > 47))
            return (-2147483648);
        else if ((number == 214748364 && str[i] > 7 + 48) ||
        number > 214748364)
            return (0);
        number *= 10;
        number += str[i] - 48;
        i++;
    }
    return (number * a);
}

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return (0);
    for (i = 0; str[i]; i++);
    return (i);
}

void my_putstr(char const *str)
{
    int err = 0;

    if (!str)
        return;
    for (int i = 0; str[i]; i++)
        err = write(1, &str[i], 1);
}

void my_putchar(char c)
{
    int err = 0;

    err = write(1, &c, 1);
}

int my_strncmp(char const *sa, char const *sb)
{
    return (!*sa || (*sa != *sb) ? (*sa - *sb) : my_strncmp(sa + 1, sb + 1));
}
