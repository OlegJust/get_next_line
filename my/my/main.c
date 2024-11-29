#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return (1);
    }

    // Открываем файл
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    // Читаем и выводим строки
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Освобождаем память, выделенную в get_next_line
    }

    // Закрываем файл
    close(fd);
    return (0);
}
