/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linebonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 16:19:32 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 16:19:32 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	expand_context(t_context *context, size_t read_size)
{
	char	*new_buffer;
	size_t	new_capacity;
	size_t	required_capacity;

	if (read_size > (size_t)-1 - context->len - 1)
		return (0);
	required_capacity = context->len + read_size + 1;
	if (required_capacity <= context->capacity)
		return (1);
	new_capacity = context->capacity;
	while (new_capacity < required_capacity)
	{
		if (new_capacity > (size_t)-1 / 2)
			new_capacity = required_capacity;
		else
			new_capacity *= 2;
	}
	new_buffer = (char *)ft_realloc(context->buffer,
			context->capacity, new_capacity);
	if (new_buffer == NULL)
		return (0);
	context->buffer = new_buffer;
	context->capacity = new_capacity;
	return (1);
}

char	*read_file(t_context *context, int fd)
{
	char	*buffer;
	ssize_t	read_size;

	if (context->buffer == NULL && !init_context(context))
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (free_context(context), NULL);
	while (!has_newline(context->buffer))
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == 0)
			return (free(buffer), context->buffer);
		if (read_size == -1)
			return (free(buffer), free_context(context), NULL);
		if (!expand_context(context, (size_t)read_size))
			return (free(buffer), free_context(context), NULL);
		ft_memcpy(context->buffer + context->len, buffer,
			(size_t)read_size);
		context->len += read_size;
		context->buffer[context->len] = '\0';
	}
	return (free(buffer), context->buffer);
}

static char	*pop_line(t_context *context)
{
	char	*line;
	size_t	line_len;
	size_t	remaining_len;

	if (context->len == 0)
		return (NULL);
	line_len = 0;
	while (line_len < context->len && context->buffer[line_len] != '\n')
		line_len++;
	if (line_len < context->len)
		line_len++;
	line = (char *)malloc(sizeof(char) * (line_len + 1));
	if (line == NULL)
		return (free_context(context), NULL);
	ft_memcpy(line, context->buffer, line_len);
	line[line_len] = '\0';
	remaining_len = context->len - line_len;
	ft_memcpy(context->buffer, context->buffer + line_len, remaining_len + 1);
	context->len = remaining_len;
	return (line);
}

char	*get_next_line(int fd)
{
	static t_context	context[MAX_FD];
	char				*line;

	if (fd < 0 || fd >= MAX_FD)
		return (NULL);
	if (context[fd].buffer == NULL || !has_newline(context[fd].buffer))
		context[fd].buffer = read_file(&context[fd], fd);
	if (context[fd].buffer == NULL)
		return (NULL);
	line = pop_line(&context[fd]);
	return (line);
}
