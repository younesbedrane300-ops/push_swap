/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybedrane <ybedrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:08:00 by ybedrane          #+#    #+#             */
/*   Updated: 2026/03/12 13:38:11 by ybedrane         ###   ########.fr       */
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

void	op_rra(t_ctx *ctx, int emit)
{
	stack_reverse_rotate(&ctx->a);
	emit_op(ctx, OP_RRA, "rra\n", emit);
}

void	op_rrb(t_ctx *ctx, int emit)
{
	stack_reverse_rotate(&ctx->b);
	emit_op(ctx, OP_RRB, "rrb\n", emit);
}

void	op_rrr(t_ctx *ctx, int emit)
{
	stack_reverse_rotate(&ctx->a);
	stack_reverse_rotate(&ctx->b);
	emit_op(ctx, OP_RRR, "rrr\n", emit);
}
