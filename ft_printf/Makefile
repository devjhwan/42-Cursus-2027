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

BONUS_SRCS	= ft_printf.c							\
			  bonus/ft_vprintf_bonus.c				\
			  bonus/ft_buffer_bonus.c				\
			  bonus/ft_parse_conversion_bonus.c		\
			  bonus/ft_handle_format_bonus.c		\
			  bonus/ft_handle_conversion_bonus.c	\
			  bonus/ft_print_utils_bonus.c			\
			  bonus/ft_print_c_bonus.c				\
			  bonus/ft_print_s_bonus.c				\
			  bonus/ft_print_percent_bonus.c		\
			  bonus/ft_print_d_i_bonus.c			\
			  bonus/ft_print_u_x_bonus.c			\
			  bonus/ft_print_p_bonus.c

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS	= $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	cp $(LIBFT_A) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus: $(LIBFT_A) $(BONUS_OBJS)
	cp $(LIBFT_A) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJS)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c ft_printf.h Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/bonus/%.o: bonus/%.c ft_printf.h Makefile | $(OBJ_DIR)/bonus
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/bonus:
	mkdir -p $(OBJ_DIR)/bonus

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
