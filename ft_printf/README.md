*This project has been created as part of the 42 curriculum by junghwal.*

## Description

`ft_printf` is a C implementation of `printf`, developed in two separate
versions: the mandatory part and the bonus part. Both versions support the
standard conversions required by the project: `c`, `s`, `p`, `d`, `i`, `u`,
`x`, `X`, and `%%`.

## Mandatory

The mandatory version handles the required conversions without parsing flags,
field width, or precision. Its output flow is:

1. `ft_printf` starts the variadic argument list, delegates processing to
   `ft_vprintf`, and returns the number of characters written.
2. `ft_vprintf` scans the format string from left to right. Ordinary characters
   are written directly; when it encounters `%`, it passes the following
   character and the argument list to `ft_handle_conversion`.
3. `ft_handle_conversion` selects the output function for the conversion.
   Character and string conversions use `ft_putchar` and `ft_putstr`; numeric
   conversions use `ft_putnbr` or `ft_putnbr_base`.
4. `ft_putnbr` writes a minus sign for negative signed values, then delegates
   digit conversion to `ft_putnbr_base` in base 10. `ft_putnbr_base` counts the
   digits, fills a character array from right to left, and writes the resulting
   string.
5. Each output function returns its written byte count. The conversion and
   format-processing functions add these counts and return `-1` when an output
   operation fails or a conversion is unsupported.

The mandatory conversion handlers retrieve arguments using their expected
variadic types:
- `int` for `%c`, `%d`, and `%i`
- `char *` for `%s`
- `void *` for `%p`
- `unsigned int` for `%u`, `%x`, and `%X`
- `%%` writes one percent sign
- null `%s` argument prints `(null)`, while a null `%p` argument prints `(nil)`

Build the mandatory library with:

```sh
make
```

## Bonus

The bonus version parses format strings using this structure:

```text
%[flags][width][.precision][specifier]
```

It supports the `-`, `0`, `#`, `+`, and space flags, field width, and precision.
The conversions apply the relevant options as follows:

| Specifier | Behavior |
| --- | --- |
| `%c` | `-` left-aligns; width adds space padding. Other flags and precision are ignored. |
| `%s` | `-` left-aligns; width adds space padding; precision limits the number of characters. Other flags are ignored. |
| `%d`, `%i` | `-` left-aligns; `0` pads with zeroes when precision is not specified; `+` adds a plus sign to non-negative values; space adds a leading space when `+` is absent; precision sets the minimum number of digits. |
| `%u` | `-` left-aligns; `0` pads with zeroes when precision is not specified; precision sets the minimum number of digits. `#`, `+`, and space are ignored. |
| `%x`, `%X` | `-` left-aligns; `0` pads with zeroes when precision is not specified; `#` adds the `0x` or `0X` prefix for non-zero values; precision sets the minimum number of digits. `+` and space are ignored. |
| `%p` | `-` left-aligns; width adds space padding. Non-null pointers use a `0x` prefix and null pointers print as `(nil)`. Other flags and precision are ignored. |
| `%%` | Writes one percent sign. Flags and width do not affect it. |

Build the bonus library with:

```sh
make bonus
```

Both targets select their implementation in `libftprintf.a`. The Makefile
keeps a separate archive for each version, so switching between mandatory and
bonus updates the selected library without relinking an unchanged version.

## Usage

Include the appropriate header (`ft_printf.h` for mandatory or
`bonus/ft_printf_bonus.h` for bonus) and link `libftprintf.a`:

```sh
cc -Wall -Wextra -Werror -I. main.c -L. -lftprintf
```

Example:

```c
ft_printf("Hello, %s!\n", "42");
```

## Resources

- [`printf(3)` manual](https://man7.org/linux/man-pages/man3/printf.3.html) — reference for formatted output.
- [`stdarg(3)` manual](https://man7.org/linux/man-pages/man3/stdarg.3.html) — reference for variadic arguments.

AI was used to assist with writing the project code and drafting this README.
The algorithm design, parsing-stage ideas, and detailed code revisions were
done by the author.
