# Libft

Libft is the first major C library project of the 42 Common Core.

The goal is to recreate a set of useful standard C library functions and add extra utility functions that can be reused in later projects.

This project builds strong foundations in C programming, memory management, string manipulation and linked lists.

---

## Overview

Libft is a custom static library.

It contains reimplemented standard functions, additional string/memory helpers, output helpers and linked list utilities.

The final result is compiled into:

```text
libft.a
```

This library can then be linked into other C projects.

---

## Function Categories

### Character Checks and Conversion

| Function     | Description                          |
| ------------ | ------------------------------------ |
| `ft_isalpha` | check if a character is alphabetic   |
| `ft_isdigit` | check if a character is a digit      |
| `ft_isalnum` | check if a character is alphanumeric |
| `ft_isascii` | check if a character is ASCII        |
| `ft_isprint` | check if a character is printable    |
| `ft_toupper` | convert character to uppercase       |
| `ft_tolower` | convert character to lowercase       |

---

### Memory Functions

| Function     | Description                         |
| ------------ | ----------------------------------- |
| `ft_memset`  | fill memory with a byte             |
| `ft_bzero`   | set memory to zero                  |
| `ft_memcpy`  | copy memory                         |
| `ft_memmove` | copy overlapping memory safely      |
| `ft_memchr`  | locate a byte in memory             |
| `ft_memcmp`  | compare memory areas                |
| `ft_calloc`  | allocate and zero-initialize memory |

---

### String Functions

| Function     | Description                            |
| ------------ | -------------------------------------- |
| `ft_strlen`  | calculate string length                |
| `ft_strlcpy` | copy string with size limit            |
| `ft_strlcat` | concatenate string with size limit     |
| `ft_strchr`  | locate first occurrence of a character |
| `ft_strrchr` | locate last occurrence of a character  |
| `ft_strncmp` | compare strings up to `n` characters   |
| `ft_strnstr` | locate substring inside a string       |
| `ft_strdup`  | duplicate a string                     |

---

### Conversion and Allocation Helpers

| Function      | Description                                    |
| ------------- | ---------------------------------------------- |
| `ft_atoi`     | convert string to integer                      |
| `ft_itoa`     | convert integer to string                      |
| `ft_substr`   | extract a substring                            |
| `ft_strjoin`  | join two strings                               |
| `ft_strtrim`  | trim characters from both ends of a string     |
| `ft_split`    | split a string by a delimiter                  |
| `ft_strmapi`  | create a new string by applying a function     |
| `ft_striteri` | apply a function to each character of a string |

---

### File Descriptor Output

| Function        | Description                            |
| --------------- | -------------------------------------- |
| `ft_putchar_fd` | write a character to a file descriptor |
| `ft_putstr_fd`  | write a string to a file descriptor    |
| `ft_putendl_fd` | write a string followed by a newline   |
| `ft_putnbr_fd`  | write a number to a file descriptor    |

---

### Linked List Functions

| Function          | Description                              |
| ----------------- | ---------------------------------------- |
| `ft_lstnew`       | create a new list node                   |
| `ft_lstadd_front` | add a node at the beginning              |
| `ft_lstadd_back`  | add a node at the end                    |
| `ft_lstsize`      | count list nodes                         |
| `ft_lstlast`      | get the last node                        |
| `ft_lstdelone`    | delete one node                          |
| `ft_lstclear`     | delete a full list                       |
| `ft_lstiter`      | apply a function to each node            |
| `ft_lstmap`       | create a new list by applying a function |

---

## Main Topics

* C programming fundamentals
* standard library behavior
* memory allocation
* pointer manipulation
* string manipulation
* file descriptors
* linked lists
* Makefiles
* static libraries

---

## Skills Practiced

* writing clean reusable C functions
* understanding standard library internals
* handling edge cases
* avoiding memory leaks
* working with pointers
* building a static library
* organizing header files
* using Makefile rules

---

## How to Build

```bash
make
```

This creates:

```text
libft.a
```

Useful Makefile rules usually include:

```bash
make clean
make fclean
make re
```

---

## Example Usage

```c
#include "libft.h"

int	main(void)
{
	char	*str;

	str = ft_strdup("Hello Libft");
	if (!str)
		return (1);
	ft_putendl_fd(str, 1);
	free(str);
	return (0);
}
```

Compile with:

```bash
cc main.c libft.a
```

---

## Why This Project Matters

Libft is used as a foundation for many later 42 projects.

Rewriting these functions helped me understand what standard C functions do internally and why careful memory handling matters.

```text
custom functions
  ↓
static library
  ↓
reused in later C projects
```

---

## What I Learned

The most important lessons from this project were:

* how common C library functions work internally
* how to manage dynamic memory safely
* how strings are represented and manipulated in C
* how linked lists are structured
* how to write reusable code
* how to organize a small C library
* how Makefiles compile and archive object files

---

## Notes

Libft was the foundation for many later Common Core projects.

It made later projects easier because I could reuse my own tested utility functions instead of relying only on the standard library.
