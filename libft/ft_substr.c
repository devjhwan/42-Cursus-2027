/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:02:46 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:02:46 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Create a new string from `s`, starting at index `start`, up to `len` chars.
 * - If `start` is beyond the source length, return an allocated empty string.
 * - Real copy length is min(remaining length from start, len).
 * - Allocate copy_length + 1 and copy with null terminator.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	ret_len;
	char	*ret;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	ret_len = s_len - start;
	if (ret_len > len)
		ret_len = len;
	ret = (char *)malloc(ret_len + 1);
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s + start, ret_len + 1);
	return (ret);
}
