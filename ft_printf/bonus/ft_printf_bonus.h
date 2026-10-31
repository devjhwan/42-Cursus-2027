/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:10:02 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:10:02 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "libft/libft.h"

# define FT_PRINTF_BUF_SIZE 1024

# define F_MINUS 1
# define F_ZERO 2
# define F_DOT 4
# define F_HASH 8
# define F_PLUS 16
# define F_SPACE 32

typedef struct s_conv
{
	char	f;
	int		w;
	int		p;
	char	cs;
}	t_conv;

typedef struct s_output_buffer
{
	char	data[FT_PRINTF_BUF_SIZE];
	int		len;
}	t_output_buffer;

typedef struct s_dctx
{
	long	value;
	char	digits[16];
	int		dlen;
	char	sign;
	int		sign_len;
	int		zeros;
	int		spaces;
	char	pad;
}	t_dctx;

typedef struct s_pctx
{
	uintptr_t	value;
	char		digits[32];
	int			dlen;
	int			spaces;
}	t_pctx;

typedef struct s_uxctx
{
	unsigned int	value;
	char			digits[32];
	int				dlen;
	int				prefix_len;
	int				zeros;
	int				spaces;
	char			pad;
	char			prefix_char;
}	t_uxctx;

int	ft_printf(const char *format, ...);
int	ft_vprintf(const char *format, va_list args);
int	ft_handle_format(const char **format, va_list args);
int	ft_handle_conversion(t_conv conv, va_list args);
int	ft_print_c(t_conv conv, va_list args);
int	ft_print_s(t_conv conv, va_list args);
int	ft_print_p(t_conv conv, va_list args);
int	ft_print_d_i(t_conv conv, va_list args);
int	ft_print_u_x(t_conv conv, va_list args);
int	ft_append_padding(int pad_len, char pad_char);
int	ft_write_bytes(const char *s, int len);
int	ft_utoa_base(unsigned long long value, int upper, char *buf);
int	ft_utoa_dec(unsigned int value, char *buf);
int	parse_conversion(const char *format, t_conv *conv);
int	ft_buffer_write_char(char c);
int	ft_buffer_flush(void);

#endif
