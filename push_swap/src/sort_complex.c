#include "push_swap.h"

void	sort_complex(t_ctx *ctx)
{
	int	max;
	int	bits;
	int	bit;
	int	i;
	int	n;

	ctx->strategy_name = "complex";
	ctx->complexity_class = "O(n log n)";
	n = ctx->a.size;
	if (n <= 1)
		return ;
	max = n - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	bit = 0;
	while (bit < bits)
	{
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
		bit++;
	}
}
