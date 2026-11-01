/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-31 14:20:30 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-31 14:20:30 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack	t_stack;
struct s_stack
{
	int		value;
	t_stack	*next;
	t_stack	*prev;
};

typedef struct s_pivot
{
	int	sm;
	int	bg;
	int	max;
	int	min;
}	t_pivot;

enum e_command
{
	CMD_PA,
	CMD_PB,
	CMD_RA,
	CMD_RB,
	CMD_RR,
	CMD_RRA,
	CMD_RRB,
	CMD_RRR,
	CMD_SA,
	CMD_SB,
	CMD_SS
};

//ft_utils
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char *str);
void	ft_free_arr(char **arr);
//stack
t_stack	*create_new_node(int value);
void	push_node(t_stack **stack, t_stack *node);
void	append_node(t_stack **stack, t_stack *node);
t_stack	*pop_node(t_stack **stack);
void	free_stack(t_stack **stack);
void	buffer_add(int command);
int		buffer_flush(void);
int		buffer_merge_command(t_stack **buffer, int command);
void	buffer_print_command(int command);
//parse
int		parse_nbr(char *str, int *nbr);
int		isduplicated(t_stack **stack, int nbr);
int		set_rank(t_stack **stack, int size);
//actions
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
//main function
void	sort(t_stack **stack_a, t_stack **stack_b, int size);

#endif