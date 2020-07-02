/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac == 2) {
        int fd = open(av[1], O_RDONLY);
        if (fd < 0) return (84);
        int rows = get_number_first_line(fd);
        char *file = load_file_in_mem(av[1]);
        int cols = count_cols_and_check_char(file);
        int count = check_carriage_ret(file);
        if (cols == -1 || rows == -1 || count != rows|| count == -1)
            return (84);
        int *data = find_biggest_square(fill_int_tab(file, rows, cols), rows,
                                        cols);
        int pos = find_pos_biggest_square(data, rows, cols);
        file = print_cross_square(pos, data, file);
        int len = 0;
        for (; file[len] != '\0'; len++);
        write(1, file, len);
        free(file);
        free(data);
    }
    return (0);
}
