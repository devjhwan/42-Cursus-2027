/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:09:17 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:09:17 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_c(t_conv conv, va_list args)
{
	int		count;
	char	c;

	count = 0;
	c = (char)va_arg(args, int);
	if (!(conv.f & F_MINUS) && conv.w > 1)
	{
		if (ft_append_padding(conv.w - 1, ' ') < 0)
			return (-1);
		count += conv.w - 1;
	}
	if (ft_buffer_write_char(c) < 0)
		return (-1);
	count++;
	if (conv.f & F_MINUS && conv.w > 1)
	{
		if (ft_append_padding(conv.w - 1, ' ') < 0)
			return (-1);
		count += conv.w - 1;
	}
	return (count);
}
