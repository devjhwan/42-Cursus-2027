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
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b)
{
	rrotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	rrotate(a);
	rrotate(b);
	ft_putstr_fd("rrr\n", 1);
}
