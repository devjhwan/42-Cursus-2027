/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:09:03 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:09:03 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_conversion(t_conv conv, va_list args)
{
	if (conv.cs == 'c')
		return (ft_print_c(conv, args));
	if (conv.cs == 's')
		return (ft_print_s(conv, args));
	if (conv.cs == 'p')
		return (ft_print_p(conv, args));
	if (conv.cs == 'd' || conv.cs == 'i')
		return (ft_print_d_i(conv, args));
	if (conv.cs == 'u')
		return (ft_print_u_x(conv, args));
	if (conv.cs == 'x' || conv.cs == 'X')
		return (ft_print_u_x(conv, args));
	if (conv.cs == '%')
		return (ft_print_percent(conv));
	return (-1);
}
