/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:08:59 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:08:59 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_output_buffer	*ft_get_output_buffer(void)
{
	static t_output_buffer	buffer;

	return (&buffer);
}

int	ft_buffer_flush(void)
{
	t_output_buffer	*buffer;

	buffer = ft_get_output_buffer();
	if (buffer->len == 0)
		return (0);
	if (write(1, buffer->data, buffer->len) < 0)
		return (-1);
	buffer->len = 0;
	return (0);
}

int	ft_buffer_write_char(char c)
{
	t_output_buffer	*buffer;

	buffer = ft_get_output_buffer();
	if (buffer->len == FT_PRINTF_BUF_SIZE)
	{
		if (ft_buffer_flush() < 0)
			return (-1);
	}
	buffer->data[buffer->len++] = c;
	return (0);
}
