/*
** EPITECH PROJECT, 2024
** load file
** File description:
** navy.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"

static char *load_file_data(int fd, int fileSize)
{
    char *buff = malloc(fileSize + 1);

    if (buff == NULL)
        return NULL;
    if (lseek(fd, 0, SEEK_SET) == -1) {
        free(buff);
        return NULL;
    }
    if (read(fd, buff, fileSize) == -1) {
        free(buff);
        return NULL;
    }
    buff[fileSize] = '\0';
    return buff;
}

static int get_file_size(int fd)
{
    int fileSize = 0;
    char buffer[4096];
    int bytesRead = read(fd, buffer, sizeof(buffer));

    while (bytesRead > 0) {
        fileSize += bytesRead;
        bytesRead = read(fd, buffer, sizeof(buffer));
    }
    if (bytesRead == -1)
        return -1;
    return fileSize;
}

char *load_file_in_mem(char const *filepath)
{
    char *buff = NULL;
    int fd = open(filepath, O_RDONLY);
    int fileSize;

    if (fd == -1)
        return NULL;
    fileSize = get_file_size(fd);
    if (fileSize == -1) {
        close(fd);
        return NULL;
    }
    buff = load_file_data(fd, fileSize);
    if (buff == NULL) {
        close(fd);
        return NULL;
    }
    close(fd);
    return buff;
}
