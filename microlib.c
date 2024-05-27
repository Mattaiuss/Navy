/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-bsnavy-matteo.aufiero
** File description:
** microlib
*/

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i ++;
    }
}

void my_put_nbr(long long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    } else
        my_putchar(nb + '0');
}

int my_getnbr(char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign = sign * (-1);
        i = i + 1;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        result = result * 10;
        result = result + str[i] - 48;
        i = i + 1;
    }
    return result * sign;
}

static char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char c;

    while (str[i] != '\0')
        i ++;
    i --;
    while (i > j) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i --;
        j ++;
    }
    return str;
}

static int intlen(int nb)
{
    int i = 0;

    if (nb == 0)
        return 1;
    while (nb != 0) {
        nb /= 10;
        i ++;
    }
    return i;
}

char *int_tostr(long long int nb)
{
    char *str = malloc(sizeof(char) * intlen(nb) + 1);

    if (nb == 0)
        return "0\0";
    for (int i = 0; i != 10; i ++)
        str[i] = '\0';
    for (int i = 0; nb != 0; i ++) {
        str[i] = nb % 10 + 48;
        nb /= 10;
    }
    return my_revstr(str);
}
