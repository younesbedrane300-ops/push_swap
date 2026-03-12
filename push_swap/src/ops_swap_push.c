/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybedrane <ybedrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:27:12 by ybedrane          #+#    #+#             */
/*   Updated: 2026/03/12 13:37:41 by ybedrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	emit_op(t_ctx *ctx, t_op op, const char *txt, int emit)
{
	ctx->op_counts[op]++;
	ctx->total_ops++;
	if (emit)
		putstr_fd(txt, 1);
}

void	op_sa(t_ctx *ctx, int emit)
{
	int	tmp;

	if (ctx->a.size > 1)
	{
		tmp = ctx->a.data[0];
		ctx->a.data[0] = ctx->a.data[1];
		ctx->a.data[1] = tmp;
	}
	emit_op(ctx, OP_SA, "sa\n", emit);
}

void	op_sb(t_ctx *ctx, int emit)
{
	int	tmp;

	if (ctx->b.size > 1)
	{
		tmp = ctx->b.data[0];
		ctx->b.data[0] = ctx->b.data[1];
		ctx->b.data[1] = tmp;
	}
	emit_op(ctx, OP_SB, "sb\n", emit);
}

void	op_ss(t_ctx *ctx, int emit)
{
	int	tmp;

	if (ctx->a.size > 1)
	{
		tmp = ctx->a.data[0];
		ctx->a.data[0] = ctx->a.data[1];
		ctx->a.data[1] = tmp;
	}
	if (ctx->b.size > 1)
	{
		tmp = ctx->b.data[0];
		ctx->b.data[0] = ctx->b.data[1];
		ctx->b.data[1] = tmp;
	}
	emit_op(ctx, OP_SS, "ss\n", emit);
}
