/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:23:38 by asemykin          #+#    #+#             */
/*   Updated: 2024/12/11 17:46:00 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_set_first_chunk(int fd, char *str_long, char **buffer_tmp);
char	*ft_read_line(int fd, char *str_long, char **buffer_tmp, size_t *len);
char	*ft_split_end(char *str_long);
char	*ft_set_last_to_first_chunk(char *str_startchunk);
char	*ft_combine(const char *str_chunk, int byte, char *str_long,
			size_t *len);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s, size_t byte_len);
void	ft_bzero(void *s, size_t n);

#endif

/*
Parameters
	fd:         The file descriptor to read from

Return value
	Read line:  correct behavior
	NULL:       there is nothing else to read, or an error occurred

External functs.
	read, malloc, free

Description
	Write a function that returns a line read from a file descriptor
*/

/*
File Descripter
- Is an integer that uniquely identifies an open of the progress
*/

/*
BUFFER_SIZE
	- Determines how much data is read from a file at once when using functions
		like read() or readlines() in file handling.
	- The buffer is essentially a temporary memory storage that holds data as it
		read from a file,
			allowing more efficient reading by minimizing the number
		of calls to the underlying system to fetch data.

	- Reading data from a file byte by byte can be inefficient, especially for
		large files. By reading chunks of data into a buffer, the program can
		minimize the overheat of file I/O operation = faster and more efficient
		reading

	- BUFFER_SIZE has a default value.  (mostly 4096 bytes(4 KB))
		- for small files a smaller buffer size like 1024 might be sufficient.
		- for large files a bigger buffer size like 8192 might be more efficient.

	TOO SMALL
		- can lead to ineddicient reading since more read opertions are performed
	TOO LARGE
		- Generally a better performance, but might consume a lot of memory for
			smaller machines when reading many files concurrently
*/

/*
Static Variable
	- Retains its value between function calls and has a lifetime throughout the
		programs execution.

	Static Local Variable
		- Variable inside a function.
		- A static local variable is initialized only once when the functions is
			first called and retains its value across multiple calls to that
			function.
		- Unlike other regular variables, which are created and destroyed each
			time a function is called.

	Static Global Variables
		- Variable outside any functions.
		- It restricts the scope of the variable to the file in which it is
			declared and can not be accessed from other files or translation
		units.
		- If not static, it can be accessed from other files.
			- file1.c   int global_var = 42;    // created
			- file2.c   extern global_var;      // acces var from file1.c

	Static Function
		- Restricts the visibility to the file in which they are defined.
		- It cannot be called from others files, even though it exists within
			the program.
		- Bassically this function is private to this file.
*/