The get_next_line function reads a file descriptor line by line:

  It reads data from the file into a static buffer until it encounters a newline or reaches the end of the file.
  It extracts the first line from the buffer.
  It saves the remainder of the buffer for future reads.
The utility functions handle string manipulation (copying, searching, etc.) to help achieve this functionality.
