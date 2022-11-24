/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:53:32 by josanton          #+#    #+#             */
/*   Updated: 2022/11/24 00:53:14 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}					t_stack;

void		swap(t_stack **stack_1, t_stack **stack_2, char c);

void		push(t_stack **stack_1, t_stack **stack_2, char c);

void		rotate(t_stack **stack_1, t_stack **stack_2, char c);

void		reverse(t_stack **stack_1, t_stack **stack_2, char c);

void		print_list(t_stack *list);

int			list_size(t_stack *list);

long long	*normalize(long long *numbers, int len);

void		radix_sort(t_stack **stack_a, t_stack **stack_b, int len);

int			is_sorted(t_stack *stack_a);

void		free_list(t_stack *list);

void		algo_for_three(t_stack **stack_a, int a, int b, int c);

void		algo_for_five(t_stack **stack_a, t_stack **stack_b);

#endif