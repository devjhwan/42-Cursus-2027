/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:10:08 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:10:08 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vprintf(const char *format, va_list args)
{
	int	printed_chars;
	int	result;

	printed_chars = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (ft_buffer_flush() < 0)
				return (-1);
			result = ft_handle_format(&format, args);
			if (result < 0)
				return (-1);
			printed_chars += result;
		}
		else
		{
			if (ft_buffer_write_char(*format) < 0)
				return (-1);
			printed_chars++;
			format++;
		}
	}
	return (printed_chars);
}
