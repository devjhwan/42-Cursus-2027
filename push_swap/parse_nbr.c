/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-31 15:48:42 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-31 15:48:42 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	parse_nbr(char *str, int *nbr)
{
	long	n;
	int		sign;

	if (str == NULL || nbr == NULL || *str == '\0')
		return (-1);
	n = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		return (-1);
	while (*str >= '0' && *str <= '9' && n < 1000000000)
		n = n * 10 + *(str++) - '0';
	if (*str != '\0')
		return (-1);
	n *= sign;
	if (n < INT_MIN || n > INT_MAX)
		return (-1);
	*nbr = (int)n;
	return (0);
}

int	isduplicated(t_stack **stack, int nbr)
{
	t_stack	*cur;

	if (stack == NULL || *stack == NULL)
		return (0);
	cur = *stack;
	while (1)
	{
		if (cur->value == nbr)
			return (1);
		cur = cur->next;
		if (cur == *stack)
			break ;
	}
	return (0);
}
