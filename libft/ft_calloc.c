/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:00:14 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:00:14 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
 * Allocate zero-initialized memory for an array of `n` elements of `size`.
 * - Check multiplication overflow before `n * size`.
 * - Allocate total bytes.
 * - Set every byte to 0 manually.
 * Returns NULL on allocation/overflow failure.
 */
void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*ptr;
	size_t			total;
	size_t			i;

	if (n == 0 || size == 0)
		return (malloc(0));
	if (n > ((size_t)-1) / size)
		return (NULL);
	total = n * size;
	ptr = (unsigned char *)malloc(total);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < total)
		ptr[i++] = 0;
	return (ptr);
}
