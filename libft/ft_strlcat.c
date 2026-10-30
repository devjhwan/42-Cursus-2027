/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:02:17 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:02:17 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	d_len;
	size_t	s_len;

	d_len = 0;
	while (d_len < dsize && dst[d_len] != '\0')
		d_len++;
	s_len = ft_strlen(src);
	if (d_len == dsize)
		return (dsize + s_len);
	ft_strlcpy(dst + d_len, src, dsize - d_len);
	return (d_len + s_len);
}
