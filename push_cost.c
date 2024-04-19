/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:58:02 by tmontani          #+#    #+#             */
/*   Updated: 2024/04/19 16:24:45 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_cheapest(t_stack *stack_b)
{
	t_stack *cheapest;
	t_stack	*temp;
	
	temp = stack_b;
	cheapest = stack_b;
	while (temp)
	{
		if (cheapest->push_cost > temp->push_cost)
			cheapest = temp;
		temp = temp->next;
	}
	return (cheapest);
}

int   push_cost2(t_stack *stack_b, t_stack *stack_a, t_stack *current)
{
	int cost_b;
	int cost_a;

	cost_b = 0;
	cost_a = 0;
	if (current->above == 0 && current->target->above == 0)
	{
		cost_b = check_stack(stack_b) - (current->index - 1);
		cost_a = check_stack(stack_a) - (current->target->index - 1);
	}
	if (current->above == 0 && current->target->above == 1)
	{	cost_b = check_stack(stack_b) - (current->index - 1);
		cost_a = current->target->index - 1;
	}
	if (current->above == 1 && current->target->above == 1)
	{
		cost_b = current->index - 1;
		cost_a = current->target->index - 1;
	}
	if (current->above == 1 && current->target->above == 0)
	{
		cost_b = current->index - 1;
		cost_a = check_stack(stack_a) - (current->target->index - 1);
	}
	return (cost_a + cost_b);
}

void    push_cost1(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *current;

	current = stack_b;
	while (current)
	{
		current->push_cost = push_cost2(stack_b, stack_a, current);
		current = current->next;
	}
}