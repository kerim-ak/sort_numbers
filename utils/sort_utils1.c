#include "../inc/push_swap.h"

int	stack_len(t_node *a)
{
	int	len;

	len = 0;
	if (!a)
		return (len);
	while (a->next)
	{
		a = a->next;
		len++;
	}
	len++;
	return (len);
}

int	check_sorted(t_node *a)
{
	if (a == NULL)
		return (1);
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

t_node	*find_max(t_node *stack)
{
	t_node	*max;

	max = stack;
	while (stack->next)
	{
		if (stack->next->data > max->data)
			max = stack->next;
		stack = stack->next;
	}
	if (stack->data > max->data)
		max = stack;
	return (max);
}

t_node	*find_min(t_node *stack)
{
	t_node	*min;

	min = stack;
	while (stack->next)
	{
		if (stack->next->data < min->data)
			min = stack->next;
		stack = stack->next;
	}
	if (stack->data < min->data)
		min = stack;
	return (min);
}

void	set_median_and_index(t_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->i = i;
		if (i <= median)
			stack->median_up = 1;
		else
			stack->median_up = 0;
		stack = stack->next;
		i++;
	}
}
