/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-31 18:30:41 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-31 18:30:41 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_to_b(t_stack **stack_a, t_stack **stack_b, int size, int min);
void	sort_b_to_a(t_stack **stack_a, t_stack **stack_b, int size, int min);
void	sort_small(t_stack **stack_a, t_stack **stack_b, int size);

int	is_sorted(t_stack **stack_a, int size)
{
	t_stack	*node;
	int		i;

	if (size <= 1)
		return (1);
	if (stack_a == NULL || *stack_a == NULL)
		return (0);
	node = *stack_a;
	i = 0;
	while (i < size - 1)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

void	sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (is_sorted(stack_a, size))
		return ;
	if (size <= 5)
		sort_small(stack_a, stack_b, size);
	else
		sort_a_to_b(stack_a, stack_b, size, 0);
}
