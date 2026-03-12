#include "push_swap.h"

int	stack_push_top(t_stack *stack, int value)
{
	int	idx;

	if (stack->size >= stack->capacity)
		return (0);
	idx = stack->size;
	while (idx > 0)
	{
		stack->data[idx] = stack->data[idx - 1];
		idx--;
	}
	stack->data[0] = value;
	stack->size++;
	return (1);
}

int	stack_pop_top(t_stack *stack, int *value)
{
	int	i;

	if (stack->size == 0)
		return (0);
	*value = stack->data[0];
	i = 0;
	while (i + 1 < stack->size)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->size--;
	return (1);
}

void	stack_rotate(t_stack *stack)
{
	int	top;
	int	i;

	if (stack->size <= 1)
		return ;
	top = stack->data[0];
	i = 0;
	while (i + 1 < stack->size)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->size - 1] = top;
}

void	stack_reverse_rotate(t_stack *stack)
{
	int	last;
	int	i;

	if (stack->size <= 1)
		return ;
	last = stack->data[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = last;
}
