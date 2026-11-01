/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-01 17:05:33 by junghwal          #+#    #+#             */
/*   Updated: 2026-11-01 17:05:33 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_merge_codes(int command, int *target, int *skip,
		int *replacement)
{
	if (command == CMD_RA)
		return (*target = CMD_RB, *skip = CMD_RR,
			*replacement = CMD_RR, 1);
	if (command == CMD_RB)
		return (*target = CMD_RA, *skip = CMD_RR,
			*replacement = CMD_RR, 1);
	if (command == CMD_SA)
		return (*target = CMD_SB, *skip = CMD_SS,
			*replacement = CMD_SS, 1);
	if (command == CMD_SB)
		return (*target = CMD_SA, *skip = CMD_SS,
			*replacement = CMD_SS, 1);
	if (command == CMD_RRA)
		return (*target = CMD_RRB, *skip = CMD_RRR,
			*replacement = CMD_RRR, 1);
	if (command == CMD_RRB)
		return (*target = CMD_RRA, *skip = CMD_RRR,
			*replacement = CMD_RRR, 1);
	return (0);
}

int	buffer_merge_command(t_stack **buffer, int command)
{
	t_stack	*current;
	int		target;
	int		skip;
	int		replacement;

	if (buffer == NULL || !get_merge_codes(command, &target, &skip,
			&replacement) || *buffer == NULL)
		return (0);
	current = *buffer;
	while (1)
	{
		if (current->value == target)
			return (current->value = replacement, 1);
		if (current->value != skip)
			return (0);
		current = current->next;
		if (current == *buffer)
			return (0);
	}
}

void	buffer_print_command(int command)
{
	if (command == CMD_PA)
		ft_putstr_fd("pa\n", 1);
	else if (command == CMD_PB)
		ft_putstr_fd("pb\n", 1);
	else if (command == CMD_RA)
		ft_putstr_fd("ra\n", 1);
	else if (command == CMD_RB)
		ft_putstr_fd("rb\n", 1);
	else if (command == CMD_RR)
		ft_putstr_fd("rr\n", 1);
	else if (command == CMD_RRA)
		ft_putstr_fd("rra\n", 1);
	else if (command == CMD_RRB)
		ft_putstr_fd("rrb\n", 1);
	else if (command == CMD_RRR)
		ft_putstr_fd("rrr\n", 1);
	else if (command == CMD_SA)
		ft_putstr_fd("sa\n", 1);
	else if (command == CMD_SB)
		ft_putstr_fd("sb\n", 1);
	else if (command == CMD_SS)
		ft_putstr_fd("ss\n", 1);
}
