*This project has been created as part of the 42 curriculum by junghwal.*

# libft

## Description
`libft` is a project where part of the C standard library is reimplemented as a reusable static library (`libft.a`).
The goal is to build solid fundamentals in memory handling, string manipulation, character checks/conversion, output functions, and linked-list operations.

## Instructions
Compile:
```bash
make
```

Clean:
```bash
make clean      # remove object files
make fclean     # remove object files + libft.a
make re         # full rebuild
```

Use in another project:
1. Include the header: `#include "libft.h"`
2. Link the library when compiling: `-L. -lft`

Example:
```bash
cc main.c -L. -lft -o app
```

## Makefile Notes
- Purpose: The Makefile automates the full build flow for `libft.a`, so the same commands produce consistent results across environments.
- Relink meaning: "Relink" means recreating `libft.a` even when source code did not change, which causes unnecessary archive updates.
- Relink prevention: The rule `$(NAME): $(OBJS)` makes `libft.a` depend only on object files, and `$(OBJ_DIR)/%.o: %.c libft.h` rebuilds only changed objects. Because of these dependencies, `make` skips `$(AR) $(ARFLAGS) $(NAME) $(OBJS)` when no object is newer than `libft.a`.
- Object files: Each `.c` source is first compiled into a `.o` object file (machine code, not yet a final library). In this project, all object files are placed in `.obj/` through `OBJ_DIR = .obj`.
- Object file benefits: They enable incremental builds (only modified sources are recompiled), reduce build time, and separate compile errors per source file, which makes debugging and maintenance easier.
- `clean`: Removes only intermediate build artifacts (`.obj/`) so the repository stays clean and object files can be regenerated safely.
- `fclean`: Performs `clean` and also removes `libft.a`, returning the project to a pre-build state.
- `re`: Runs `fclean` then `all` to force a complete rebuild, useful when you want to eliminate any stale build state.

## Makefile Symbols Used
- `$(...)`: Expands a variable value (example: `$(NAME)`, `$(OBJS)`).
- `$@`: Automatic variable for the current target name (example: output object file path in pattern rules).
- `$<`: Automatic variable for the first prerequisite (example: current source `.c` file).
- `:`: Separates target and dependencies (example: `$(NAME): $(OBJS)`).
- `%`: Pattern wildcard used in pattern rules (example: `$(OBJ_DIR)/%.o: %.c libft.h`).
- `|`: Order-only dependency separator; the right side must exist before the recipe runs but does not trigger rebuilds by timestamp changes (example: `| $(OBJ_DIR)`).
- `\`: Line continuation character, used to split long variable definitions across multiple lines.
- `.PHONY`: Marks names such as `clean`, `fclean`, and `re` as commands, not real files.

## Library Details
This library provides the following groups of functions.

- Character checks/conversion: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
- Memory operations: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- String operations: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`
- String creation/transformation: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_atoi`
- File-descriptor output: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- Singly linked list: `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

For readability, some functions include detailed comments above their implementations to explain core logic and edge-case handling for beginners.

Project files:
- `libft.h`: function prototypes and type declarations
- `Makefile`: build rules
- `ft_*.c`: implementation files

## Resources
Main reference:
- Ubuntu default C manual pages (`man`, e.g., `man 3 strlen`).
- No additional external references were used.

AI usage:
- AI was used to structure and refine this README.
- AI was also used to draft beginner-friendly comments for selected function implementations.
- Core function logic, Makefile rules, and final code review were completed according to the project requirements.