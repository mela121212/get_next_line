# get_next_line

This implementation of `get_next_line` in C is designed to efficiently and flexibly read lines from a file descriptor. The main function `get_next_line` reads a line from the specified file descriptor, while the auxiliary functions `fill_stash` and `extract_line` assist in processing the data.

## Functions

### `get_next_line(int fd)`
The `get_next_line` function reads a line from the specified file descriptor `fd`.

- **Parameters**:
  - `fd`: The file descriptor from which the line will be read.

- **Return**:
  - Returns the next line from the file as a character string (`char *`).
  - Returns `NULL` if the end of the file is reached or an error occurs during reading.

### `fill_stash(int fd, char *buff, char *stash)`
The `fill_stash` function reads data from the file descriptor and stores it in a "stash" for further processing.

- **Parameters**:
  - `fd`: The file descriptor from which the data will be read.
  - `buff`: A buffer used to temporarily store the data read from the file.
  - `stash`: A pointer to the current "stash" containing unprocessed data from previous calls to `get_next_line`.

- **Return**:
  - Returns a pointer to a character string representing the updated "stash" after reading and adding data from the file.
  - Returns `NULL` if an error occurs during reading.

### `extract_line(char *line)`
The `extract_line` function extracts a single line of text from a character string.

- **Parameters**:
  - `line`: The character string from which the line will be extracted.

- **Return**:
  - Returns a pointer to a character string representing the extracted line.
  - Returns `NULL` if the input string is empty or does not contain a complete line.

## Usage
To use the `get_next_line` function in your project, simply include the `"get_next_line.h"` file and ensure that `get_next_line.c` is compiled along with your other source files. Then, you can call the `get_next_line` function in your code to obtain lines from a file opened with `open()`.

```c
#include "get_next_line.h"

int main(void) {
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL) {
        // Process the obtained line
        printf("%s\n", line);
        free(line); // Free memory after use
    }
    close(fd);
    return 0;
}
