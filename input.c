/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-navy-matteo.aufiero
** File description:
** input
*/

#include "my.h"

int valid_input(char *input)
{
    if (my_strlen(input) == 3 && input[0] >= 'A' && input[0] <= 'H' &&
    input[1] >= '1' && input[1] <= '8')
        return 0;
    return 1;
}

int input_attack(int *test, all_t *data)
{
    char *input = NULL;
    size_t bufsize = 0;
    ssize_t nread;

    my_putstr("attack: ");
    nread = getline(&input, &bufsize, stdin);
    if (nread == -1) {
        my_putstr("Error reading input\n");
        return 84;
    }
    if (valid_input(input) == 0) {
        *test = 1;
    } else
        my_putstr("wrong position\n");
    data->letter_pos = (int)(input[0] - 'A');
    data->int_pos = input[1] - '1';
    free(input);
    return 0;
}
