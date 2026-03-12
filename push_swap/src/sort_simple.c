/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybedrane <ybedrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:28:05 by ybedrane          #+#    #+#             */
/*   Updated: 2026/03/12 13:43:09 by ybedrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_stack *a)
{
	int	idx;
	int	best;

	idx = 1;
	best = 0;
	while (idx < a->size)
	{
		if (a->data[idx] < a->data[best])
			best = idx;
		idx++;
	}
	return (best);
}

void	sort_simple(t_ctx *ctx)
{
	int	idx;

	ctx->strategy_name = "simple";
	ctx->complexity_class = "O(n^2)";
	while (ctx->a.size > 0)
	{
		idx = find_min_index(&ctx->a);
		if (idx <= ctx->a.size / 2)
		{
			while (idx-- > 0)
				op_ra(ctx, 1);
		}
		else
		{
			idx = ctx->a.size - idx;
			while (idx-- > 0)
				op_rra(ctx, 1);
		}
		op_pb(ctx, 1);
	}
	while (ctx->b.size > 0)
		op_pa(ctx, 1);
}
