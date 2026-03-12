/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybedrane <ybedrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:27:42 by ybedrane          #+#    #+#             */
/*   Updated: 2026/03/12 13:43:20 by ybedrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_ctx(t_ctx *ctx)
{
	int	i;

	ctx->a.data = NULL;
	ctx->a.size = 0;
	ctx->a.capacity = 0;
	ctx->b.data = NULL;
	ctx->b.size = 0;
	ctx->b.capacity = 0;
	ctx->config.strategy = STRAT_ADAPTIVE;
	ctx->config.bench = 0;
	ctx->disorder = 0.0;
	ctx->strategy_name = "adaptive";
	ctx->complexity_class = "mixed";
	ctx->total_ops = 0;
	i = 0;
	while (i < OP_COUNT)
		ctx->op_counts[i++] = 0;
}

static void	run_strategy(t_ctx *ctx)
{
	if (ctx->a.size <= 1 || is_sorted_ascending(&ctx->a))
	{
		ctx->strategy_name = "none-needed";
		ctx->complexity_class = "O(1)";
		return ;
	}
	if (ctx->a.size == 2)
	{
		ctx->strategy_name = "tiny";
		ctx->complexity_class = "O(1)";
		op_sa(ctx, 1);
		return ;
	}
	if (ctx->config.strategy == STRAT_SIMPLE)
		sort_simple(ctx);
	else if (ctx->config.strategy == STRAT_MEDIUM)
		sort_medium(ctx);
	else if (ctx->config.strategy == STRAT_COMPLEX)
		sort_complex(ctx);
	else
		sort_adaptive(ctx);
}

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	init_ctx(&ctx);
	if (argc == 1)
		return (0);
	if (!parse_input(&ctx, argc, argv))
	{
		print_error();
		free_ctx(&ctx);
		return (1);
	}
	if (ctx.a.size == 0)
	{
		free_ctx(&ctx);
		return (0);
	}
	run_strategy(&ctx);
	if (ctx.config.bench)
		print_bench(&ctx);
	free_ctx(&ctx);
	return (0);
}
