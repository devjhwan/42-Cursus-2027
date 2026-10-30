/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:09:10 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:09:10 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_conv(t_conv *conv)
{
	conv->f = 0;
	conv->w = 0;
	conv->p = -1;
	conv->cs = 0;
}

int	ft_handle_format(const char **format, va_list args)
{
	t_conv	conv;
	int		parsed_len;

	(void)args;
	if (**format != '%')
		return (-1);
	init_conv(&conv);
	parsed_len = parse_conversion(*format, &conv);
	if (parsed_len < 0)
		return (-1);
	*format += parsed_len;
	if (parsed_len == 1)
	{
		if (ft_buffer_write_char('%') < 0)
			return (-1);
		return (1);
	}
	return (ft_handle_conversion(conv, args));
}
