/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:13:36 by tmontani          #+#    #+#             */
/*   Updated: 2024/04/19 15:28:16 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == '+')
		return (1);
	return (0);
}
int	check_special_chars(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (1);
		i++;
	}
		return (0);
}
int	check_same_nb(long nb, t_stack *stack_a)
{
	if (!stack_a)
		return (1);
		while (stack_a)
		{
			if (stack_a->value == nb)
				return (0);
			stack_a = stack_a->next;
		}
	return (1);
}
int	check_stack(t_stack *stack_a)
{
	int count;
	t_stack *temp;
	temp = stack_a;
	count = 0;

	if (stack_a == NULL)
		return(0);
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	if (count == 1)
		return (0);
	return (count);
}
void print_stack(t_stack **stack_a)
 {
 	t_stack *current;

 	current = *stack_a;
 	while (current != NULL)
 	{
 		printf("node: %d\n", current->value);
 		current = current->next;
 	}
 }