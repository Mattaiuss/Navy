/*
** EPITECH PROJECT, 2023
** Day06-Task06
** File description:
** Task06-my_strcmp, a code that compares 2 strings
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'){
        i++;
    }
    return (s1[i] - s2[i]);
}
