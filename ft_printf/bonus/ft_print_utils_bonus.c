/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:09:51 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:09:51 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_repeat(char c, int count)
{
	int	written;

	written = 0;
	while (written < count)
	{
		if (ft_buffer_write_char(c) < 0)
			return (-1);
		written++;
	}
	return (written);
}

int	ft_append_padding(int *count, int pad_len, char pad_char)
{
	int	pad;

	if (pad_len <= 0)
		return (0);
	pad = ft_write_repeat(pad_char, pad_len);
	if (pad < 0)
		return (-1);
	*count += pad;
	return (0);
}

int	ft_write_str_n(const char *s, int len)
{
	int	written;

	written = 0;
	while (written < len)
	{
		if (ft_buffer_write_char(s[written]) < 0)
			return (-1);
		written++;
	}
	return (written);
}

int	ft_utoa_base(unsigned long long value, int upper, char *buf)
{
	char	*base;
	char	tmp[32];
	int		idx;
	int		out;

	base = "0123456789abcdef";
	if (upper)
		base = "0123456789ABCDEF";
	if (value == 0)
	{
		buf[0] = '0';
		return (1);
	}
	idx = 0;
	while (value > 0)
	{
		tmp[idx++] = base[value % 16];
		value /= 16;
	}
	out = 0;
	while (idx > 0)
		buf[out++] = tmp[--idx];
	return (out);
}

int	ft_utoa_dec(unsigned int value, char *buf)
{
	char	tmp[16];
	int		idx;
	int		out;

	if (value == 0)
	{
		buf[0] = '0';
		return (1);
	}
	idx = 0;
	while (value > 0)
	{
		tmp[idx++] = (char)('0' + (value % 10));
		value /= 10;
	}
	out = 0;
	while (idx > 0)
		buf[out++] = tmp[--idx];
	return (out);
}
