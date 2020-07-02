/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** get_number_first_line
*/

#include "my.h"

int get_number_loop(int fd, char buff, int *ptr)
{
    int result = 0;
    for (; (buff >= '0' && buff <= '9') && buff != '\n';) {
        *ptr = 1;
        result += buff - '0';
        read(fd, &buff, 1);
        if ((buff >= '0' && buff <= '9') && buff != '\n')
            result *= 10;
    }
    if (buff != '\n' && (buff < '0' || buff > '9'))
        *ptr = 0;
    return (result);
}

int get_number_first_line(int fd)
{
    int rd = 0;
    int result = 0;
    char buff;
    int check = 0;
    int *ptr = &check;
    rd = read(fd, &buff, 1);
    if (rd < 0)
        return (-1);
    result = get_number_loop(fd, buff, ptr);
    if (check != 1)
        return (-1);
    close(fd);
    return (result);
}