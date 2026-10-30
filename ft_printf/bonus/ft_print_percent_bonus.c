/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:09:35 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:09:35 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(t_conv conv)
{
	int	count;

	count = 0;
	if (!(conv.f & F_MINUS))
	{
		if (ft_append_padding(&count, conv.w - 1, ' ') < 0)
			return (-1);
	}
	if (ft_buffer_write_char('%') < 0)
		return (-1);
	count++;
	if (conv.f & F_MINUS)
	{
		if (ft_append_padding(&count, conv.w - 1, ' ') < 0)
			return (-1);
	}
	return (count);
}
