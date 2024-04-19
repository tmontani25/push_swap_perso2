/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:57:01 by tmontani          #+#    #+#             */
/*   Updated: 2024/04/19 16:31:47 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_push(t_stack **stack_1, t_stack **stack_2)
{
	if (stack_1 == NULL)
		return (0);

	t_stack *head_1;

	head_1 = *stack_1;
	
	(*stack_1) = (*stack_1)->next; //permet de supprimer le premier noeud de la stack_1
	head_1->next = (*stack_2);
	(*stack_2) = head_1;
	return (1);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	
	if(!ft_push(stack_a, stack_b))
		return (0);
	write(1, "pa\n", 3);
	return (1);
}

int pb(t_stack **stack_b, t_stack **stack_a)
{	
	if(!ft_push(stack_a, stack_b))
		return (0);
	write(1, "pb\n", 3);
	return (1);
}