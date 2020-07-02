/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** count_cols_and_check
*/

#include "my.h"

int count_cols_and_check_char(char *file)
{
    int i = 0;
    int count = 0;
    int count_save = 0;
    for (; file[i] != '\n' && file[i] != '\0'; i++, count_save++)
        if (file[i] != '.' && file[i] != 'o')
            return (-1);
    count_save += 1;
    i++;
    for (; file[i] != '\0'; i++) {
        for (; file[i] != '\n'; i++, count++)
            if (file[i] != '.' && file[i] != 'o')
                return (-1);
        count += 1;
        if (count != count_save)
            return (-1);
        count = 0;
    }
    return (count_save);
}

int check_carriage_ret(char *file)
{
    int i = 0;
    int count = 0;
    for (; file[i] != '\0'; i++)
        if (file[i] == '\n')
            count++;
    if (count < 1)
        return (-1);
    return (count);
}
