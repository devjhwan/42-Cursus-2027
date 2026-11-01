/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-01 23:05:00 by junghwal          #+#    #+#             */
/*   Updated: 2026-11-01 23:05:00 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	buffer_add(int command)
{
	(void)command;
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*u_s1;
	const unsigned char	*u_s2;

	i = 0;
	u_s1 = (const unsigned char *)s1;
	u_s2 = (const unsigned char *)s2;
	while (i < n && u_s1[i] == u_s2[i] && u_s1[i] != '\0')
		i++;
	if (i == n)
		return (0);
	return ((int)(u_s1[i] - u_s2[i]));
}

static int	parse_command(const char *line)
{
	if (line == NULL)
		return (-1);
	if (ft_strncmp(line, "pa\n", 4) == 0)
		return (CMD_PA);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		return (CMD_PB);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		return (CMD_RA);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		return (CMD_RB);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		return (CMD_RR);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		return (CMD_RRA);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		return (CMD_RRB);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		return (CMD_RRR);
	else if (ft_strncmp(line, "sa\n", 4) == 0)
		return (CMD_SA);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		return (CMD_SB);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		return (CMD_SS);
	return (-1);
}

int	checker_apply_command(t_stack **stack_a, t_stack **stack_b,
		const char *line)
{
	int	command;

	command = parse_command(line);
	if (command == CMD_PA)
		pa(stack_a, stack_b);
	else if (command == CMD_PB)
		pb(stack_a, stack_b);
	else if (command == CMD_RA)
		ra(stack_a);
	else if (command == CMD_RB)
		rb(stack_b);
	else if (command == CMD_RR)
		rr(stack_a, stack_b);
	else if (command == CMD_RRA)
		rra(stack_a);
	else if (command == CMD_RRB)
		rrb(stack_b);
	else if (command == CMD_RRR)
		rrr(stack_a, stack_b);
	else if (command == CMD_SA)
		sa(stack_a);
	else if (command == CMD_SB)
		sb(stack_b);
	else if (command == CMD_SS)
		ss(stack_a, stack_b);
	else
		return (-1);
	return (0);
}
