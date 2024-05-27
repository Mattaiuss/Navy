/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-navy-matteo.aufiero
** File description:
** signal
*/

#include "my.h"

void update_enemymap(all_t *data)
{
    pause();
    my_putstr("\nresult: ");
    my_putchar(data->letter_pos + 65);
    my_put_nbr(data->int_pos + 1);
    my_putchar(':');
    if (data->sig->sig == 1) {
        data->map1_2[data->int_pos][data->letter_pos] = 'x';
        my_putstr("hit\n");
    } else {
        data->map1_2[data->int_pos][data->letter_pos] = 'o';
        my_putstr("missed\n");
    }
}

static int check_touch(all_t *data)
{
    if (data->map1_1[data->enemy_ipos - 1][data->enemy_lpos - 1] >= '2' &&
        data->map1_1[data->enemy_ipos - 1][data->enemy_lpos - 1] <= '5') {
        data->map1_1[data->enemy_ipos - 1][data->enemy_lpos - 1] = 'x';
        return 1;
    }
    if (data->map1_1[data->enemy_ipos - 1][data->enemy_lpos - 1] == '.') {
        data->map1_1[data->enemy_ipos - 1][data->enemy_lpos - 1] = 'o';
        return 2;
    }
    if (data->map1_1[data->enemy_ipos - 1][data->enemy_lpos - 1] == 'o')
        return 2;
    if (data->map1_1[data->enemy_ipos - 1][data->enemy_lpos - 1] == 'x')
        return 2;
    return 0;
}

int send_signal(all_t *data)
{
    for (int i = 0; i != data->letter_pos + 1; i ++) {
        usleep(1000);
        if (kill(data->sig->sender, SIGUSR1) == -1)
            return 84;
        pause();
    }
    for (int j = 0; j != data->int_pos + 1; j ++) {
        usleep(1000);
        if (kill(data->sig->sender, SIGUSR2) == -1)
            return 84;
        pause();
    }
    usleep(1000);
    if (kill(data->sig->sender, SIGUSR1) == -1)
        return 84;
    update_enemymap(data);
    return 0;
}

int is_touched(all_t *data, int coo_letter, int coo_number)
{
    data->enemy_lpos = coo_letter;
    data->enemy_ipos = coo_number;
    data->is_touch = check_touch(data);
    usleep(1000);
    my_putstr("result: ");
    my_putchar(data->enemy_lpos + 64);
    my_put_nbr(data->enemy_ipos);
    if (data->is_touch == 1) {
        if (kill(data->sig->sender, SIGUSR1) == -1)
            return 84;
        my_putstr(":hit\n\n");
    } else {
        if (kill(data->sig->sender, SIGUSR2) == -1)
            return 84;
        my_putstr(":missed\n\n");
    }
    return 0;
}

int recieve_signal(all_t *data)
{
    int coo_letter = 0;
    int coo_number = 0;

    pause();
    while (data->sig->sig == 1) {
        coo_letter ++;
        usleep(1000);
        if (kill(data->sig->sender, SIGUSR1) == -1)
            return 84;
        pause();
    }
    while (data->sig->sig == 2) {
        coo_number ++;
        usleep(1000);
        if (kill(data->sig->sender, SIGUSR1) == -1)
            return 84;
        pause();
    }
    return is_touched(data, coo_letter, coo_number);
}
