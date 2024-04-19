/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:50:22 by tmontani          #+#    #+#             */
/*   Updated: 2024/04/15 20:41:04 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	last_sort(t_stack **stack_a)
{
	t_stack *smallest;
	smallest = find_smallest((*stack_a));
	if (smallest->above == 1)
	{
		while (smallest != (*stack_a))
		{
			ra(stack_a);
		}
	}
	if (smallest->above == 0)
	{
		while (smallest != (*stack_a))
		{
			rra(stack_a);
		}
	}
}
void ft_rotate_b(t_stack *cheapest, t_stack **stack_b)
{
	while (cheapest != (*stack_b))
	{
		if (cheapest->above == 0)
			rrb(stack_b);
		else if (cheapest->above == 1)
			rb(stack_b);
	}
}

void	ft_rotate_a(t_stack *target, t_stack **stack_a)
{
	while (target != (*stack_a))
	{
		if (target->above == 0)
			rra(stack_a);
		else if (target->above == 1)
			ra(stack_a);
	}
}

void	ft_execute(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest((*stack_b));
	// puts("stack_a:\n");
	// print_stack(stack_a);
	// puts("stack_b:\n");
	// print_stack(stack_b);
	// printf("cheapest: %d\n\n", cheapest->value);
	if (cheapest->above == 1 && cheapest->target->above == 1)
	{
		while (cheapest != (*stack_b) && cheapest->target != (*stack_a))
		{
			rr(stack_a, stack_b);
		}
	}
	else if (cheapest->above == 0 && cheapest->target->above == 0)
	{
		// printf("cheapest->above: %d\n", cheapest->above);
		// printf("cheapest->target->above: %d\n\n", cheapest->target->above);
		while (cheapest != (*stack_b) && cheapest->target != (*stack_a))
		{
			rrr(stack_a, stack_b);
		}	
			// puts("get in there mf");
			// printf("cheapest above: %d\n", cheapest->above);
		 	// printf("cheapest target above: %d\n", cheapest->target->above);
	}
	// printf("cheapest value %d\n", cheapest->value);
	// printf("cheapest push_cost %d\n", cheapest->push_cost);
		if (cheapest != (*stack_b))
			ft_rotate_b(cheapest, stack_b);
		if (cheapest->target != (*stack_a))
		{
			//printf("cheapest->target: %d\n", cheapest->target->value);
			ft_rotate_a(cheapest->target, stack_a);
		}

	pa(stack_b, stack_a);
}