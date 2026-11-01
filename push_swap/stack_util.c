/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-31 14:20:33 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-31 14:20:33 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_new_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = node;
	node->prev = node;
	return (node);
}

void	push_node(t_stack **stack, t_stack *node)
{
	if (stack == NULL || node == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = *stack;
		node->prev = (*stack)->prev;
		(*stack)->prev->next = node;
		(*stack)->prev = node;
		*stack = node;
	}
}

void	append_node(t_stack **stack, t_stack *node)
{
	if (stack == NULL || node == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->prev = (*stack)->prev;
		node->next = *stack;
		(*stack)->prev->next = node;
		(*stack)->prev = node;
	}
}

t_stack	*pop_node(t_stack **stack)
{
	t_stack	*node;

	if (stack == NULL || *stack == NULL)
		return (NULL);
	node = (*stack);
	if (node->next == node)
		*stack = NULL;
	else
	{
		(*stack)->prev->next = (*stack)->next;
		(*stack)->next->prev = (*stack)->prev;
		*stack = node->next;
	}
	node->next = node;
	node->prev = node;
	return (node);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tail;
	t_stack	*next;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	tail = (*stack)->prev;
	while (current != tail)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(tail);
	*stack = NULL;
}
