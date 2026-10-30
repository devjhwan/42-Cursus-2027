/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:01:29 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:01:29 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Copy `n` bytes from `src` to `dest`, even when memory regions overlap.
 * - If `dest` starts after `src`, copy backward to avoid overwriting bytes
 *   that are still needed.
 * - Otherwise copy forward (delegated to ft_memcpy in this implementation).
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == src || n == 0)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s)
		while (n-- > 0)
			d[n] = s[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
