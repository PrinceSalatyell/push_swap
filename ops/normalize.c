/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:49:38 by josanton          #+#    #+#             */
/*   Updated: 2022/11/12 03:19:51 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long long	find_bigger(long long *numbers, int len)
{
	int			i;
	long long	bigger;

	bigger = numbers[0];
	i = 0;
	while (i < len)
	{
		if (numbers[i] > bigger)
			bigger = numbers[i];
		i++;
	}
	return (bigger);
}

long long	*normalize(long long *numbers, int len)
{
	int			i;
	long long	*nums;
	int			j;
	int			smaller;
	long long	bigger;

	bigger = find_bigger(numbers, len);
	nums = malloc(sizeof(long long) * len);
	i = 0;
	while (i < len)
	{
		smaller = 0;
		j = 0;
		while (j < len)
		{
			if (numbers[j] < numbers[smaller])
				smaller = j;
			j++;
		}
		numbers[smaller] = bigger + 1;
		nums[smaller] = i;
		i++;
	}
	free(numbers);
	return (nums);
}
