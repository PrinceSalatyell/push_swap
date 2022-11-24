/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:06:15 by josanton          #+#    #+#             */
/*   Updated: 2022/11/23 23:41:32 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_for_three(t_stack **stack_a, int a,
	int b, int c)
{

	a = (*stack_a)->number;
	b = (*stack_a)->next->number;
	c = (*stack_a)->next->next->number;

	if (a > b && b < c && c > a)
		swap(stack_a, NULL, 'a');
	else if (a > b && b > c
		&& c < a)
	{
		swap(stack_a, NULL, 'a');
		reverse(stack_a, NULL, 'a');
	}
	else if (a > b && b < c
		&& c < a)
		rotate(stack_a, NULL, 'a');
	else if (a < b && b > c
		&& c > a)
	{
		swap(stack_a, NULL, 'a');
		rotate(stack_a, NULL, 'a');
	}
	else if (a < b && b > c
		&& c < a)
		reverse(stack_a, NULL, 'a');
}