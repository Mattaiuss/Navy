/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-navy-matteo.aufiero
** File description:
** player1
*/

#include "my.h"
#include <fcntl.h>

int player1(all_t *data)
{
    struct sigaction sa;

    data->sig = malloc(sizeof(signal_t));
    data->sig = set_signal(data->sig);
    my_putstr("my_pid: ");
    data->sig->my_pid = getpid();
    my_put_nbr(data->sig->my_pid);
    my_putstr("\n");
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    my_putstr("\nwaiting for enemy...\n");
    pause();
    my_putstr("\nenemy connected\n\n");
    put_boats(data);
    return game(data);
}
