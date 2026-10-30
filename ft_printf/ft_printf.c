/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:09:54 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:09:54 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_chars;

	va_start(args, format);
	printed_chars = ft_vprintf(format, args);
	va_end(args);
	if (ft_buffer_flush() < 0)
		return (-1);
	if (printed_chars < 0)
		return (-1);
	return (printed_chars);
}
