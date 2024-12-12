#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

void wait_for_keypress() {
    // struct termios oldt, newt;
    // printf("Click any source to continue...\n");

    // tcgetattr(STDIN_FILENO, &oldt);
    // newt = oldt;

    // newt.c_lflag &= ~(ICANON | ECHO);
    // tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // getchar();
    // tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	int		fd5;
	int		fd6;
	int		fd7;
	int		fd8;
	int		fd9;
	int		fd10;
	int		fd11;


	fd1 = open("./text/example.txt", O_RDONLY);
	fd2 = open("./text/1char.txt", O_RDONLY);
	fd3 = open("./text/empty.txt", O_RDONLY);
	fd4 = open("./text/giant_line_nl.txt", O_RDONLY);
	fd5 = open("./text/giant_line.txt", O_RDONLY);
	fd6 = open("./text/lines_around_10.txt", O_RDONLY);
	fd7 = open("./text/multiple_nl.txt", O_RDONLY);
	fd8 = open("./text/one_line_no_nl.txt", O_RDONLY);
	fd9 = open("./text/only_nl.txt", O_RDONLY);
	fd10 = open("./text/read_error.txt", O_RDONLY);
	fd11 = open("./text/variable_nls.txt", O_RDONLY);
	i = 1;
	
	line = get_next_line(fd1);
	printf("example.txt [%02d]: %s \n", i, line);
	free(line);
	wait_for_keypress();
	line = get_next_line(fd2);
	printf("1char.txt [%02d]: %s \n", i, line);
	free(line);
	wait_for_keypress();
	line = get_next_line(fd3);
	printf("empty.txt [%02d]: %s \n", i, line);
	free(line);
	wait_for_keypress();
	line = get_next_line(fd4);
	printf("giant_line_nl.txt [%02d]: %s \n", i, line);
	free(line);
	wait_for_keypress();
	line = get_next_line(fd5);
	printf("giant_line.txt [%02d]: %s \n", i, line);
	free(line);
	wait_for_keypress();
	line = get_next_line(fd6);
	printf("lines_around_10.txt [%02d]: %s \n", i, line);
	free(line);
	wait_for_keypress();
	line = get_next_line(fd7);
	printf("multiple_nl.txt [%02d]: %s \n", i, line);
	free(line);
	wait_for_keypress();
	line = get_next_line(fd8);
	printf("one_line_no_nl.txt [%02d]: %s \n", i, line);
	free(line);
	wait_for_keypress();
	line = get_next_line(fd9);
	printf("only_nl.txt [%02d]: %s \n", i, line);
	free(line);
	wait_for_keypress();
	line = get_next_line(fd10);
	printf("read_error.txt [%02d]: %s \n", i, line);
	free(line);
	wait_for_keypress();
	line = get_next_line(fd11);
	printf("variable_nls.txt [%02d]: %s \n", i, line);
	free(line);
	wait_for_keypress();

	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	close(fd6);
	close(fd7);
	close(fd8);
	close(fd9);
	close(fd10);
	close(fd11);
	return (0);
}