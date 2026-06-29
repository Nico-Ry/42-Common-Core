# get_next_line

get_next_line is a file descriptor reading project from the 42 Common Core.

The goal is to write a function that reads and returns one line at a time from a file descriptor.

This project is important because it introduces static variables, buffer management, file descriptors and careful memory handling in C.

---

## Overview

The function reads from a file descriptor until it reaches a newline character or the end of the file.

Each call returns the next available line.

```text
file descriptor
  ↓
read into buffer
  ↓
store remaining data
  ↓
extract one line
  ↓
return line to caller
```

The challenge is that a line may be longer than the buffer size, so the function must preserve unread data between calls.

---

## Main Function

```c
char	*get_next_line(int fd);
```

The function returns:

* the next line from the file descriptor
* `NULL` when there is nothing else to read or an error occurs

---

## Main Topics

* file descriptors
* `read()`
* static variables
* buffer management
* dynamic memory allocation
* string manipulation
* newline detection
* memory leaks
* edge-case handling

---

## Skills Practiced

* C programming
* managing persistent state between function calls
* reading files progressively
* handling partial data
* working with buffers
* allocating and freeing memory correctly
* debugging file-reading logic

---

## How It Works

A simplified flow:

```text
call get_next_line(fd)
  ↓
check if saved data already contains a newline
  ↓
read more data if needed
  ↓
join saved data with new buffer
  ↓
extract the next line
  ↓
save the remaining characters for the next call
  ↓
return the line
```

---

## Example Usage

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("example.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

---

## How to Build

Depending on the repository structure, compile with the required source files:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c
```

With a custom buffer size:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

---

## Important Edge Cases

Important cases to handle include:

* empty files
* files with no newline at the end
* very long lines
* `BUFFER_SIZE=1`
* large buffer sizes
* invalid file descriptors
* multiple consecutive calls
* memory allocation failures
* preserving remaining data after a newline

---

## What I Learned

The most important lessons from this project were:

* how file descriptors are read progressively
* why one call to `read()` is not always enough
* how static variables preserve state between calls
* how to manage leftover data after returning a line
* how easy it is to create memory leaks in string-building logic
* how important edge-case testing is in C

---

## Notes

get_next_line is a small project, but it is a strong foundation for later projects that require parsing files, reading input or handling streams of data.
