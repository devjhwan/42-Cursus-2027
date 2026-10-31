/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conversion.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:09:03 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:09:03 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_string(char *s)
{
	if (s == NULL)
		return (ft_putstr("(null)"));
	else
		return (ft_putstr(s));
}

static int	ft_handle_pointer(uintptr_t p)
{
	if (p == 0)
		return (ft_putstr("(nil)"));
	else
		return (ft_putstr("0x") + ft_putnbr_base((unsigned long long)p, 16, 0));
}

int	ft_handle_conversion(char ch, va_list args)
{
	if (ch == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	if (ch == 's')
		return (ft_handle_string(va_arg(args, char *)));
	if (ch == 'p')
		return (ft_handle_pointer((uintptr_t)va_arg(args, void *)));
	if (ch == 'd' || ch == 'i')
		return (ft_putnbr((long)va_arg(args, int)));
	if (ch == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), 10, 0));
	if (ch == 'x' || ch == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), 16, ch == 'X'));
	if (ch == '%')
		return (ft_putchar('%'));
	return (-1);
}
