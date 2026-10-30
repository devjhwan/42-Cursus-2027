NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I. -I./libft
AR			= ar
ARFLAGS		= rcs
RM			= rm -rf
OBJ_DIR		= .obj

LIBFT_DIR	= libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

SRCS		= ft_printf.c				\
			  ft_vprintf.c				\
			  ft_buffer.c				\
			  ft_parse_conversion.c		\
			  ft_handle_format.c		\
			  ft_handle_conversion.c	\
			  ft_print_utils.c			\
			  ft_print_c.c				\
			  ft_print_s.c				\
			  ft_print_percent.c		\
			  ft_print_d_i.c			\
			  ft_print_u_x.c			\
			  ft_print_p.c

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

bonus: all

$(NAME): $(LIBFT_A) $(OBJS)
	cp $(LIBFT_A) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c ft_printf.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
