/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 14:59:34 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 14:59:34 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Count how many characters are needed to print `n`.
 * `n` is expected to be non-negative here, and `sign` tells whether we need
 * an extra '-' character in the final string.
 */
static int	ft_digit_len(int n, int sign)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	if (sign < 0)
		len++;
	return (len);
}

/*
 * Convert integer `n` to a newly allocated decimal string.
 * - Handle INT_MIN first because `-INT_MIN` overflows in int.
 * - Track sign, then convert number to positive for digit extraction.
 * - Fill string from right to left using modulo/division by 10.
 * - Put '-' at index 0 when original number was negative.
 */
char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 1;
	if (n < 0)
		sign = -1;
	n *= sign;
	len = ft_digit_len(n, sign);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (n >= 10)
	{
		str[--len] = (char)(n % 10 + '0');
		n /= 10;
	}
	str[--len] = (char)(n + '0');
	if (sign < 0)
		str[0] = '-';
	return (str);
}
