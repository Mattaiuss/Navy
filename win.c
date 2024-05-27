/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-navy-matteo.aufiero
** File description:
** win
*/

#include "my.h"

static int if_win(all_t *data, int i)
{
    for (int y = 0; y < 8; y++)
        if (data->map1_1[i][y] >= '2' && data->map1_1[i][y] <= '5')
            return 1;
    return 0;
}

int loose_condi(all_t *data)
{
    for (int i = 0; i < 8; i++)
        if (if_win(data, i) == 1)
            return 1;
    return 0;
}

int win_condi(all_t *data)
{
    int cpt_touch = 0;

    for (int i = 0; i < 8; i++)
        for (int y = 0; y < 8; y++)
            cpt_touch += data->map1_2[i][y] == 'x' ? 1 : 0;
    if (cpt_touch == (2 + 3 + 4 + 5))
        return 0;
    return 1;
}

int loose(all_t *data)
{
    put_boats(data);
    my_putstr("Enemy won\n");
    return 1;
}

int win(all_t *data)
{
    put_boats(data);
    my_putstr("I won\n");
    kill(data->sig->sender, SIGUSR1);
    return 0;
}
