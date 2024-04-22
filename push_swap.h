/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:43:15 by tmontani          #+#    #+#             */
/*   Updated: 2024/04/22 17:47:35 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack	t_stack;

struct s_stack
{
	int				value;
	struct s_stack	*next;
	int				above;
	struct s_stack	*target;
	int				push_cost;
	int				index;
};

int		check_stack(t_stack *stack_a);
void	print_stack(t_stack **stack_a);
int		check_same_nb(long nb, t_stack *stack_a);
t_stack	*find_last_node(t_stack *stack_a);
int		check_special_chars(char *str);
int		ft_handle_operators(char *str);
int		ft_free(t_stack *stack_a);
int		ft_free_array(char **array);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_b, t_stack **stack_a);
int		rrr(t_stack **stack_a, t_stack **stack_b);
void	send_to_algo(t_stack **stack_a, int stack_len);
int		stack_sorted(t_stack *stack_a);
void	sort_3(t_stack **stack_a);
void	big_sort(t_stack **stack_a);
void	push_in_b(t_stack **stack_a, t_stack **stack_b);
void	find_target(t_stack *stack_a, t_stack *stack_b);
int		s_above(t_stack *stack);
void	set_above(t_stack *stack_a, t_stack *stack_b);
t_stack	*find_smallest(t_stack *stack_a);
void	find_index(t_stack *stack_a, t_stack *stack_b);
void	push_cost1(t_stack *stack_a, t_stack *stack_b);
int		push_cost2(t_stack *stack_b, t_stack *stack_a, t_stack *current);
t_stack	*find_cheapest(t_stack *stack_b);
void	ft_execute(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_a(t_stack *target, t_stack **stack_a);
void	ft_rotate_b(t_stack *cheapest, t_stack **stack_b);
void	last_sort(t_stack **stack_a);

#endif
