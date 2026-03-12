/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybedrane <ybedrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:05:00 by ybedrane          #+#    #+#             */
/*   Updated: 2026/03/12 13:37:41 by ybedrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_prefix(const char *s, int *sign, int *i)
{
	*sign = 1;
	*i = 0;
	if (!s || !*s || s[*i] == '+')
		return (0);
	if (s[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	if (!s[*i])
		return (0);
	if (s[*i] == '0' && s[*i + 1] != '\0')
		return (0);
	if (*sign == -1 && s[*i] == '0')
		return (0);
	return (1);
}

int	parse_int_strict(const char *s, int *out)
{
	long	value;
	int		sign;
	int		i;

	if (!parse_prefix(s, &sign, &i))
		return (0);
	value = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		value = value * 10 + (s[i] - '0');
		if (sign * value > 2147483647L || sign * value < -2147483648L)
			return (0);
		i++;
	}
	*out = (int)(sign * value);
	return (1);
}

void	putnbr_fd(long n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		putnbr_fd(n / 10, fd);
	c = '0' + (char)(n % 10);
	write(fd, &c, 1);
}

void	putu2_fd(unsigned int n, int fd)
{
	char	buf[2];

	buf[0] = '0' + (char)((n / 10) % 10);
	buf[1] = '0' + (char)(n % 10);
	write(fd, buf, 2);
}
