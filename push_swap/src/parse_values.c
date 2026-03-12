/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybedrane <ybedrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:10:00 by ybedrane          #+#    #+#             */
/*   Updated: 2026/03/12 13:42:22 by ybedrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_parse_token_span(const char *s, int start, int end, int *out)
{
	char	buf[32];
	int		len;
	int		i;

	len = end - start;
	if (len <= 0 || len >= (int) sizeof(buf))
		return (0);
	i = 0;
	while (i < len)
	{
		buf[i] = s[start + i];
		i++;
	}
	buf[i] = '\0';
	return (parse_int_strict(buf, out));
}

static int	fill_one_arg(const char *arg, int *vals, int *idx)
{
	int	j;
	int	k;
	int	v;

	j = 0;
	while (arg[j])
	{
		while (arg[j] && ps_is_space(arg[j]))
			j++;
		k = j;
		while (arg[j] && !ps_is_space(arg[j]))
			j++;
		if (j > k)
		{
			if (!ps_parse_token_span(arg, k, j, &v))
				return (0);
			vals[(*idx)++] = v;
		}
	}
	return (1);
}

int	ps_fill_values(int *vals, int argc, char **argv, t_config *cfg)
{
	int	i;
	int	idx;

	i = 1;
	idx = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			cfg->bench = 1;
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			cfg->strategy = STRAT_ADAPTIVE;
		else if (ft_strcmp(argv[i], "--simple") == 0)
			cfg->strategy = STRAT_SIMPLE;
		else if (ft_strcmp(argv[i], "--medium") == 0)
			cfg->strategy = STRAT_MEDIUM;
		else if (ft_strcmp(argv[i], "--complex") == 0)
			cfg->strategy = STRAT_COMPLEX;
		else if (!fill_one_arg(argv[i], vals, &idx))
			return (0);
		i++;
	}
	return (1);
}

int	ps_fill_checker_values(int *vals, int argc, char **argv)
{
	int	i;
	int	idx;

	i = 1;
	idx = 0;
	while (i < argc)
	{
		if (!fill_one_arg(argv[i], vals, &idx))
			return (0);
		i++;
	}
	return (1);
}
