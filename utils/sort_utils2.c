#include "../inc/push_swap.h"

void	set_target_a(t_node *a, t_node *b)
{
	t_node	*cur_b;
	t_node	*target;
	long	target_value;

	while (a)
	{
		target_value = LONG_MIN;
		cur_b = b;
		while (cur_b)
		{
			if (cur_b->data < a->data && cur_b->data > target_value)
			{
				target_value = cur_b->data;
				target = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (target_value == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

void	set_target_b(t_node *a, t_node *b)
{
	t_node	*cur_a;
	t_node	*target;
	long	target_value;

	while (b)
	{
		target_value = LONG_MAX;
		cur_a = a;
		while (cur_a)
		{
			if (cur_a->data > b->data && cur_a->data < target_value)
			{
				target_value = cur_a->data;
				target = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (target_value == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	set_cheapest(t_node *stack)
{
	long	cheapest;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest)
		{
			cheapest = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->is_cheapest = 1;
}

t_node	*get_cheapest(t_node *stack)
{
	t_node	*cheapest;

	if (!stack)
		return (NULL);
	cheapest = stack;
	while (stack->next)
	{
		if (stack->next->cost < cheapest->cost)
			cheapest = stack->next;
		stack = stack->next;
	}
	if (stack->cost < cheapest->cost)
		cheapest = stack;
	return (cheapest);
}

void	prep_for_push(t_node **stack, t_node *target, char a_or_b)
{
	while (*stack != target)
	{
		if (a_or_b == 'a')
		{
			if (target->median_up)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (a_or_b == 'b')
		{
			if (target->median_up)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}
