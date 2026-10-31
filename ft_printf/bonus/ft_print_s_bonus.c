/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:09:38 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:09:38 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	init_values(t_conv conv, va_list args, char **str, int *len)
{
	*str = va_arg(args, char *);
	if (!(*str))
		*str = "(null)";
	*len = (int)ft_strlen(*str);
	if (conv.p >= 0 && conv.p < *len)
		*len = conv.p;
}

int	ft_print_s(t_conv conv, va_list args)
{
	int		count;
	int		len;
	char	*str;

	count = 0;
	init_values(conv, args, &str, &len);
	if (!(conv.f & F_MINUS) && conv.w > len)
	{
		if (ft_append_padding(conv.w - len, ' ') < 0)
			return (-1);
		count += conv.w - len;
	}
	if (ft_write_bytes(str, len) < 0)
		return (-1);
	count += len;
	if (conv.f & F_MINUS && conv.w > len)
	{
		if (ft_append_padding(conv.w - len, ' ') < 0)
			return (-1);
		count += conv.w - len;
	}
	return (count);
}
