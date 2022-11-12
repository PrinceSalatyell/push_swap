/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:28:08 by josanton          #+#    #+#             */
/*   Updated: 2022/11/12 20:11:25 by josanton         ###   ########.fr       */
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
	ft_printf("p%c\n", c);
}

void	swap(t_stack **stack_1, t_stack **stack_2, char c)
{
	t_stack	*tmp;

	if (stack_2)
		swap(stack_2, NULL, 's');
	if (*stack_1 == NULL || (*stack_1)->next == NULL)
		return ;
	tmp = (*stack_1)->next;
	(*stack_1)->next = tmp->next;
	tmp->next = *stack_1;
	*stack_1 = tmp;
	if (!stack_2)
		ft_printf("s%c\n", c);
}
