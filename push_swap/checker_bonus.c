/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-01 21:59:00 by junghwal          #+#    #+#             */
/*   Updated: 2026-11-01 21:59:00 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line_bonus.h"

int		checker_apply_command(t_stack **stack_a, t_stack **stack_b,
			const char *line);

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

static int	read_commands(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int		status;

	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		status = checker_apply_command(stack_a, stack_b, line);
		free(line);
		if (status < 0)
			return (-1);
		line = get_next_line(STDIN_FILENO);
	}
	return (0);
}

static int	is_sorted(t_stack *stack_a, t_stack *stack_b, int size)
{
	int		rank;
	t_stack	*node;

	if (stack_b != NULL || stack_a == NULL)
		return (0);
	node = stack_a;
	rank = 0;
	while (rank < size)
	{
		if (node->value != rank)
			return (0);
		node = node->next;
		rank++;
	}
	return (1);
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
	if (read_commands(&stack_a, &stack_b) < 0)
		return (free_stack(&stack_a), free_stack(&stack_b),
			ft_putstr_fd("Error\n", 2), -1);
	if (is_sorted(stack_a, stack_b, size))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
