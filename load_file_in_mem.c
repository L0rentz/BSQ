/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** load_file_in_mem
*/

#include "my.h"

char *load_file_in_mem(char const *filepath)
{
    char *file;
    char buff;
    int fd = 0;
    int count = 0;
    fd = open(filepath, O_RDONLY);
    read(fd, &buff, 1);
    count++;
    for (; (buff >= '0' && buff <= '9') && buff != '\n';) {
        read(fd, &buff, 1);
        count++;
    }
    struct stat filestat;
    stat(filepath, &filestat);
    file = malloc((filestat.st_size - count + 1) * sizeof(char));
    read(fd, file, filestat.st_size - count);
    file[filestat.st_size - count] = '\0';
    close(fd);
    return (file);
}
