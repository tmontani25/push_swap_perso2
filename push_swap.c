/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:20:25 by tmontani          #+#    #+#             */
/*   Updated: 2024/04/19 16:30:24 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last_node(t_stack *stack_a)
{
    t_stack *current;
	
	current = stack_a;

    while (current->next)
        current = current->next;
    return (current);
}

void	add_new_node(long atoi_result, t_stack **stack_a)
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack));

	new_node->value = atoi_result;
	new_node->next = NULL;
	if (!(*stack_a))
		*stack_a = new_node;
	else
		find_last_node(*stack_a)->next = new_node;
}

int	ft_handle_str(char **array, t_stack **stack_a)
{
	long	atoi_result;
	int		j;
	int		stack_len;

	atoi_result = 0;
	j = 0;
	while(array[j])
	{
		if(check_special_chars(array[j]))
			return (ft_free(*stack_a));
		if (!ft_handle_operators(array[j]))
			return (ft_free(*stack_a));
		atoi_result = ft_atoi(array[j]);
		if (atoi_result > INT_MAX || atoi_result < INT_MIN)
				return (ft_free(*stack_a));
		if(!check_same_nb(atoi_result, *stack_a))
				return (ft_free(*stack_a));
		add_new_node(atoi_result, stack_a);
		j++;
	}
	stack_len = check_stack((*stack_a));
	send_to_algo(stack_a, stack_len);
	return (0);
}

int main (int argc, char **argv)
{
	t_stack *stack_a;
	char	**result_of_split;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		result_of_split = ft_split(argv[1], ' ');
		if (!result_of_split)
			return (0);
		ft_handle_str(result_of_split, &stack_a);
		ft_free_array(result_of_split);
	}
	else
		ft_handle_str(argv+1, &stack_a);
	exit(0);
}
