/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:28:04 by tmontani          #+#    #+#             */
/*   Updated: 2024/04/22 17:56:11 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_in_b(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->next->next->next)
	{
		pb(stack_b, stack_a);
	}
}

void	big_sort(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	push_in_b(stack_a, &stack_b);
	sort_3(stack_a);
	while (stack_b)
	{
		find_target(*stack_a, stack_b);
		find_index((*stack_a), stack_b);
		set_above((*stack_a), stack_b);
		push_cost1((*stack_a), stack_b);
		ft_execute(stack_a, &stack_b);
	}
	last_sort(stack_a);
	find_index((*stack_a), stack_b);
}
