/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybedrane <ybedrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:27:27 by ybedrane          #+#    #+#             */
/*   Updated: 2026/03/12 13:39:59 by ybedrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	putstr_fd("Error\n", 2);
}

static void	print_disorder(t_ctx *ctx)
{
	long		centi_percent;
	long		total_pairs;
	long		mistakes;

	total_pairs = (long)ctx->a.capacity * (ctx->a.capacity - 1) / 2;
	mistakes = (long)(ctx->disorder * (double)total_pairs + 0.5);
	if (total_pairs == 0)
		centi_percent = 0;
	else
		centi_percent = (mistakes * 10000 + total_pairs / 2) / total_pairs;
	putstr_fd("[bench] disorder: ", 2);
	putnbr_fd(centi_percent / 100, 2);
	write(2, ".", 1);
	putu2_fd((unsigned int)(centi_percent % 100), 2);
	putstr_fd("%\n", 2);
}

static void	print_strategy_info(t_ctx *ctx)
{
	putstr_fd("[bench] strategy: ", 2);
	putstr_fd(ctx->strategy_name, 2);
	putstr_fd(" (", 2);
	putstr_fd(ctx->complexity_class, 2);
	putstr_fd(")\n", 2);
	putstr_fd("[bench] total_ops: ", 2);
	putnbr_fd(ctx->total_ops, 2);
	putstr_fd("\n", 2);
}

static void	print_op_counts(t_ctx *ctx)
{
	const char	*names[OP_COUNT];
	int			i;

	names[0] = "sa";
	names[1] = "sb";
	names[2] = "ss";
	names[3] = "pa";
	names[4] = "pb";
	names[5] = "ra";
	names[6] = "rb";
	names[7] = "rr";
	names[8] = "rra";
	names[9] = "rrb";
	names[10] = "rrr";
	i = 0;
	while (i < OP_COUNT)
	{
		putstr_fd("[bench] ", 2);
		putstr_fd(names[i], 2);
		putstr_fd(": ", 2);
		putnbr_fd(ctx->op_counts[i], 2);
		putstr_fd("\n", 2);
		i++;
	}
}

void	print_bench(t_ctx *ctx)
{
	print_disorder(ctx);
	print_strategy_info(ctx);
	print_op_counts(ctx);
}
