#include "push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	arg_is_only_spaces(const char *s)
{
	int	j;

	j = 0;
	while (s[j] && is_space(s[j]))
		j++;
	return (s[j] == '\0');
}

static int	count_tokens(int argc, char **argv)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] && is_space(argv[i][j]))
				j++;
			if (argv[i][j])
				count++;
			while (argv[i][j] && !is_space(argv[i][j]))
				j++;
		}
		i++;
	}
	return (count);
}

static int	has_invalid_empty_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (arg_is_only_spaces(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	sort_ints(int *arr, int n)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

static int	binary_search(const int *arr, int n, int v)
{
	int	l;
	int	r;
	int	m;

	l = 0;
	r = n - 1;
	while (l <= r)
	{
		m = l + (r - l) / 2;
		if (arr[m] == v)
			return (m);
		if (arr[m] < v)
			l = m + 1;
		else
			r = m - 1;
	}
	return (-1);
}

static int	parse_token_span(const char *s, int start, int end, int *out)
{
	char	buf[32];
	int	len;
	int	i;

	len = end - start;
	if (len <= 0 || len >= (int)sizeof(buf))
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

static int	fill_values(int *vals, int argc, char **argv)
{
	int	idx;
	int	i;
	int	j;
	int	k;
	int	v;

	idx = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] && is_space(argv[i][j]))
				j++;
			k = j;
			while (argv[i][j] && !is_space(argv[i][j]))
				j++;
			if (j > k)
			{
				if (!parse_token_span(argv[i], k, j, &v))
					return (0);
				vals[idx++] = v;
			}
		}
		i++;
	}
	return (1);
}

int	parse_checker_input(t_ctx *ctx, int argc, char **argv)
{
	int	*vals;
	int	*sorted;
	int	n;
	int	i;

	if (has_invalid_empty_arg(argc, argv))
		return (0);
	n = count_tokens(argc, argv);
	if (n == 0)
		return (0);
	vals = (int *)malloc(sizeof(int) * n);
	sorted = (int *)malloc(sizeof(int) * n);
	if (!vals || !sorted)
		return (free(vals), free(sorted), 0);
	if (!fill_values(vals, argc, argv))
		return (free(vals), free(sorted), 0);
	i = -1;
	while (++i < n)
		sorted[i] = vals[i];
	sort_ints(sorted, n);
	i = 1;
	while (i < n)
	{
		if (sorted[i] == sorted[i - 1])
			return (free(vals), free(sorted), 0);
		i++;
	}
	ctx->a.data = (int *)malloc(sizeof(int) * n);
	ctx->b.data = (int *)malloc(sizeof(int) * n);
	if (!ctx->a.data || !ctx->b.data)
	{
		free(vals);
		free(sorted);
		free(ctx->a.data);
		free(ctx->b.data);
		ctx->a.data = NULL;
		ctx->b.data = NULL;
		return (0);
	}
	ctx->a.size = n;
	ctx->a.capacity = n;
	ctx->b.size = 0;
	ctx->b.capacity = n;
	i = 0;
	while (i < n)
	{
		ctx->a.data[i] = binary_search(sorted, n, vals[i]);
		i++;
	}
	free(vals);
	free(sorted);
	return (1);
}
