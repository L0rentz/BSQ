/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** header
*/

#ifndef CPE_BSQ_2019_MY_H
#define CPE_BSQ_2019_MY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int get_number_first_line(int fd);
int count_cols_and_check_char(char *file);
char *load_file_in_mem(char const *filepath);
int check_carriage_ret(char *file);
int *fill_int_tab(char *file, int rows, int cols);
int *find_biggest_square(int *data, int rows, int cols);
int find_pos_biggest_square(int *data, int rows, int cols);
char *print_cross_square(int pos, int *data, char *file);

#endif
