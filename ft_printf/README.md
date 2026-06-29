# ft_printf

ft_printf is a recreation of part of the standard C `printf` function.

The goal is to implement formatted output by parsing a format string and printing different types of values depending on conversion specifiers.

This project is important because it introduces variadic functions, formatted output, parsing and type-specific printing logic.

---

## Overview

The function receives a format string and a variable number of arguments.

It scans the format string character by character. When it finds a `%` conversion, it retrieves the next argument and prints it according to the requested type.

```text
format string
  ↓
parse characters
  ↓
detect conversion
  ↓
read argument
  ↓
print formatted value
  ↓
return number of printed characters
```

---

## Main Function

```c
int	ft_printf(const char *format, ...);
```

The function returns the number of characters printed.

---

## Supported Conversions

| Conversion | Description                             |
| ---------- | --------------------------------------- |
| `%c`       | print a character                       |
| `%s`       | print a string                          |
| `%p`       | print a pointer address                 |
| `%d`       | print a signed decimal integer          |
| `%i`       | print a signed decimal integer          |
| `%u`       | print an unsigned decimal integer       |
| `%x`       | print a number in lowercase hexadecimal |
| `%X`       | print a number in uppercase hexadecimal |
| `%%`       | print a percent sign                    |

---

## Implemented Helpers

This project was organized with helper functions for each output type.

Examples:

* `putchar` / character output
* `putstr` / string output
* `putnbr` / signed number output
* `putptr` / pointer address output
* `putnbr_hex` / hexadecimal output
* `putnbr_dec` / decimal and unsigned output

Each helper contributes to the final printed character count.

---

## Main Topics

* variadic functions
* `va_list`
* `va_start`
* `va_arg`
* `va_end`
* format string parsing
* integer conversion
* hexadecimal conversion
* pointer formatting
* output counting
* edge-case handling

---

## Skills Practiced

* C programming
* parsing
* modular helper functions
* recursion or iterative number printing
* base conversion
* handling signed and unsigned values
* writing reusable output functions
* testing against standard `printf` behavior

---

## How It Works

Simplified flow:

```text
ft_printf("Hello %s %d", name, number)
  ↓
print normal characters
  ↓
find %s
  ↓
print string argument
  ↓
find %d
  ↓
print integer argument
  ↓
return total printed length
```

---

## How to Build

```bash
make
```

This builds the library containing `ft_printf`.

Depending on the Makefile, the output may be:

```text
libftprintf.a
```

---

## Example Usage

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello %s\n", "world");
	ft_printf("Number: %d\n", 42);
	ft_printf("Hex: %x\n", 255);
	ft_printf("Pointer: %p\n", &main);
	return (0);
}
```

---

## What I Learned

The most important lessons from this project were:

* how variadic functions work in C
* how format strings are parsed
* how different data types require different printing logic
* how to convert numbers to different bases
* how to print pointer addresses
* how to count output accurately
* how to split a complex function into smaller helpers
* how to compare behavior against the real `printf`

---

## Notes

ft_printf was a useful project because it recreated a familiar standard library function from the inside.

It helped me understand formatted output, parsing and the mechanics behind variadic functions in C.
