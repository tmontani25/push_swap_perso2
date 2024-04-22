/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:56:35 by tmontani          #+#    #+#             */
/*   Updated: 2024/04/22 17:28:03 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swapab(t_stack **head)
{
	t_stack	*temp;

	if (head == NULL || (*head)->next == NULL)
		return (0);
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	return (1);
}

int	sa(t_stack **stack_a)
{
	if (!ft_swapab(stack_a))
		return (0);
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stack **stack_b)
{
	if (!ft_swapab(stack_b))
		return (0);
	write(1, "sb\n", 3);
	return (1);
}
