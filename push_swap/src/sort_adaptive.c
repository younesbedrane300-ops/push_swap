#include "push_swap.h"

void	sort_adaptive(t_ctx *ctx)
{
	ctx->strategy_name = "adaptive";
	ctx->complexity_class = "mixed (O(n^2) / O(n*sqrt(n)) / O(n log n))";
	if (ctx->disorder < 0.2)
		sort_simple(ctx);
	else if (ctx->disorder < 0.5)
		sort_medium(ctx);
	else
		sort_complex(ctx);
}
