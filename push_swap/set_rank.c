/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-31 19:56:11 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-31 19:56:11 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_values(int *values, int count)
{
	int	i;
	int	j;
	int	value;

	i = 1;
	while (i < count)
	{
		value = values[i];
		j = i - 1;
		while (j >= 0 && values[j] > value)
		{
			values[j + 1] = values[j];
			j--;
		}
		values[j + 1] = value;
		i++;
	}
}

static int	find_rank(const int *values, int count, int value)
{
	int	left;
	int	right;
	int	middle;

	left = 0;
	right = count;
	while (left < right)
	{
		middle = left + (right - left) / 2;
		if (values[middle] < value)
			left = middle + 1;
		else
			right = middle;
	}
	return (left);
}

int	set_rank(t_stack **stack, int count)
{
	t_stack	*node;
	int		*values;
	int		i;

	values = malloc(count * sizeof(int));
	if (values == NULL)
		return (-1);
	node = *stack;
	i = 0;
	while (i < count)
	{
		values[i++] = node->value;
		node = node->next;
	}
	sort_values(values, count);
	node = *stack;
	i = 0;
	while (i < count)
	{
		node->value = find_rank(values, count, node->value);
		node = node->next;
		i++;
	}
	free(values);
	return (0);
}
