/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** load_map
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

void print_board(all_t *p, int i, int j)
{
    my_putchar(p->map1_1[i][j]);
    my_putchar(' ');
}

void print_eneboard(all_t *p, int i, int j)
{
    my_putchar(p->map1_2[i][j]);
    my_putchar(' ');
}

void display_board(all_t *p)
{
    my_putstr("my navy:\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_put_nbr(i + 1);
        my_putchar('|');
        for (int j = 0; j < 8; j++)
            print_board(p, i, j);
        my_putchar('\n');
    }
    my_putchar('\n');
}

void display_eneboard(all_t *p)
{
    my_putstr("enemy navy:\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_put_nbr(i + 1);
        my_putchar('|');
        for (int j = 0; j < 8; j++)
            print_eneboard(p, i, j);
        my_putchar('\n');
    }
    my_putchar('\n');
}

static int let_true(int k, int m, all_t *p)
{
    if (p->boat[k]->let_beg < p->boat[k]->let_end) {
        if (POSMAPP(0, m) != '.')
            return 84;
        else
            POSMAPP(0, m) = p->boat[k]->length;
    } else {
        if (POSMAPN(0, m) != '.')
            return 84;
        else
            POSMAPN(0, m) = p->boat[k]->length;
    }
    return 0;
}

static int num_true(int k, int m, all_t *p)
{
    if (p->boat[k]->num_beg < p->boat[k]->num_end) {
        if (POSMAPP(m, 0) != '.')
            return 84;
        else
            POSMAPP(m, 0) = p->boat[k]->length;
    } else {
        if (POSMAPN(m, 0) != '.')
            return 84;
        else
            POSMAPN(m, 0) = p->boat[k]->length;
    }
    return 0;
}

static int if_init(int k, int m, int len_let, all_t *p)
{
    if (len_let != 0) {
        if (let_true(k, m, p) == 84)
            return 84;
    } else {
        if (num_true(k, m, p) == 84)
            return 84;
    }
    return 0;
}

static int for_init(int k, int len_let, all_t *p)
{
    for (int m = 0; m < (p->boat[k]->length - 48); m++)
        if (if_init(k, m, len_let, p) == 84)
            return 84;
    return 0;
}

static int init_ship(all_t *p)
{
    int len_let;

    for (int k = 0; k < 4; k++) {
        len_let = p->boat[k]->let_beg - p->boat[k]->let_end;
        if (for_init(k, len_let, p) == 84)
            return 84;
    }
    return 0;
}

int init_board(all_t *p)
{
    p->map1_1 = (char **)malloc(sizeof(char *) * 8);
    p->map1_2 = (char **)malloc(sizeof(char *) * 8);
    for (int i = 0; i < 8; i++) {
        p->map1_1[i] = (char *)malloc(sizeof(char) * 8);
        p->map1_2[i] = (char *)malloc(sizeof(char) * 8);
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            p->map1_1[i][j] = '.';
            p->map1_2[i][j] = '.';
        }
    }
    return init_ship(p);
}
