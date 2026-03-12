/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybedrane <ybedrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:10:00 by ybedrane          #+#    #+#             */
/*   Updated: 2026/03/12 13:39:16 by ybedrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_alloc_stacks(t_ctx *ctx, int n)
{
	ctx->a.data = (int *)malloc(sizeof(int) * n);
	ctx->b.data = (int *)malloc(sizeof(int) * n);
	if (!ctx->a.data || !ctx->b.data)
	{
		free(ctx->a.data);
		free(ctx->b.data);
		ctx->a.data = NULL;
		ctx->b.data = NULL;
		return (0);
	}
	return (1);
}
