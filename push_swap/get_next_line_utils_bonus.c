/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-01 22:01:57 by junghwal          #+#    #+#             */
/*   Updated: 2026-11-01 22:01:57 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	init_context(t_context *context)
{
	context->buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (context->buffer == NULL)
		return (0);
	context->buffer[0] = '\0';
	context->len = 0;
	context->capacity = BUFFER_SIZE + 1;
	return (1);
}

void	free_context(t_context *context)
{
	free(context->buffer);
	context->buffer = NULL;
	context->len = 0;
	context->capacity = 0;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

int	has_newline(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	unsigned char	*new_ptr;
	size_t			copy_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = (unsigned char *)malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		copy_size = old_size;
		if (copy_size > new_size)
			copy_size = new_size;
		ft_memcpy(new_ptr, ptr, copy_size);
		free(ptr);
	}
	return (new_ptr);
}
