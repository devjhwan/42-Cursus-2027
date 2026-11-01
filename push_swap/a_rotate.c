/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-31 15:17:41 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-31 15:17:41 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **s)
{
	if (s == NULL || *s == NULL)
		return ;
	*s = (*s)->next;
}

void	ra(t_stack **a)
{
	rotate(a);
	buffer_add(CMD_RA);
}

void	rb(t_stack **b)
{
	rotate(b);
	buffer_add(CMD_RB);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	buffer_add(CMD_RR);
}
