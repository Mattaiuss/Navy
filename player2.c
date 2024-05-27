/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-navy-matteo.aufiero
** File description:
** player2
*/

#include "my.h"
#include <fcntl.h>

static void my_put_pid(all_t *data)
{
    my_putstr("my_pid: ");
    my_put_nbr(data->sig->my_pid);
    my_putstr("\n");
}

int player2(all_t *data, int id)
{
    struct sigaction sa;

    data->sig = malloc(sizeof(signal_t));
    data->sig = set_signal(data->sig);
    data->sig->sender = id;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    data->sig->my_pid = getpid();
    my_put_pid(data);
    usleep(1000);
    if (kill(id, SIGUSR1) == -1)
        return 84;
    my_putstr("\nsuccessfully connected to enemy\n\n");
    put_boats(data);
    my_putstr("waiting for enemy's attack...\n\n");
    return game_second(data);
}
