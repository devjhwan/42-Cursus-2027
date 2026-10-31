/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_conversion_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:09:14 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:09:14 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	is_flag_char(char c)
{
	return (c == '-' || c == '0' || c == '#' || c == '+' || c == ' ');
}

static void	set_flag(t_conv *conv, char c)
{
	if (c == '-')
		conv->f |= F_MINUS;
	else if (c == '0')
		conv->f |= F_ZERO;
	else if (c == '.')
		conv->f |= F_DOT;
	else if (c == '#')
		conv->f |= F_HASH;
	else if (c == '+')
		conv->f |= F_PLUS;
	else if (c == ' ')
		conv->f |= F_SPACE;
}

static int	is_conversion_char(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	parse_conversion(const char *format, t_conv *conv)
{
	int	idx;

	idx = 1;
	while (is_flag_char(format[idx]))
	{
		set_flag(conv, format[idx]);
		idx++;
	}
	conv->w = ft_atoi(&format[idx]);
	while (ft_isdigit(format[idx]))
		idx++;
	if (format[idx] == '.')
	{
		set_flag(conv, '.');
		idx++;
		conv->p = ft_atoi(&format[idx]);
		while (ft_isdigit(format[idx]))
			idx++;
	}
	if (!is_conversion_char(format[idx]))
		return (1);
	conv->cs = format[idx];
	return (idx + 1);
}
