/*
** EPITECH PROJECT, 2023
** task03
** File description:
** shows the len of a str
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
