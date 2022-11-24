/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:36:53 by josanton          #+#    #+#             */
/*   Updated: 2022/11/24 00:57:38 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_for_five(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	if ((*stack_a)->next->next->next->next->number == 0)
		reverse(stack_a, NULL, 'a');
	else
	{
		while ((*stack_a)->number != 0)
			rotate(stack_a, NULL, 'a');
	}
	push(stack_a, stack_b, 'b');
	if ((*stack_a)->next->next->next->number == 1)
		reverse(stack_a, NULL, 'a');
	else
	{
		while ((*stack_a)->number != 1)
			rotate(stack_a, NULL, 'a');
	}
	push(stack_a, stack_b, 'b');
	algo_for_three(stack_a, 0, 0, 0);
	push(stack_b, stack_a, 'a');
	push(stack_b, stack_a, 'a');
}
