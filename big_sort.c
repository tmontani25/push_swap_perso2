/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:28:04 by tmontani          #+#    #+#             */
/*   Updated: 2024/04/22 16:50:45 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_in_b(t_stack **stack_a, t_stack **stack_b)
{
	while((*stack_a)->next->next->next)
	{
		pb(stack_b, stack_a);
	}
}
void big_sort(t_stack **stack_a, int stack_len)
{
	(void)stack_len;
	t_stack *stack_b;
	t_stack *temp;

	stack_b = NULL;
	push_in_b(stack_a, &stack_b);
	sort_3(stack_a);
	// puts("stack_a after sort_3\n");
	//  while ((*stack_a))
	// {
	//  	printf("nb: %d\n", (*stack_a)->value);
	//  	(*stack_a) = (*stack_a)->next;
	// }

	while (stack_b)
	{ 
		find_target(*stack_a, stack_b); // trouver toutes les targets avant de push le nombre OK
		find_index((*stack_a), stack_b);//trouver chaque index des deux stacks pour une position donnée
		temp = stack_b;
		// while(temp)
		// {
		// 	printf("nb: %d -> target: %d\n\n", temp->value, temp->target->value);
		// 	temp = temp->next;
		// }
		set_above((*stack_a), stack_b); // trouver pour chaque noeud s'il est dans la partie sup ou inf
		push_cost1((*stack_a), stack_b); // calculer le push_cost grace aux informations contenue dans chaque noeud
		ft_execute(stack_a, &stack_b);	//executer les mouvements necessaire apres avoir trouver le cheapest
		temp = stack_b;
	}
		last_sort(stack_a);

	find_index((*stack_a), stack_b);
// puts("stack finish:\n");
//print_stack(stack_a);
}