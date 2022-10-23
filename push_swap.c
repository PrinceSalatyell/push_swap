/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:53:27 by josanton          #+#    #+#             */
/*   Updated: 2022/10/23 02:36:30 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(char **argv)
{
	int	i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
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
			if (!ft_strncmp(argv[i], argv[j++], ft_strlen(argv[i])))
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
		if (ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) < -2147483648)
			return (NULL);
	}
	stack = malloc(sizeof(int) * n - 1);
	i = 0;
	while (argv[i + 1])
		stack[i] = atoi(argv[++i]);
	return (stack);
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;

	if (argc < 2)
		return (0);
	if (check_input(argv))
	{
		stack_a = parsing(argc, argv);
		if (stack_a == NULL)
		{
			ft_printf("Error!");
			return (0);
		}
		int i = argc - 1;
		ft_printf("stack a:\n");
		while (i)
		{
			ft_printf("%i\n", stack_a[i--]);
		}
	}
	else
		ft_printf("Error");
	return (0);
}
