# ft_printf

A 42-style implementation of `printf` packaged as a static C library:
`libftprintf.a`.

The project provides:

- `ft_printf(const char *format, ...)`
- `ft_sprintf(const char *format, ...)`
- a bundled `libft`
- support for common `printf` conversions, plus custom binary and terminal
  color conversions

## Purpose

The goal of this project is to reproduce core `printf` behavior without using
the standard library implementation internally. It parses format strings,
handles variadic arguments, applies flags, width, precision, and length
modifiers, then writes the formatted result to standard output.

It also includes a small test harness in `main.c` that compares `ft_printf`
output and return values against the system `printf`.

## Supported API

Include the project header:

```c
#include "libftprintf.h"
```

### `ft_printf`

```c
int ft_printf(const char *format, ...);
```

Formats and writes output to `STDOUT_FILENO`.

Returns the number of bytes written.

### `ft_sprintf`

```c
t_ftsprintf *ft_sprintf(const char *format, ...);
```

Formats into an allocated result structure:

```c
typedef struct s_ftsprintf
{
	int  len;
	char *str;
} t_ftsprintf;
```

The returned structure and its `str` field are allocated by the function and
should be freed by the caller when no longer needed.

## Supported Format Features

### Conversions

| Conversion | Description |
| --- | --- |
| `%c` | character |
| `%s` | string |
| `%p` | pointer |
| `%d`, `%i` | signed decimal integer |
| `%o` | unsigned octal integer |
| `%u` | unsigned decimal integer |
| `%x` | unsigned hexadecimal, lowercase |
| `%X` | unsigned hexadecimal, uppercase |
| `%f` | floating-point decimal |
| `%b` | custom binary output |
| `%k` | custom terminal color/style output |
| `%%` | literal percent sign |

### Flags

| Flag | Meaning |
| --- | --- |
| `-` | left-align within width |
| `+` | always show sign for signed positive numbers |
| space | prefix signed positive numbers with a space |
| `0` | zero padding |
| `#` | alternate form where supported |

### Width And Precision

The implementation supports numeric width, `*` width, numeric precision, and
`*` precision.

Examples:

```c
ft_printf("%10s\n", "hello");
ft_printf("%-10s|\n", "hello");
ft_printf("%.3s\n", "abcdef");
ft_printf("%08d\n", 42);
ft_printf("%*.*d\n", 8, 4, 42);
```

### Length Modifiers

Supported length modifiers:

| Modifier | Meaning |
| --- | --- |
| `hh` | char-sized integer |
| `h` | short-sized integer |
| `l` | long-sized integer |
| `ll` | long long-sized integer |
| `L` | long double for floating-point |
| `z` | `size_t` / related unsigned size |
| `j` | `intmax_t` / `uintmax_t` |
| `t` | parsed as a length modifier |

## Custom Features

### Binary: `%b`

`%b` prints an integer value in base 2.

```c
ft_printf("%032b\n", 42);
```

Example output:

```text
00000000000000000000000000101010
```

### Terminal Colors: `%k`

`%k` writes ANSI terminal color/style sequences.

The width controls the color code. Constants are defined in
`libftprintf.h`:

```c
K_BLACK
K_RED
K_GREEN
K_YELLOW
K_BLUE
K_ROSE
K_CYAN
K_WHITE
```

Examples:

```c
ft_printf("%*kred text%k\n", K_RED);
ft_printf("%+*kbold green%k\n", K_GREEN);
ft_printf("%-*kunderlined blue%k\n", K_BLUE);
ft_printf("%#*kbackground cyan%k\n", K_CYAN);
```

Style flags with `%k`:

| Format | Effect |
| --- | --- |
| `%k` | reset / end color |
| `%*k` | foreground color |
| `%-*k` | underlined foreground color |
| `%+*k` | bold foreground color |
| `%0*k` | italic foreground color |
| `%#*k` | background color |

## Build

Build the static library:

```sh
make
```

This builds:

- `libft/libft.a`
- `libftprintf.a`
- generated object files under `.obj/`
- a copied `includes/libft.h`

Rebuild from scratch:

```sh
make re
```

Remove object files:

```sh
make clean
```

Remove build artifacts:

```sh
make fclean
```

## Test

Build the test executable:

```sh
make test
```

Run the test executable:

```sh
./test.out
```

The test binary compares many `ft_printf` calls against system `printf` and
prints a final summary such as:

```text
157/157 tests reussi (0 errors)
```

Note: the test suite intentionally includes invalid or undefined format strings
to compare behavior. When compiled with AddressSanitizer, system `printf` may
print a runtime warning about an unexpected format specifier. That warning is
from the test harness and is not necessarily a failing test.

## Compile Your Own Program

Example `tests/main.c`:

```c
#include "libftprintf.h"

int	main(void)
{
	ft_printf("Hello %s: %d, %#x, %032b\n", "world", 42, 42, 42);
	return (0);
}
```

Compile it against the library:

```sh
make
cc tests/main.c -I includes -L . -lftprintf -o demo
```

Run it:

```sh
./demo
```

Alternative direct archive link:

```sh
cc tests/main.c -I includes libftprintf.a -o demo
```

## Project Layout

```text
.
|-- Makefile
|-- includes/
|   `-- libftprintf.h
|-- documentation/
|   `-- documentations and diagrams
|-- libft/
|   |-- Makefile
|   |-- includes/libft.h
|   `-- *.c
|-- srcs/
|   |-- ft_printf.c
|   |-- put.c
|   |-- handler.c
|   |-- functions.c
|   |-- get_dec_lenght.c
|   |-- params.c
|   `-- buffer.c
|-- tests/
    `-- main.c
```

## Notes

- The project is written in C and builds with `gcc`/`cc`.
- The Makefile currently enables AddressSanitizer debug flags via `DEBUGFLG`.
- `make test` suppresses compiler format warnings for the test harness because
  many tests intentionally pass invalid format strings to system `printf`.
- `libftprintf.a` includes the bundled `libft` objects by first copying
  `libft/libft.a` into the final archive and then adding printf objects.
