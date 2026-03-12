/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybedrane <ybedrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:27:31 by ybedrane          #+#    #+#             */
/*   Updated: 2026/03/12 13:42:44 by ybedrane         ###   ########.fr       */
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
	ctx->strategy_name = "checker";
	ctx->complexity_class = "N/A";
	ctx->total_ops = 0;
	i = 0;
	while (i < OP_COUNT)
		ctx->op_counts[i++] = 0;
}

static int	is_sorted_ascending_checker(t_stack *stack)
{
	int	i;

	i = 0;
	while (i + 1 < stack->size)
	{
		if (stack->data[i] > stack->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	apply_instr(t_ctx *ctx, const char *s)
{
	if (ft_strcmp(s, "sa") == 0)
		op_sa(ctx, 0);
	else if (ft_strcmp(s, "sb") == 0)
		op_sb(ctx, 0);
	else if (ft_strcmp(s, "ss") == 0)
		op_ss(ctx, 0);
	else if (ft_strcmp(s, "pa") == 0)
		op_pa(ctx, 0);
	else if (ft_strcmp(s, "pb") == 0)
		op_pb(ctx, 0);
	else if (ft_strcmp(s, "ra") == 0)
		op_ra(ctx, 0);
	else if (ft_strcmp(s, "rb") == 0)
		op_rb(ctx, 0);
	else if (ft_strcmp(s, "rr") == 0)
		op_rr(ctx, 0);
	else if (ft_strcmp(s, "rra") == 0)
		op_rra(ctx, 0);
	else if (ft_strcmp(s, "rrb") == 0)
		op_rrb(ctx, 0);
	else if (ft_strcmp(s, "rrr") == 0)
		op_rrr(ctx, 0);
	else
		return (0);
	return (1);
}

static int	read_and_apply(t_ctx *ctx)
{
	char	c;
	char	line[5];
	int		len;

	len = 0;
	while (read(0, &c, 1) > 0)
	{
		if (c == '\n')
		{
			line[len] = '\0';
			if (!apply_instr(ctx, line))
				return (0);
			len = 0;
		}
		else
		{
			if (len >= 4)
				return (0);
			line[len++] = c;
		}
	}
	if (len != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	init_ctx(&ctx);
	if (argc == 1)
		return (0);
	if (!parse_checker_input(&ctx, argc, argv))
	{
		print_error();
		free_ctx(&ctx);
		return (1);
	}
	if (!read_and_apply(&ctx))
	{
		print_error();
		free_ctx(&ctx);
		return (1);
	}
	if (is_sorted_ascending_checker(&ctx.a) && ctx.b.size == 0)
		putstr_fd("OK\n", 1);
	else
		putstr_fd("KO\n", 1);
	free_ctx(&ctx);
	return (0);
}
