/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** my.h
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

#define SUITE(a) (((a >= '1' && a <= '8') || (a >= 'A' && a <= 'H')))
#define CONDITION(a) ((a) != '\n' && (a) != ':' && !SUITE(a))
#define ALLCPT2(d) (d->cpt_boat[2] == 1 && d->cpt_boat[3] == 1)
#define ALLCPT(d) (d->cpt_boat[0] == 1 && d->cpt_boat[1] == 1 && ALLCPT2(d))
#define GOODFIRST(cur) (cur == '2' || cur == '3' || cur == '4' || cur == '5')
#define SECPA(i, y) (p->boat[k]->let_beg - 'A' + y)
#define SECNA(i, y) (p->boat[k]->let_beg - 'A' - y)
#define POSMAPP(i, y) (p->map1_1[p->boat[k]->num_beg - '1' + i][SECPA(i, y)])
#define POSMAPN(i, y) (p->map1_1[p->boat[k]->num_beg - '1' - i][SECNA(i, y)])
#include <stdbool.h>

typedef struct {
    int length;
    char let_beg;
    int num_beg;
    char let_end;
    int num_end;
} boat_t;

typedef struct {
    int sender;
    int my_pid;
    int sig;
} signal_t;

typedef struct {
    boat_t *boat[4];
    char **map1_1;
    char **map1_2;
    int cpt_boat[4];
    int ind_cpt_bt;
    bool firstchar;
    int char_pos;
    int letter_pos;
    int int_pos;
    int enemy_lpos;
    int enemy_ipos;
    int is_touch;
    signal_t *sig;
} all_t;

void usages(void);

int my_strcmp(char const *s1, char const *s2);
char *load_file_in_mem(char const *filepath);
int check_all(char const *path, all_t *data, char *file);
void my_putchar(char c);
void my_putstr(char *str);
char *int_tostr(long long int nb);
int my_getnbr(char *str);
void my_put_nbr(long long int nb);
int my_strlen(char const *str);

int init_board(all_t *p);
void display_eneboard(all_t *p);
void display_board(all_t *p);
void put_boats(all_t *data);
void handler(int sig, siginfo_t *info, void *context);
int input_attack(int *test, all_t *data);
int take_input(all_t *data);

int player1(all_t *data);
int player2(all_t *data, int id);
int game(all_t *data);
int game_second(all_t *data);
signal_t *set_signal(signal_t *signal);

int send_signal(all_t *data);
int recieve_signal(all_t *data);

int valid_input(char *input);
int input_attack(int *test, all_t *data);

int win(all_t *data);
int loose(all_t *data);
int loose_condi(all_t *data);
int win_condi(all_t *data);
