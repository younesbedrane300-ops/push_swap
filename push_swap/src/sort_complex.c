/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybedrane <ybedrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:27:57 by ybedrane          #+#    #+#             */
/*   Updated: 2026/03/12 13:40:31 by ybedrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bit_count(int max)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	run_pass(t_ctx *ctx, int bit, int n)

{
	int	i;

	i = 0;
	while (i < n)
	{
		if (((ctx->a.data[0] >> bit) & 1) == 0)
			op_pb(ctx, 1);
		else
			op_ra(ctx, 1);
		i++;
	}
	while (ctx->b.size > 0)
		op_pa(ctx, 1);
}

void	sort_complex(t_ctx *ctx)
{
	int	bit;
	int	bits;
	int	n;

	ctx->strategy_name = "complex";
	ctx->complexity_class = "O(n log n)";
	n = ctx->a.size;
	if (n <= 1)
		return ;
	bits = bit_count(n - 1);
	bit = 0;
	while (bit < bits)
		run_pass(ctx, bit++, n);
}
