/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_metrics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybedrane <ybedrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:16:00 by ybedrane          #+#    #+#             */
/*   Updated: 2026/03/12 13:42:04 by ybedrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_ascending(t_stack *stack)
{
	int	i;

	i = 0;
	while (i + 1 < stack->size)
	{
		if (stack->data[i] > stack->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

double	compute_disorder(const int *arr, int n)
{
	long	mistakes;
	long	total;
	int		i;
	int		j;

	if (n < 2)
		return (0.0);
	mistakes = 0;
	total = 0;
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			total++;
			if (arr[i] > arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / (double)total);
}
