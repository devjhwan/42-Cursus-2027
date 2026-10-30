/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:01:23 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:01:23 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*u_s1;
	const unsigned char	*u_s2;
	size_t				i;

	u_s1 = (const unsigned char *)s1;
	u_s2 = (const unsigned char *)s2;
	i = 0;
	while (i < n && u_s1[i] == u_s2[i])
		i++;
	if (i == n)
		return (0);
	return ((int)(u_s1[i] - u_s2[i]));
}
