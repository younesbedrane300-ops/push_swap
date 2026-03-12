/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parse_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybedrane <ybedrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:27:36 by ybedrane          #+#    #+#             */
/*   Updated: 2026/03/12 13:42:30 by ybedrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fill_checker_ranks(t_ctx *ctx, int *vals, int *sorted, int n)
{
	int	i;

	i = 0;
	ctx->a.size = n;
	ctx->a.capacity = n;
	ctx->b.size = 0;
	ctx->b.capacity = n;
	while (i < n)
	{
		ctx->a.data[i] = ps_binary_search(sorted, n, vals[i]);
		i++;
	}
	return (1);
}

static int	parse_checker_core(t_ctx *ctx, int *vals, int *sorted, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		sorted[i] = vals[i];
		i++;
	}
	ps_sort_ints(sorted, n);
	if (ps_has_duplicates(sorted, n) || !ps_alloc_stacks(ctx, n))
		return (0);
	if (!fill_checker_ranks(ctx, vals, sorted, n))
		return (0);
	return (1);
}

int	parse_checker_input(t_ctx *ctx, int argc, char **argv)
{
	int	*vals;
	int	*sorted;
	int	n;

	if (ps_has_invalid_empty_arg(argc, argv, 0))
		return (0);
	n = ps_count_tokens(argc, argv, 0);
	if (n == 0)
		return (0);
	vals = (int *)malloc(sizeof(int) * n);
	sorted = (int *)malloc(sizeof(int) * n);
	if (!vals || !sorted)
		return (free(vals), free(sorted), 0);
	if (!ps_fill_checker_values(vals, argc, argv)
		|| !parse_checker_core(ctx, vals, sorted, n))
		return (free(vals), free(sorted), 0);
	free(vals);
	free(sorted);
	return (1);
}
