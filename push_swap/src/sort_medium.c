#include "push_swap.h"

static int	int_sqrt(int n)
{
	int	r;

	r = 0;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}

static int	find_max_index(t_stack *b)
{
	int	idx;
	int	best;

	idx = 1;
	best = 0;
	while (idx < b->size)
	{
		if (b->data[idx] > b->data[best])
			best = idx;
		idx++;
	}
	return (best);
}

void	sort_medium(t_ctx *ctx)
{
	int	i;
	int	chunk;
	int	n;
	int	max_idx;

	ctx->strategy_name = "medium";
	ctx->complexity_class = "O(n*sqrt(n))";
	n = ctx->a.size;
	chunk = int_sqrt(n) + 1;
	i = 0;
	while (ctx->a.size > 0)
	{
		if (ctx->a.data[0] <= i)
		{
			op_pb(ctx, 1);
			op_rb(ctx, 1);
			i++;
		}
		else if (ctx->a.data[0] <= i + chunk)
		{
			op_pb(ctx, 1);
			i++;
		}
		else
			op_ra(ctx, 1);
	}
	while (ctx->b.size > 0)
	{
		max_idx = find_max_index(&ctx->b);
		if (max_idx <= ctx->b.size / 2)
			while (max_idx-- > 0)
				op_rb(ctx, 1);
		else
		{
			max_idx = ctx->b.size - max_idx;
			while (max_idx-- > 0)
				op_rrb(ctx, 1);
		}
		op_pa(ctx, 1);
	}
}
