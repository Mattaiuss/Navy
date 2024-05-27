/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-navy-matteo.aufiero
** File description:
** game
*/

#include "my.h"

int take_input(all_t *data)
{
    int test = 0;

    while (test == 0) {
        if (input_attack(&test, data) == 84)
            return 84;
    }
    return 0;
}

void put_boats(all_t *data)
{
    display_board(data);
    display_eneboard(data);
}

int game(all_t *data)
{
    while (1) {
        if (loose_condi(data) == 0)
            return loose(data);
        if (take_input(data) == 84)
            return 84;
        if (send_signal(data) == 84)
            return 84;
        my_putstr("\nwaiting for enemy's attack...\n\n");
        if (win_condi(data) == 0)
            return win(data);
        if (recieve_signal(data) == 84)
            return 84;
        put_boats(data);
    }
    return 0;
}

int game_second(all_t *data)
{
    while (1) {
        if (recieve_signal(data) == 84)
            return 84;
        if (loose_condi(data) == 0)
            return loose(data);
        if (take_input(data) == 84)
            return 84;
        if (send_signal(data) == 84)
            return 84;
        if (win_condi(data) == 0)
            return win(data);
        my_putchar('\n');
        put_boats(data);
        my_putstr("waiting for enemy's attack...\n\n");
    }
    return 0;
}
