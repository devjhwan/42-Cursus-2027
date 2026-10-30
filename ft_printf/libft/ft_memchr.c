/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:01:19 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:01:19 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*u_s;
	size_t				i;

	u_s = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (u_s[i] == (unsigned char)c)
			return ((void *)(u_s + i));
		i++;
	}
	return (NULL);
}
