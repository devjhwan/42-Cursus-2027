/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:02:02 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:02:02 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
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
