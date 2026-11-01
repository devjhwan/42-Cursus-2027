/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-31 21:22:59 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-31 21:22:59 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_to_b(t_stack **stack_a, t_stack **stack_b, int size, int min);

static void	sort_small_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 1)
	{
		pa(stack_a, stack_b);
		return ;
	}
	if (size < 2 || size > 3 || stack_b == NULL || *stack_b == NULL)
		return ;
	if ((*stack_b)->value < (*stack_b)->next->value)
		sb(stack_b);
	if (size == 3 && (*stack_b)->next->value < (*stack_b)->next->next->value)
	{
		rb(stack_b);
		sb(stack_b);
		rrb(stack_b);
	}
	if (size == 3 && (*stack_b)->value < (*stack_b)->next->value)
		sb(stack_b);
	while (size--)
		pa(stack_a, stack_b);
}

static void	split_stack(t_stack **stack_a, t_stack **stack_b, t_pivot p, int sz)
{
	int	i;

	i = 0;
	while (i++ < sz)
	{
		if ((*stack_b)->value >= p.bg)
			pa(stack_a, stack_b);
		else if ((*stack_b)->value >= p.sm)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else
			rb(stack_b);
	}
}

static void	re_rotation(t_stack **st_a, t_stack **st_b, t_pivot p)
{
	int	i;
	int	rot_a;
	int	rot_b;

	i = 0;
	rot_a = p.bg - p.sm;
	rot_b = p.sm - p.min;
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

void	sort_b_to_a(t_stack **stack_a, t_stack **stack_b, int size, int min)
{
	t_pivot	p;

	if (size <= 3)
		return (sort_small_b(stack_a, stack_b, size));
	p.sm = size / 3 + min;
	p.bg = 2 * size / 3 + min;
	p.max = size + min;
	p.min = min;
	split_stack(stack_a, stack_b, p, size);
	sort_a_to_b(stack_a, stack_b, size + min - p.bg, p.bg);
	re_rotation(stack_a, stack_b, p);
	sort_a_to_b(stack_a, stack_b, p.bg - p.sm, p.sm);
	sort_b_to_a(stack_a, stack_b, p.sm - min, min);
}
