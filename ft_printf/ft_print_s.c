/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:09:38 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:09:38 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(t_conv conv, va_list args)
{
	int		count;
	int		len;
	char	*str;

	count = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = (int)ft_strlen(str);
	if (conv.p >= 0 && conv.p < len)
		len = conv.p;
	if (!(conv.f & F_MINUS))
	{
		if (ft_append_padding(&count, conv.w - len, ' ') < 0)
			return (-1);
	}
	if (ft_write_str_n(str, len) < 0)
		return (-1);
	count += len;
	if (conv.f & F_MINUS)
	{
		if (ft_append_padding(&count, conv.w - len, ' ') < 0)
			return (-1);
	}
	return (count);
}
