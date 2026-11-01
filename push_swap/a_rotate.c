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
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
