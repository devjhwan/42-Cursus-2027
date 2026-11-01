/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-31 23:30:24 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-31 23:30:24 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	123
	132 rra 213 sa	n1 < n2, n1 < n3, n2 > n3
	213 sa 123		n1 > n2, n1 < n3, n2 < n3
	231 rra 123		n1 < n2, n1 > n3, n2 > n3
	312 ra 123		n1 > n2, n1 > n3, n2 < n3
	321 sa 231 rra	n1 > n2, n1 > n3, n2 > n3
*/

/*  pb 2 pa
	1000 4
	0100 ra 4
	0010 ra ra 4
	0001 rra 4
*/

/*	2 pa pa
	12000 pb pb 4
	10200 pb ra pb 4
	10020 pb ra ra pb 4
	10002 pb ra ra ra pb 4
	01200 ra pb pb 4
	01020 ra pb ra pb 4
	01002 ra pb ra ra pb 4
	00120 ra ra pb pb 4
	00102 ra ra pb ra pb 4
	00012 ra ra ra pb pb 4

*/

int		is_sorted(t_stack **stack_a, int size);
void	sort_small(t_stack **s_a, t_stack **s_b, int size);

void	sort_four(t_stack **s_a, t_stack **s_b)
{
	if ((*s_a)->value == 0)
		return (pb(s_a, s_b), sort_small(s_a, s_b, 3), pa(s_a, s_b));
	else if ((*s_a)->prev->value == 0)
		return (rra(s_a), sort_four(s_a, s_b));
	else
		return (ra(s_a), sort_four(s_a, s_b));
}

void	sort_five(t_stack **s_a, t_stack **s_b)
{
	int	count;

	count = 0;
	while (count < 2)
	{
		if ((*s_a)->value == 0 || (*s_a)->value == 1)
		{
			pb(s_a, s_b);
			count++;
		}
		else
			ra(s_a);
	}
	if ((*s_b)->value < (*s_b)->next->value)
		sb(s_b);
	sort_small(s_a, s_b, 3);
	pa(s_a, s_b);
	pa(s_a, s_b);
}

void	sort_small(t_stack **s_a, t_stack **s_b, int size)
{
	if (size <= 1 || is_sorted(s_a, size))
		return ;
	if (size == 2)
		return (sa(s_a));
	if (size == 3)
	{
		if ((*s_a)->next->value - (*s_a)->value == 2
			|| (*s_a)->next->value - (*s_a)->prev->value == 2)
			return (rra(s_a), sort_small(s_a, s_b, size));
		else if ((*s_a)->value - (*s_a)->next->value == 1)
			return (sa(s_a), sort_small(s_a, s_b, size));
		else
			return (ra(s_a), sort_small(s_a, s_b, size));
	}
	if (size == 4)
		sort_four(s_a, s_b);
	if (size == 5)
		sort_five(s_a, s_b);
}
