/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:55:51 by tmontani          #+#    #+#             */
/*   Updated: 2024/04/22 17:44:14 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_reverse_rotate(t_stack **head)
{
	t_stack	*current_node;
	t_stack	*last_node;

	current_node = *head;
	if (head == NULL || (*head)->next == NULL)
		return (0);
	while (current_node->next != NULL && current_node->next->next != NULL)
	{
		current_node = current_node->next;
	}
	last_node = current_node->next;
	current_node->next = NULL;
	last_node->next = *head;
	*head = last_node;
	return (1);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
	return (1);
}

int	rra(t_stack **stack_a)
{
	if (!ft_reverse_rotate(stack_a))
		return (0);
	write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_stack **stack_b)
{
	if (!ft_reverse_rotate(stack_b))
		return (0);
	write(1, "rrb\n", 4);
	return (1);
}
