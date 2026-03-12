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
		if (ft_strcmp(argv[i], "--bench") == 0 || ft_strcmp(argv[i], "--adaptive") == 0
			|| ft_strcmp(argv[i], "--simple") == 0 || ft_strcmp(argv[i], "--medium") == 0
			|| ft_strcmp(argv[i], "--complex") == 0)
		{
			i++;
			continue ;
		}
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
		if (ft_strcmp(argv[i], "--bench") == 0 || ft_strcmp(argv[i], "--adaptive") == 0
			|| ft_strcmp(argv[i], "--simple") == 0 || ft_strcmp(argv[i], "--medium") == 0
			|| ft_strcmp(argv[i], "--complex") == 0)
		{
			i++;
			continue ;
		}
		if (arg_is_only_spaces(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	cmp_int(const int *a, const int *b)
{
	if (*a < *b)
		return (-1);
	if (*a > *b)
		return (1);
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
		while (j >= 0 && cmp_int(&arr[j], &key) > 0)
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

static int	fill_values(int *vals, int argc, char **argv, t_config *cfg)
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
		else
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
		}
		i++;
	}
	return (1);
}

int	is_sorted_ascending(t_stack *stack)
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

double	compute_disorder(const int *arr, int n)
{
	long	mistakes;
	long	total;
	int		i;
	int		j;

	if (n < 2)
		return (0.0);
	mistakes = 0;
	total = 0;
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			total++;
			if (arr[i] > arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / (double)total);
}

int	parse_input(t_ctx *ctx, int argc, char **argv)
{
	int	*vals;
	int	*sorted;
	int	n;
	int	i;

	ctx->config.strategy = STRAT_ADAPTIVE;
	ctx->config.bench = 0;
	if (has_invalid_empty_arg(argc, argv))
		return (0);
	n = count_tokens(argc, argv);
	if (n == 0)
		return (1);
	vals = (int *)malloc(sizeof(int) * n);
	sorted = (int *)malloc(sizeof(int) * n);
	if (!vals || !sorted)
		return (free(vals), free(sorted), 0);
	if (!fill_values(vals, argc, argv, &ctx->config))
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
	ctx->disorder = compute_disorder(vals, n);
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

void	free_ctx(t_ctx *ctx)
{
	free(ctx->a.data);
	free(ctx->b.data);
	ctx->a.data = NULL;
	ctx->b.data = NULL;
}
