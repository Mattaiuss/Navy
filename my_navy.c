/*
** EPITECH PROJECT, 2024
** navy_project
** File description:
** navy play
*/

#include "my.h"

signal_t *set_signal(signal_t *signal)
{
    static signal_t *new = NULL;

    if (signal != NULL)
        new = signal;
    return new;
}

void handler(int sig, siginfo_t *info, void *context)
{
    static signal_t *signal = NULL;

    (void)context;
    if (signal == NULL)
        signal = set_signal(NULL);
    if (sig == SIGUSR1)
        signal->sig = 1;
    if (sig == SIGUSR2)
        signal->sig = 2;
    signal->my_pid = getpid();
    signal->sender = info->si_pid;
}

int main(int ac, char **av)
{
    all_t p;
    char *file = load_file_in_mem(av[ac - 1]);

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        usages();
        return 0;
    }
    if (ac != 2 && ac != 3)
        return 84;
    if (file == NULL || file[0] == '\0' || !(check_all(av[ac - 1], &p, file)))
        return 84;
    if (init_board(&p))
        return 84;
    if (ac == 2)
        return player1(&p);
    if (ac == 3)
        return player2(&p, my_getnbr(av[1]));
}
