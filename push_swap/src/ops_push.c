/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybedrane <ybedrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:08:00 by ybedrane          #+#    #+#             */
/*   Updated: 2026/03/12 13:37:47 by ybedrane         ###   ########.fr       */
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

void	op_pa(t_ctx *ctx, int emit)
{
	int	v;

	if (stack_pop_top(&ctx->b, &v))
		stack_push_top(&ctx->a, v);
	emit_op(ctx, OP_PA, "pa\n", emit);
}

void	op_pb(t_ctx *ctx, int emit)
{
	int	v;

	if (stack_pop_top(&ctx->a, &v))
		stack_push_top(&ctx->b, v);
	emit_op(ctx, OP_PB, "pb\n", emit);
}
