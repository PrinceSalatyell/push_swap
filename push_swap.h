/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:53:32 by josanton          #+#    #+#             */
/*   Updated: 2022/11/10 23:58:02 by josanton         ###   ########.fr       */
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

void	swap(t_stack **stack, char c);

void	push(t_stack **stack_1, t_stack **stack_2, char c);

void	rotate(t_stack **stack, char c);

void	reverse(t_stack **stack, char c);

void	print_list(t_stack *list);

#endif