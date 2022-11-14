/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:20:27 by josanton          #+#    #+#             */
/*   Updated: 2022/11/14 22:54:04 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	int	n;

	n = -1;
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->number < n)
			return (0);
		n = stack_a->number;
		stack_a = stack_a->next;
	}
	return (1);
}

int	get_bit(int bit_index, int n)
{
	return (n >> bit_index & 1);
}

void	operations(t_stack **stack_a, t_stack **stack_b, int bit_index)
{
	int	size;
	int	i;

	while (*stack_b)
		push(stack_b, stack_a, 'a');
	size = list_size(*stack_a);
	i = 0;
	while (i < size)
	{
		if ((is_sorted(*stack_a) && *stack_b == NULL))
			break ;
		if (get_bit(bit_index, (*stack_a)->number))
			rotate(stack_a, NULL, 'a');
		else
			push(stack_a, stack_b, 'b');
		i++;
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = -1;
	while (++i < 33)
	{
		operations(stack_a, stack_b, i);
		if ((is_sorted(*stack_a) && *stack_b == NULL))
			break ;
	}
}
