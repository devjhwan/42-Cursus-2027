/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-31 21:21:52 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-31 21:21:52 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_to_a(t_stack **stack_a, t_stack **stack_b, int size, int min);

static void	sort_small_a(t_stack **stack_a, int size)
{
	if (size < 2 || size > 3 || stack_a == NULL || *stack_a == NULL)
		return ;
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
	if (size == 3 && (*stack_a)->next->value > (*stack_a)->next->next->value)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	if (size == 3 && (*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

static void	split_stack(t_stack **stack_a, t_stack **stack_b, t_pivot p, int sz)
{
	int	i;

	i = 0;
	while (i++ < sz)
	{
		if ((*stack_a)->value >= p.bg)
			ra(stack_a);
		else if ((*stack_a)->value >= p.sm)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else
			pb(stack_a, stack_b);
	}
}

static void	re_rotation(t_stack **st_a, t_stack **st_b, t_pivot p)
{
	int	i;
	int	rot_a;
	int	rot_b;

	i = 0;
	rot_a = p.max - p.bg;
	rot_b = p.bg - p.sm;
	while (i < rot_a && i < rot_b)
	{
		rrr(st_a, st_b);
		i++;
	}
	while (i < rot_a)
	{
		rra(st_a);
		i++;
	}
	while (i < rot_b)
	{
		rrb(st_b);
		i++;
	}
}

void	sort_a_to_b(t_stack **stack_a, t_stack **stack_b, int size, int min)
{
	t_pivot	p;

	if (size <= 3)
		return (sort_small_a(stack_a, size));
	p.sm = size / 3 + min;
	p.bg = 2 * size / 3 + min;
	p.max = size + min;
	p.min = min;
	split_stack(stack_a, stack_b, p, size);
	re_rotation(stack_a, stack_b, p);
	sort_a_to_b(stack_a, stack_b, size + min - p.bg, p.bg);
	sort_b_to_a(stack_a, stack_b, p.bg - p.sm, p.sm);
	sort_b_to_a(stack_a, stack_b, p.sm - min, min);
}
