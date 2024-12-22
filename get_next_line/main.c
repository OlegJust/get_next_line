#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	while (i = 9)
// 	{
// 		fd = open("example.txt", O_RDONLY);
// 		if (fd < 0)
// 		{
// 			printf("ERROR\n");
// 			return (0);
// 		}
// 		line = get_next_line(fd);
// 		while (line != NULL)
// 		{
// 			printf("%s", line);
// 			free(line);
// 			line = get_next_line(fd);
// 		}
// 		free(line);
// 		close(fd);
// 		i++;
// 	}
	
	
// }

void process_file(const char *file_path) {
    // Здесь вы можете обрабатывать файл, как вам нужно
    
	int		fd;
	char	*line;

	printf("Processing file: %s\n", file_path);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		printf("ERROR\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	
	
}

void list_files_in_directory(const char *directory_path) {
    DIR *dir = opendir(directory_path);
    if (!dir) {
        perror("opendir failed");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Пропускаем "." и ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", directory_path, entry->d_name);

        // Проверяем, является ли это файлом или директорией
        if (entry->d_type == DT_DIR) {
            // Если это директория, рекурсивно вызываем функцию
            list_files_in_directory(full_path);
        } else if (entry->d_type == DT_REG) {
            // Если это файл, обрабатываем его
            process_file(full_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    list_files_in_directory(argv[1]);
    return EXIT_SUCCESS;
}