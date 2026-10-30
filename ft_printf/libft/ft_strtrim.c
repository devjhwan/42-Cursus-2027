/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:02:43 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:02:43 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Remove characters from both ends of `s1` if they exist in `set`.
 * - `start` moves right until it reaches a character not in `set`.
 * - `end` moves left until it reaches a character not in `set`.
 * - If everything is trimmed, return an allocated empty string.
 * - Otherwise copy the middle range [start, end) into a new string.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	if (start == end)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}
