/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybedrane <ybedrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:10:00 by ybedrane          #+#    #+#             */
/*   Updated: 2026/03/12 13:39:12 by ybedrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_ints(int *arr, int n)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

int	ps_binary_search(const int *arr, int n, int v)
{
	int	l;
	int	r;
	int	m;

	l = 0;
	r = n - 1;
	while (l <= r)
	{
		m = l + (r - l) / 2;
		if (arr[m] == v)
			return (m);
		if (arr[m] < v)
			l = m + 1;
		else
			r = m - 1;
	}
	return (-1);
}

int	ps_has_duplicates(const int *sorted, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (sorted[i] == sorted[i - 1])
			return (1);
		i++;
	}
	return (0);
}
