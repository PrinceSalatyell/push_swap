/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:28:08 by josanton          #+#    #+#             */
/*   Updated: 2022/11/10 23:03:30 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **stack_1, t_stack **stack_2, char c)
{
	t_stack	*tmp;

	if (*stack_1 == NULL)
		return ;
	tmp = *stack_1;
	*stack_1 = tmp->next;
	tmp->next = *stack_2;
	*stack_2 = tmp;
}

void	swap(t_stack **stack, char c)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}
