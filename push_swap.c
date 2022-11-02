/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:53:27 by josanton          #+#    #+#             */
/*   Updated: 2022/11/02 23:00:06 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (j == 0 && (argv[i][j++] == '-' || argv[i][j - 1] == '+'))
				continue ;
			if (!ft_isdigit(argv[i][j++]))
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
		if (ft_atolll(argv[i]) > 2147483647 || ft_atolll(argv[i]) < -2147483648)
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

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	*sorted;
	int	i;

	if (argc < 2)
		return (0);
	if (check_input(argv, 1, 0))
	{
		stack_a = parsing(argc, argv);
		if (stack_a == NULL)
		{
			ft_printf("Error!");
			return (0);
		}
		sorted = sort(stack_a, argc - 1);
	}
	else
		ft_printf("Error");
	return (0);
}
