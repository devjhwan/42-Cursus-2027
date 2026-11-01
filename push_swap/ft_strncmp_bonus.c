/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:02:30 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:02:30 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*u_s1;
	const unsigned char	*u_s2;

	i = 0;
	u_s1 = (const unsigned char *)s1;
	u_s2 = (const unsigned char *)s2;
	while (i < n && u_s1[i] == u_s2[i] && u_s1[i] != '\0')
		i++;
	if (i == n)
		return (0);
	return ((int)(u_s1[i] - u_s2[i]));
}
