/*
** EPITECH PROJECT, 2023
** Usages for my_sokoban
** File description:
** My_sokoban
*/

#include <unistd.h>
#include "my.h"

void usages(void)
{
    write(1, "USAGE\n", 6);
    write(1, "     ./navy [first_player_pid] navy_positions\n", 46);
    write(1, "DESCRIPTION\n", 12);
    write(1, "     first_player_pid: only for the 2nd player. pid of ", 55);
    write(1, "the first player.\n     navy_positions: file representing ", 57);
    write(1, "the positions of the ships.\n", 28);
}
