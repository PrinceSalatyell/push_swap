/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:53:27 by josanton          #+#    #+#             */
/*   Updated: 2022/11/10 23:58:10 by josanton         ###   ########.fr       */
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

int	*parsing(int n, char **argv)
{
	int	i;
	int	*stack;

	i = 0;
	while (argv[++i])
	{
		if (ft_atoll(argv[i]) > 2147483647 || ft_atoll(argv[i]) < -2147483648)
			return (NULL);
	}
	stack = malloc(sizeof(int) * (n - 1));
	i = 0;
	while (argv[i + 1])
	{
		stack[i] = atoi(argv[i + 1]);
		i++;
	}
	return (stack);
}

int	*sort(int *numbers, int len)
{
	int	*res;
	int	i;

	i = 0;
	res = malloc(sizeof(int) * (len));
	while (i < len)
	{
		res[i] = numbers[i];
		i++;
	}
	ft_quicksort(res, len);
	return (res);
}

t_stack	*put_in_list(int *numbers, int size)
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
	int		*stack;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*sorted;
	int		i;

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
		stack_a = put_in_list(stack, argc - 1);
		stack_b = NULL;
		print_list(stack_a);
		reverse(&stack_a, 'a');
		ft_printf("\n");
		print_list(stack_a);
	}
	else
		ft_printf("Error");
	return (0);
}
