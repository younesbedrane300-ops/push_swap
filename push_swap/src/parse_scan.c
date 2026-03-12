/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybedrane <ybedrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:10:00 by ybedrane          #+#    #+#             */
/*   Updated: 2026/03/12 13:44:05 by ybedrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	count_in_arg(const char *arg)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (arg[j])
	{
		while (arg[j] && ps_is_space(arg[j]))
			j++;
		if (arg[j])
			count++;
		while (arg[j] && !ps_is_space(arg[j]))
			j++;
	}
	return (count);
}

int	ps_count_tokens(int argc, char **argv, int with_flags)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (i < argc)
	{
		if (!with_flags || (ft_strcmp(argv[i], "--bench") != 0
				&& ft_strcmp(argv[i], "--adaptive") != 0
				&& ft_strcmp(argv[i], "--simple") != 0
				&& ft_strcmp(argv[i], "--medium") != 0
				&& ft_strcmp(argv[i], "--complex") != 0))
			count += count_in_arg(argv[i]);
		i++;
	}
	return (count);
}

static int	arg_is_empty(const char *arg)
{
	int	j;

	j = 0;
	while (arg[j] && ps_is_space(arg[j]))
		j++;
	return (arg[j] == '\0');
}

int	ps_has_invalid_empty_arg(int argc, char **argv, int with_flags)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (with_flags && (ft_strcmp(argv[i], "--bench") == 0
				|| ft_strcmp(argv[i], "--adaptive") == 0
				|| ft_strcmp(argv[i], "--simple") == 0
				|| ft_strcmp(argv[i], "--medium") == 0
				|| ft_strcmp(argv[i], "--complex") == 0))
		{
			i++;
			continue ;
		}
		if (arg_is_empty(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
