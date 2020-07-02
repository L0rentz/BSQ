/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** TODO: add description
*/

#include "my.h"

int *fill_int_tab(char *file, int rows, int cols)
{
    int *data;
    int i = 0;
    int j = 0;
    int k = 0;
    int len = 0;
    for (; file[len] != '\0'; len++);
    data = malloc((len + 1) * sizeof(int));
    for (; i != rows; i++) {
        for (j = 0; j != cols; j++, k++) {
            if (file[k] == '.')
                data[k] = 1;
            if (file[k] == 'o' || file[k] == '\n')
                data[k] = 0;
        }
    }
    return (data);
}

int *find_biggest_square(int *data, int rows, int cols)
{
    int left = 0;
    int up = 0;
    int diag = 0;
    int smallest = 0;
    int k = cols + 1;
    for (int i = 1; i != rows; i++) {
        for (int j = 0; j != cols; j++, k++) {
            left = data[k - 1];
            up = data[k - cols];
            diag = data[k - cols - 1];
            smallest = left;
            if (up < smallest)
                smallest = up;
            if (diag < smallest)
                smallest = diag;
            if (data[k] != 0)
                data[k] = smallest + 1;
        }
    }
    return (data);
}

int find_pos_biggest_square(int *data, int rows, int cols)
{
    int k = 0;
    int biggest = 0;
    int pos = 0;
    for (int i = 0; i != rows; i++) {
        for (int j = 0; j != cols; j++, k++) {
            if (data[k] > biggest) {
                biggest = data[k];
                pos = k;
            }
        }
    }
    return (pos);
}

char *print_cross_square(int pos, int *data, char *file)
{
    int biggest = data[pos];
    int column = 0;
    int cols = biggest;
    int rows = biggest;
    for (int i = 0; file[i] != '\n' && file[i] != '\0'; i++, column++);
    column++;
    for (; rows != 0; rows--) {
        for (cols = biggest; cols != 0; cols--, pos--) {
            file[pos] = 'x';
        }
        pos = pos - column + biggest;
    }
    return (file);
}