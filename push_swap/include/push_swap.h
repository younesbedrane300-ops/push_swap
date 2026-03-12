#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}t_strategy;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}t_op;

typedef struct s_stack
{
	int	*data;
	int	size;
	int	capacity;
}t_stack;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
}t_config;

typedef struct s_ctx
{
	t_stack			a;
	t_stack			b;
	t_config		config;
	long			op_counts[OP_COUNT];
	long			total_ops;
	double			disorder;
	const char		*strategy_name;
	const char		*complexity_class;
}t_ctx;

int		parse_input(t_ctx *ctx, int argc, char **argv);
void	free_ctx(t_ctx *ctx);

void	op_sa(t_ctx *ctx, int emit);
void	op_sb(t_ctx *ctx, int emit);
void	op_ss(t_ctx *ctx, int emit);
void	op_pa(t_ctx *ctx, int emit);
void	op_pb(t_ctx *ctx, int emit);
void	op_ra(t_ctx *ctx, int emit);
void	op_rb(t_ctx *ctx, int emit);
void	op_rr(t_ctx *ctx, int emit);
void	op_rra(t_ctx *ctx, int emit);
void	op_rrb(t_ctx *ctx, int emit);
void	op_rrr(t_ctx *ctx, int emit);

void	sort_simple(t_ctx *ctx);
void	sort_medium(t_ctx *ctx);
void	sort_complex(t_ctx *ctx);
void	sort_adaptive(t_ctx *ctx);

int		is_sorted_ascending(t_stack *stack);
double	compute_disorder(const int *arr, int n);

int		stack_push_top(t_stack *stack, int value);
int		stack_pop_top(t_stack *stack, int *value);
void	stack_rotate(t_stack *stack);
void	stack_reverse_rotate(t_stack *stack);

void	print_error(void);
void	print_bench(t_ctx *ctx);

size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *a, const char *b);
int		parse_int_strict(const char *s, int *out);
void	putstr_fd(const char *s, int fd);
void	putnbr_fd(long n, int fd);
void	putu2_fd(unsigned int n, int fd);

#endif
