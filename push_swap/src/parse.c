/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybedrane <ybedrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:27:48 by ybedrane          #+#    #+#             */
/*   Updated: 2026/03/12 13:41:59 by ybedrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fill_ranks(t_ctx *ctx, int *vals, int *sorted, int n)
{
	int	i;

	i = 0;
	ctx->a.size = n;
	ctx->a.capacity = n;
	ctx->b.size = 0;
	ctx->b.capacity = n;
	ctx->disorder = compute_disorder(vals, n);
	i = 0;
	while (i < n)
	{
		ctx->a.data[i] = ps_binary_search(sorted, n, vals[i]);
		i++;
	}
	return (1);
}

static int	parse_core(t_ctx *ctx, int argc, char **argv, int n)
{
	int	*vals;
	int	*sorted;
	int	i;

	vals = (int *)malloc(sizeof(int) * n);
	sorted = (int *)malloc(sizeof(int) * n);
	if (!vals || !sorted)
		return (free(vals), free(sorted), 0);
	if (!ps_fill_values(vals, argc, argv, &ctx->config))
		return (free(vals), free(sorted), 0);
	i = 0;
	while (i < n)
	{
		sorted[i] = vals[i];
		i++;
	}
	ps_sort_ints(sorted, n);
	if (ps_has_duplicates(sorted, n) || !ps_alloc_stacks(ctx, n))
		return (free(vals), free(sorted), 0);
	if (!fill_ranks(ctx, vals, sorted, n))
		return (free(vals), free(sorted), 0);
	free(vals);
	free(sorted);
	return (1);
}

int	parse_input(t_ctx *ctx, int argc, char **argv)
{
	int	n;

	ctx->config.strategy = STRAT_ADAPTIVE;
	ctx->config.bench = 0;
	if (ps_has_invalid_empty_arg(argc, argv, 1))
		return (0);
	n = ps_count_tokens(argc, argv, 1);
	if (n == 0)
		return (1);
	return (parse_core(ctx, argc, argv, n));
}

void	free_ctx(t_ctx *ctx)
{
	free(ctx->a.data);
	free(ctx->b.data);
	ctx->a.data = NULL;
	ctx->b.data = NULL;
}
