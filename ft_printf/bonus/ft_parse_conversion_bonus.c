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

#include "ft_printf.h"

static int	is_flag_char(char c)
{
	return (c == '-' || c == '0' || c == '#'
		|| c == '+' || c == ' ');
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

static void	parse_number(const char *s, int *idx, int *out)
{
	*out = ft_atoi(&s[*idx]);
	while (ft_isdigit(s[*idx]))
		(*idx)++;
}

static int	is_conversion_char(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	parse_conversion(const char *format, t_conv *conv)
{
	int	idx;

	if (!format || !conv || format[0] != '%')
		return (-1);
	idx = 1;
	while (is_flag_char(format[idx]))
	{
		set_flag(conv, format[idx]);
		idx++;
	}
	if (ft_isdigit(format[idx]))
		parse_number(format, &idx, &conv->w);
	if (format[idx] == '.')
	{
		set_flag(conv, '.');
		idx++;
		conv->p = 0;
		if (ft_isdigit(format[idx]))
			parse_number(format, &idx, &conv->p);
	}
	if (!is_conversion_char(format[idx]))
		return (1);
	conv->cs = format[idx];
	return (idx + 1);
}
