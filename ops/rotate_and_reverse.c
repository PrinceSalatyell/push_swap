/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:04:05 by josanton          #+#    #+#             */
/*   Updated: 2022/11/11 01:23:28 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*last;

	last = *stack;
	while (last->next)
		last = last->next;

	tmp = (*stack)->next;
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = tmp;
}

void	reverse(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*before_last;

	last = *stack;
	while (last->next)
		last = last->next;
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	before_last->next = NULL;
	tmp = *stack;
	*stack = last;
	(*stack)->next = tmp;
}
