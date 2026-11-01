/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-31 14:51:43 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-31 14:51:43 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **s)
{
	int	tmp;

	if (s == NULL || *s == NULL || (*s)->next == *s)
		return ;
	tmp = (*s)->value;
	(*s)->value = (*s)->next->value;
	(*s)->next->value = tmp;
}

void	sa(t_stack **a)
{
	swap(a);
	buffer_add(CMD_SA);
}

void	sb(t_stack **b)
{
	swap(b);
	buffer_add(CMD_SB);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	buffer_add(CMD_SS);
}
