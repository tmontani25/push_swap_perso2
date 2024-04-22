/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:57:06 by tmontani          #+#    #+#             */
/*   Updated: 2024/04/22 17:40:03 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rotate(t_stack **head)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*current_node;

	first_node = (*head);
	second_node = (*head)->next;
	current_node = *head;
	if (head == NULL || (*head)->next == NULL)
		return (0);
	current_node = find_last_node(*head);
	current_node->next = first_node;
	(*head) = second_node;
	first_node->next = NULL;
	return (1);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
	return (1);
}

int	ra(t_stack **stack_a)
{
	if (!ft_rotate(stack_a))
		return (0);
	write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stack **stack_b)
{
	if (!ft_rotate(stack_b))
		return (0);
	write(1, "rb\n", 3);
	return (1);
}
