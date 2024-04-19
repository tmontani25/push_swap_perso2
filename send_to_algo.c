/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:38:29 by tmontani          #+#    #+#             */
/*   Updated: 2024/04/05 13:23:34 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_algo(t_stack **stack_a, int stack_len)
{
	// print_stack(stack_a);
	if (stack_len == 0)
		return ;
	else if (stack_len == 2)
		if((*stack_a)->next->value < (*stack_a)->value)
			sa(stack_a);
	if (stack_sorted((*stack_a)))
		return ;
	if (stack_len == 3)
		sort_3(stack_a);
	if (stack_len > 3)
	{
		big_sort(stack_a, stack_len);
	}
		return ;
}