/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-31 16:02:31 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-31 16:02:31 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	if (dsize == 0)
		return (len);
	i = 0;
	while (src[i] != '\0' && i < dsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

static char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	s_len;

	s_len = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (s_len + 1));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s, s_len + 1);
	return (ret);
}

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
