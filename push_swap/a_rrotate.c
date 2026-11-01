/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_rrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-31 15:17:41 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-31 15:17:41 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_stack **s)
{
	if (s == NULL || *s == NULL)
		return ;
	*s = (*s)->prev;
}

void	rra(t_stack **a)
{
	rrotate(a);
	buffer_add(CMD_RRA);
}

void	rrb(t_stack **b)
{
	rrotate(b);
	buffer_add(CMD_RRB);
}

void	rrr(t_stack **a, t_stack **b)
{
	rrotate(a);
	rrotate(b);
	buffer_add(CMD_RRR);
}
