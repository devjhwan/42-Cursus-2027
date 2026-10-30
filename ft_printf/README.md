*This project has been created as part of the 42 curriculum by junghwal.*

## Description

`ft_printf` is a C implementation of the standard `printf` function. It formats and writes characters, strings, pointers, signed and unsigned integers, hexadecimal values, and percent signs. It supports field width, precision, and the `-`, `0`, `#`, `+`, and space flags.

The format string is scanned from left to right. When a `%` is found, the parser stores the conversion's flags, width, precision, and specifier in a `t_conv` structure, then dispatches it to the matching conversion handler. Handlers format values into character arrays and append output to a fixed-size 1024-byte buffer, which is flushed to standard output when full and at the end of `ft_printf`. This keeps parsing, conversion, and writing separate while reducing individual system calls.

## Algorithm and flag handling

The formatting process follows these steps:

1. Scan the format string from left to right, adding ordinary characters to the output buffer.
2. At `%`, initialize a conversion description and parse the conversion using this format:

   ```text
   %[flags][width][.precision][specifier]
   ```

   The supported flags are `-`, `0`, `#`, `+`, and space. Width and precision are optional decimal numbers; precision begins with `.`. Supported specifiers are `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, and `%`.
3. Use the specifier to dispatch the conversion to its handler. The handler retrieves the matching argument from the `va_list`, formats it, and applies padding.
4. Add the result to the output buffer and flush the buffer when full; `ft_printf` flushes the remaining output at the end.

The parsed flags are stored as a bit field in `t_conv`, alongside the width, precision, and specifier. Conversion handlers only apply the flags relevant to their type:

| Specifier | Flag behavior |
| --- | --- |
| `%c` | `-` left-aligns the character; width adds space padding. Other flags and precision are ignored. |
| `%s` | `-` left-aligns the string; width adds space padding. Precision limits the number of characters. Other flags are ignored. |
| `%d`, `%i` | `-` left-aligns; `0` pads with zeroes when precision is not specified; `+` adds a plus sign to non-negative values; space adds a leading space when `+` is absent. Precision sets the minimum number of digits. |
| `%u` | `-` left-aligns; `0` pads with zeroes when precision is not specified. Precision sets the minimum number of digits. `#`, `+`, and space do not affect this conversion. |
| `%x`, `%X` | `-` left-aligns; `0` pads with zeroes when precision is not specified; `#` adds the `0x` or `0X` prefix for non-zero values. Precision sets the minimum number of digits. `+` and space are ignored. |
| `%p` | `-` left-aligns; width adds space padding. Non-null pointers use a `0x` prefix and null pointers print as `(nil)`. Other flags and precision are ignored. |
| `%%` | `-` left-aligns the percent sign; width adds space padding. Other flags and precision are ignored. |

## Instructions

Build the static library with `make`. Use `make clean` to remove object files, `make fclean` to remove all generated files, or `make re` to rebuild.

Include `ft_printf.h` and link `libftprintf.a` when compiling your program:

```sh
cc -Wall -Wextra -Werror -I. main.c -L. -lftprintf
```

Call `ft_printf` like the standard function, for example: `ft_printf("Hello, %s!\n", "42");`.

## Resources

- [`printf(3)` manual](https://man7.org/linux/man-pages/man3/printf.3.html) — reference for formatted output.
- [`stdarg(3)` manual](https://man7.org/linux/man-pages/man3/stdarg.3.html) — reference for variadic arguments.

AI was used to assist with writing the project code and drafting this README. The algorithm design, parsing-stage ideas, and detailed code revisions were done by the author.
