/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-31 10:33:07 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-31 10:33:07 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	return (write(1, s, ft_strlen(s)));
}

int	ft_putchar(char ch)
{
	return (write(1, &ch, 1));
}

int	ft_putnbr(long n)
{
	int	count;
	int	result;

	count = 0;
	if (n < 0)
	{
		count = ft_putchar('-');
		if (count < 0)
			return (-1);
		n = -n;
	}
	result = ft_putnbr_base((unsigned long long)n, 10, 0);
	if (result < 0)
		return (-1);
	return (count + result);
}

int	ft_putnbr_base(unsigned long long n, int base, int upper)
{
	char				*b;
	char				nbr[21];
	unsigned long long	tmp;
	int					len;

	if (base == 10)
		b = "0123456789";
	else if (base == 16 && upper)
		b = "0123456789ABCDEF";
	else if (base == 16)
		b = "0123456789abcdef";
	len = 1;
	tmp = n;
	while (tmp >= (unsigned long long)base)
	{
		tmp /= base;
		len++;
	}
	nbr[len] = '\0';
	while (len > 0)
	{
		nbr[--len] = b[n % base];
		n /= base;
	}
	return (ft_putstr(nbr));
}
