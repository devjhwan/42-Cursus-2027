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
			  parse_nbr.c		\
			  a_push.c			\
			  a_rotate.c		\
			  a_rrotate.c		\
			  a_swap.c			\
			  ft_putstr.c		\
			  ft_split.c		\
			  ft_split_utils.c

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c push_swap.h Makefile | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
