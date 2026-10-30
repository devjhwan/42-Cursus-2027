/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:02:34 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:02:34 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Search `little` inside `big`, but only within the first `len` bytes of `big`.
 * - Empty `little` matches immediately at `big`.
 * - At each index, compare `little` length bytes with `ft_strncmp`.
 * - Stop when a full match would exceed `len` or end of `big` is reached.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b_idx;
	size_t	l_len;

	if (little[0] == '\0')
		return ((char *)big);
	l_len = ft_strlen(little);
	b_idx = 0;
	while (b_idx + l_len <= len && big[b_idx] != '\0')
	{
		if (ft_strncmp(big + b_idx, little, l_len) == 0)
			return ((char *)(big + b_idx));
		b_idx++;
	}
	return (NULL);
}
