/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-01 16:14:12 by junghwal          #+#    #+#             */
/*   Updated: 2026-11-01 16:14:12 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	**get_buffer(void)
{
	static t_stack	*buffer;

	return (&buffer);
}

static int	*get_buffer_error(void)
{
	static int	error;

	return (&error);
}

void	buffer_add(int command)
{
	t_stack	**buffer;
	t_stack	*node;

	if (*get_buffer_error())
		return ;
	if (command < CMD_PA || command > CMD_SS)
	{
		*get_buffer_error() = 1;
		return ;
	}
	buffer = get_buffer();
	if (buffer_merge_command(buffer, command))
		return ;
	node = create_new_node(command);
	if (node == NULL)
	{
		*get_buffer_error() = 1;
		return ;
	}
	push_node(buffer, node);
}

int	buffer_flush(void)
{
	t_stack	**buffer;
	t_stack	*current;
	t_stack	*top;
	int		error;

	buffer = get_buffer();
	error = *get_buffer_error();
	if (!error && *buffer != NULL)
	{
		top = *buffer;
		current = top->prev;
		while (1)
		{
			buffer_print_command(current->value);
			if (current == top)
				break ;
			current = current->prev;
		}
	}
	free_stack(buffer);
	if (error)
		return (-1);
	return (0);
}
