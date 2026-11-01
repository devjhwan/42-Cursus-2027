NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -I.
RM			= rm -rf
OBJ_DIR		= .obj

SRCS		= push_swap.c		\
			  sort.c			\
			  sort_small.c		\
			  sort_a_to_b.c		\
			  sort_b_to_a.c		\
			  set_rank.c		\
			  stack_util.c		\
			  buffer.c			\
			  buffer_util.c		\
			  parse_nbr.c		\
			  a_push.c			\
			  a_rotate.c		\
			  a_rrotate.c		\
			  a_swap.c			\
			  ft_putstr.c		\
			  ft_split.c		\
			  ft_split_utils.c

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

CHECKER_SRCS	= checker_bonus.c	\
			  checker_util_bonus.c	\
			  a_push.c			\
			  a_rotate.c		\
			  a_rrotate.c		\
			  a_swap.c			\
			  stack_util.c		\
			  parse_nbr.c		\
			  set_rank.c		\
			  ft_putstr.c		\
			  ft_split.c		\
			  ft_split_utils.c	\
			  get_next_line_bonus.c	\
			  get_next_line_utils_bonus.c

CHECKER_OBJS	= $(CHECKER_SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

checker: $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o checker

bonus: checker

$(OBJ_DIR)/%.o: %.c push_swap.h Makefile | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) checker

re: fclean all

.PHONY: all bonus clean fclean re
