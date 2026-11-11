*This project has been created as part of the 42 curriculum by hlatt.*

# get_next_line

## Description

The **get_next_line** project is part of the 42 School curriculum. Its objective is to create a function that reads a file descriptor and returns one line at a time.

The function reads from a file descriptor until it encounters a newline character (`\n`) or reaches the end of the file (EOF).

Unlike standard file-reading functions that read an entire file at once, `get_next_line()` allows the caller to retrieve individual lines through repeated function calls.

### Goal

- Understand file descriptors and file reading.
- Work with static variables.
- Manage dynamically allocated memory.
- Handle different buffer sizes.
- Learn how to handle EOF and memory allocation failures.

## Instructions

### Compilation

Compile the mandatory source files using:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl
```

### Buffer Size

The buffer size can be specified during compilation using the `-D` flag.

For example:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

If `BUFFER_SIZE` is not specified, the implementation uses its default value.

### Execution

Run the executable with a file as an argument:

```bash
./gnl file.txt
```

The function returns one line per call, including the newline character when present. It returns `NULL` when there is nothing left to read or when an error occurs.

## Algorithm Explanation

### General Approach

The implementation uses a **static variable to preserve unread data between function calls**.

This is necessary because `read()` may retrieve more data than what is needed for the current line. Instead of discarding the remaining characters, they are stored and reused during the next call.

### Step-by-Step Process

1. **Read:** Read data from the file descriptor using `read()` and a buffer of `BUFFER_SIZE` bytes.

2. **Accumulate:** Append the newly read data to the previously stored leftover data.

3. **Search:** Check whether the accumulated string contains a newline character (`\n`).

4. **Extract:** If a newline is found, extract everything up to and including that newline as the returned line.

5. **Preserve:** Keep the remaining characters in the static variable for the next function call.

6. **Return:** Return the extracted line and repeat the process on subsequent calls.

7. **EOF:** If the end of the file is reached, return any remaining characters as the final line. If no characters remain, return `NULL`.

### Why This Algorithm?

The static-buffer approach avoids losing data when a single `read()` operation retrieves multiple lines or part of the next line.

It also allows the function to work with different `BUFFER_SIZE` values without requiring the entire file to be loaded into memory.

The algorithm is suitable for this project because it provides sequential line reading while preserving unread data between calls.

## Resources

### Documentation and References

- [42 get_next_line Subject](https://github.com/42School/42cursus)
- [read() — Linux Manual](https://man7.org/linux/man-pages/man2/read.2.html)
- [malloc() — Linux Manual](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [free() — Linux Manual](https://man7.org/linux/man-pages/man3/free.3.html)
- [Static Variables in C](https://en.cppreference.com/w/c/language/static.html)

### AI Usage

ChatGPT was used as a learning and development assistant during this project.

It was used for:
- Understanding the project requirements and the behavior of file descriptors.
- Discussing the static variable approach and line extraction logic.
- Designing manual test cases for different buffer sizes, EOF conditions, empty files, and long lines.
- Creating a temporary testing program to verify the function's behavior.
- Understanding debugging results and memory-management concepts.

The implementation and final algorithm were reviewed and tested by the student. AI assistance was used to support learning and debugging rather than replace the implementation process.
