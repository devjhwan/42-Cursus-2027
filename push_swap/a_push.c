/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-31 15:14:34 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-31 15:14:34 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*node;

	if (dst == NULL || src == NULL || *src == NULL)
		return ;
	node = pop_node(src);
	if (node != NULL)
		push_node(dst, node);
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	buffer_add(CMD_PA);
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	buffer_add(CMD_PB);
}
