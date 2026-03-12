#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strcmp(const char *a, const char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return ((unsigned char)a[i] - (unsigned char)b[i]);
}

int	parse_int_strict(const char *s, int *out)
{
	long	value;
	int		sign;
	int		i;

	if (!s || !*s)
		return (0);
	sign = 1;
	i = 0;
	if (s[i] == '+')
		return (0);
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (!s[i])
		return (0);
	if (s[i] == '0' && s[i + 1] != '\0')
		return (0);
	if (sign == -1 && s[i] == '0')
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

void	putstr_fd(const char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
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
