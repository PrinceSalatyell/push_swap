/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:04:05 by josanton          #+#    #+#             */
/*   Updated: 2022/11/12 20:10:13 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack_1, t_stack **stack_2, char c)
{
	t_stack	*tmp;
	t_stack	*last;

	if (stack_2)
		rotate(stack_2, NULL, 'r');
	if (*stack_1 == NULL || (*stack_1)->next == NULL)
		return ;
	last = *stack_1;
	while (last->next)
		last = last->next;
	tmp = (*stack_1)->next;
	last->next = *stack_1;
	(*stack_1)->next = NULL;
	*stack_1 = tmp;
	if (!stack_2)
		ft_printf("r%c\n", c);
}

void	reverse(t_stack **stack_1, t_stack **stack_2, char c)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*before_last;

	if (stack_2)
		reverse(stack_2, NULL, 'r');
	if (*stack_1 == NULL || (*stack_1)->next == NULL)
		return ;
	last = *stack_1;
	while (last->next)
		last = last->next;
	before_last = *stack_1;
	while (before_last->next->next)
		before_last = before_last->next;
	before_last->next = NULL;
	tmp = *stack_1;
	*stack_1 = last;
	(*stack_1)->next = tmp;
	if (!stack_2)
		ft_printf("rr%c\n", c);
}
