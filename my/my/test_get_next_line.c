#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

void test_file_with_lines()
{
    printf("Test: File with multiple lines\n");
    int fd = open("test_files/multiple_lines.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line: %s", line);
        free(line);
    }
    close(fd);
}

void test_empty_file()
{
    printf("Test: Empty file\n");
    int fd = open("test_files/empty.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return;
    }

    char *line = get_next_line(fd);
    if (line == NULL)
        printf("Success: No lines to read\n");
    else
    {
        printf("Failure: Unexpected line: %s", line);
        free(line);
    }
    close(fd);
}

void test_single_line_no_newline()
{
    printf("Test: Single line without newline\n");
    int fd = open("test_files/single_line.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return;
    }

    char *line = get_next_line(fd);
    if (line)
    {
        printf("Line: %s\n", line);
        free(line);
    }
    else
        printf("Failure: Expected a line but got NULL\n");

    line = get_next_line(fd);
    if (line == NULL)
        printf("Success: No more lines to read\n");
    else
    {
        printf("Failure: Unexpected line: %s", line);
        free(line);
    }
    close(fd);
}

void test_large_file()
{
    printf("Test: Large file\n");
    int fd = open("test_files/large_file.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return;
    }

    char *line;
    int line_count = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        line_count++;
        free(line);
    }
    printf("Total lines read: %d\n", line_count);
    close(fd);
}

void test_stdin()
{
    printf("Test: Read from stdin (type some lines, Ctrl+D to finish)\n");
    char *line;
    while ((line = get_next_line(0)) != NULL)
    {
        printf("You typed: %s", line);
        free(line);
    }
}

int main()
{
    test_file_with_lines();
    test_empty_file();
    test_single_line_no_newline();
    test_large_file();
    // Uncomment to test reading from stdin
    // test_stdin();
    return 0;
}
