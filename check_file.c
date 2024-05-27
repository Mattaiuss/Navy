/*
** EPITECH PROJECT, 2024
** check_file
** File description:
** navy.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"

static int verif_pos(char *lines, int num_lines, all_t *p)
{
    int result;
    char *line;

    for (int i = 0; i < num_lines; ++i) {
        line = &lines[i * 7];
        p->boat[i]->length = line[i + 0];
        p->boat[i]->let_beg = line[i + 2];
        p->boat[i]->num_beg = line[i + 3];
        p->boat[i]->let_end = line[i + 5];
        p->boat[i]->num_end = line[i + 6];
        result = abs((p->boat[i]->let_beg - '0' + p->boat[i]->num_beg - '0') -
        (p->boat[i]->let_end - '0' + p->boat[i]->num_end - '0')) + 1;
        if (result != (p->boat[i]->length - '0'))
            return 0;
    }
    return 1;
}

int check_file(char const *path)
{
    int fd = open(path, O_RDONLY);
    char buffer;
    int bytesRead = read(fd, &buffer, 1);

    if (bytesRead < 1)
        return 0;
    while (bytesRead > 0) {
        if (CONDITION(buffer)) {
            close(fd);
            return 0;
        }
        bytesRead = read(fd, &buffer, 1);
    }
    close(fd);
    return 1;
}

static int check_char_constraints(char curr, int pos)
{
    if (pos == 0 && (curr < '2' || curr > '5'))
        return 0;
    if ((pos == 1 || pos == 4) && curr != ':')
        return 0;
    if ((pos == 2 || pos == 5) && (curr < 'A' || curr > 'H'))
        return 0;
    if ((pos == 3 || pos == 6) && (curr < '1' || curr > '8'))
        return 0;
    if (pos == 6 && curr == '\0')
        return 0;
    if (pos == 7 && (curr != '\n'))
        return 0;
    return 1;
}

static int process_first_char(char currentChar, all_t *data, int fd)
{
    if (data->firstchar) {
        if (!check_char_constraints(currentChar, 0)) {
            close(fd);
            return 0;
        }
        data->ind_cpt_bt = currentChar - '2';
        data->cpt_boat[data->ind_cpt_bt]++;
    } else if (!check_char_constraints(currentChar, data->char_pos)) {
        close(fd);
        return 0;
    }
    data->firstchar = (currentChar == '\n' || currentChar == '\0');
    data->char_pos = (data->char_pos + 1) % 8;
    return 1;
}

static int last_line_isempty(char *buffer)
{
    int i = 0;

    while (buffer[i] != '5')
        i ++;
    for (int j = 0; j != 7; j ++) {
        if (buffer[j + i] == '\0')
            return 0;
    }
    return 1;
}

int process_buffer(char *buffer, int size, all_t *data, int fd)
{
    char currentChar;

    for (int i = 0; i < size; i++) {
        currentChar = buffer[i];
        if (last_line_isempty(buffer) == 0)
            return 0;
        if (process_first_char(currentChar, data, fd) == 0)
            return 0;
    }
    return 1;
}

int read_and_process(int fd, all_t *data)
{
    char buffer[32000];
    int bytesRead = read(fd, buffer, sizeof(buffer));

    while (bytesRead > 0) {
        if (!process_buffer(buffer, bytesRead, data, fd))
            return 0;
        bytesRead = read(fd, buffer, sizeof(buffer));
    }
    return 1;
}

int check_boat(char const *path, all_t *data)
{
    int fd = open(path, O_RDONLY);

    if (!read_and_process(fd, data)) {
        close(fd);
        return 0;
    }
    close(fd);
    return (ALLCPT(data)) ? 84 : 0;
}

static void init_all(all_t *data)
{
    data->firstchar = true;
    data->ind_cpt_bt = 0;
    for (int i = 0; i < 4; ++i) {
        data->boat[i] = malloc(sizeof(boat_t));
        data->boat[i]->length = 0;
        data->boat[i]->let_beg = 0;
        data->boat[i]->num_beg = 0;
        data->boat[i]->let_end = 0;
        data->boat[i]->num_end = 0;
    }
    for (int i = 0; i < 4; ++i)
        data->cpt_boat[i] = 0;
}

int check_all(char const *path, all_t *data, char *file)
{
    init_all(data);
    if (!(check_file(path)) || !(check_boat(path, data)))
        return 0;
    if (!(verif_pos(file, 4, data)))
        return 0;
    return 1;
}
