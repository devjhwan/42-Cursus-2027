*This project has been created as part of the 42 curriculum by junghwal.*

## Description

`get_next_line` is a C function that reads from a file descriptor and returns one line per call. A returned line includes its terminating newline when one is present; if the input ends with a non-empty final line that has no newline, that line is returned as well. The function returns `NULL` when there is no more input to return or when a read or allocation error occurs.

The mandatory implementation keeps the unread input between calls for one file descriptor. The bonus implementation keeps separate state for multiple file descriptors, allowing lines to be read from them alternately.

## Algorithm

Each call to `get_next_line(fd)` follows the same basic process:

1. **Keep the reading state between calls.** The mandatory version stores one static `t_context`, containing a buffer, its current length, and its capacity. The bonus version stores an array of contexts and selects the one indexed by `fd`, so data read ahead for one descriptor is kept separate from other descriptors. The bonus version returns `NULL` immediately for descriptors outside the range `0` to `MAX_FD - 1`.
2. **Read only when necessary.** If the saved buffer does not already contain a newline, `read_file` reads chunks of up to `BUFFER_SIZE` bytes until it finds a newline or reaches end-of-file. This means a single read may bring in bytes beyond the line being returned; those bytes remain in the context for a later call.
3. **Grow the saved buffer as needed.** Before appending each chunk, `expand_context` checks whether the current capacity is sufficient. It first checks that adding the incoming data and null terminator will not overflow `size_t`; if the required size cannot be represented, it fails instead of attempting an invalid allocation. Otherwise, it increases the capacity geometrically (doubling it until it can hold the accumulated input and a null terminator), then copies the existing data into the larger allocation.
4. **Return one line and retain the rest.** `pop_line` scans the saved data for the first newline. It allocates and returns a string through that newline, including it. If no newline remains at end-of-file, it returns the remaining non-empty bytes as the final line. It then shifts any unreturned bytes to the start of the context buffer and updates the saved length.
5. **Stop when there is nothing to return.** If reading reaches end-of-file with no saved bytes, or a read/allocation error occurs, the function returns `NULL`. Read and allocation errors also release the affected context.

The context buffer is the key data structure: it holds both the bytes accumulated while searching for the next newline and any bytes read ahead that belong to following lines. Retaining that buffer across calls avoids discarding data and lets each call return exactly one line.

### Data structure choice

This implementation uses `t_context` to retain the accumulated input, its length, and its capacity. Reusing this buffer and growing it geometrically avoids allocating and copying a new combined string for every read, reducing allocation and copying overhead as input grows.

If minimizing `malloc` calls is not a priority, the implementation can be made shorter by joining newly read chunks to the saved string with `strjoin`. After extracting a line, `memmove` can shift the remaining bytes to the start of the string; `strlen` can be used to determine string lengths where needed. In that design, the capacity-tracking structure and its associated initialization, cleanup, and reallocation functions are unnecessary. This is an alternative approach, not the one used by the current implementation.

## Instructions

The project has no Makefile. Compile the mandatory implementation with your own `main.c`:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o get_next_line
```

`BUFFER_SIZE` controls the number of bytes requested from `read` at a time. If it is not defined during compilation, the headers set it to `42`.

To compile the bonus implementation instead, use its source and utility files:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o get_next_line
```

Include `get_next_line.h` for the mandatory version or `get_next_line_bonus.h` for the bonus version. Do not compile both versions into the same executable because they define the same `get_next_line` function.

Call `get_next_line(fd)` repeatedly, using the returned string each time and freeing it when it is no longer needed. Close the file descriptor when finished. The bonus version supports file descriptors from `0` up to (but not including) `MAX_FD`, defined as `10240`.

## Resources

- [`read(2)` manual](https://man7.org/linux/man-pages/man2/read.2.html) — behavior of reading bytes from a file descriptor.
- [`malloc(3)` manual](https://man7.org/linux/man-pages/man3/malloc.3.html) — dynamic memory allocation and release.

AI was used to inspect the project implementation and draft this README, including the algorithm explanation and compilation instructions. AI was not used to write or modify the project source code.
