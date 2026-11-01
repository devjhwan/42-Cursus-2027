/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-31 15:22:23 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-31 15:22:23 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	fill_stack(t_stack **stack_a, char *str)
{
	t_stack	*node;
	int		nbr;

	if (parse_nbr(str, &nbr) < 0)
		return (-1);
	if (isduplicated(stack_a, nbr))
		return (-1);
	node = create_new_node(nbr);
	if (node == NULL)
		return (-1);
	append_node(stack_a, node);
	return (0);
}

static int	parse_argv(t_stack **stack_a, char **argv)
{
	char	**nb_arr;
	int		idx;
	int		size;

	if (stack_a == NULL)
		return (-1);
	size = 0;
	while (*(++argv) != NULL)
	{
		nb_arr = ft_split(*argv);
		if (nb_arr == NULL)
			return (-1);
		idx = 0;
		while (nb_arr[idx] != NULL)
		{
			if (fill_stack(stack_a, nb_arr[idx]))
				return (ft_free_arr(nb_arr), -1);
			size++;
			idx++;
		}
		ft_free_arr(nb_arr);
	}
	return (size);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	size = parse_argv(&stack_a, argv);
	if (size < 0)
		return (free_stack(&stack_a), ft_putstr_fd("Error\n", 2), -1);
	if (size == 0)
		return (free_stack(&stack_a), 0);
	if (set_rank(&stack_a, size) < 0)
		return (free_stack(&stack_a), ft_putstr_fd("Error\n", 2), -1);
	sort(&stack_a, &stack_b, size);
	if (buffer_flush() < 0)
		return (free_stack(&stack_a), free_stack(&stack_b),
			ft_putstr_fd("Error\n", 2), -1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
