/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:53:27 by josanton          #+#    #+#             */
/*   Updated: 2022/11/12 20:20:57 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				continue ;
			if (!ft_isdigit(argv[i][j]))
				return (0);
		}
		i++;
	}
	i = 0;
	while (argv[++i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!ft_strcmp(argv[i], argv[j++]))
				return (0);
		}
	}
	return (1);
}

long long	*parsing(int n, char **argv)
{
	int			i;
	long long	*stack;

	i = 0;
	while (argv[++i])
	{
		if (ft_atoll(argv[i]) > 2147483647 || ft_atoll(argv[i]) < -2147483648)
			return (NULL);
	}
	stack = malloc(sizeof(long long) * (n - 1));
	i = 0;
	while (argv[i + 1])
	{
		stack[i] = atoll(argv[i + 1]);
		i++;
	}
	return (stack);
}

long long	*sort(long long *numbers, int len)
{
	long long	*res;
	int			i;

	i = 0;
	res = malloc(sizeof(long long) * (len));
	while (i < len)
	{
		res[i] = numbers[i];
		i++;
	}
	ft_quicksort(res, len);
	return (res);
}

t_stack	*put_in_list(long long *numbers, int size)
{
	t_stack	*res;
	t_stack	*tmp;
	t_stack	*end;
	int		i;

	res = malloc(sizeof(t_stack));
	res->next = NULL;
	res->number = numbers[0];
	i = 0;
	end = res;
	while (++i < size)
	{
		tmp = malloc(sizeof(t_stack));
		tmp->next = NULL;
		tmp->number = numbers[i];
		end->next = tmp;
		end = tmp;
	}
	tmp = res;
}

int	main(int argc, char **argv)
{
	long long		*stack;
	t_stack			*stack_a;
	t_stack			*stack_b;
	long long		*sorted;
	int				i;

	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (check_input(argv, 1, 0))
	{
		stack = parsing(argc, argv);
		if (stack == NULL)
		{
			ft_printf("Error!");
			return (0);
		}
		sorted = sort(stack, argc - 1);
		stack = normalize(stack, argc -1);
		stack_a = put_in_list(stack, argc - 1);
		radix_sort(&stack_a, &stack_b);
	}
	else
		ft_printf("Error");
	return (0);
}
