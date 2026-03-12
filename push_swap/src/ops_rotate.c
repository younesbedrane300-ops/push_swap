#include "push_swap.h"

static void	emit_op(t_ctx *ctx, t_op op, const char *txt, int emit)
{
	ctx->op_counts[op]++;
	ctx->total_ops++;
	if (emit)
		putstr_fd(txt, 1);
}

void	op_ra(t_ctx *ctx, int emit)
{
	stack_rotate(&ctx->a);
	emit_op(ctx, OP_RA, "ra\n", emit);
}

void	op_rb(t_ctx *ctx, int emit)
{
	stack_rotate(&ctx->b);
	emit_op(ctx, OP_RB, "rb\n", emit);
}

void	op_rr(t_ctx *ctx, int emit)
{
	stack_rotate(&ctx->a);
	stack_rotate(&ctx->b);
	emit_op(ctx, OP_RR, "rr\n", emit);
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
