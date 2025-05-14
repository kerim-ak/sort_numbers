#include "../inc/push_swap.h"

static void	case_two(t_node *first, int first_len, int second_len)
{
	if ((second_len - first->target_node->i) > (first_len - first->i))
		first->cost = second_len - first->target_node->i;
	else
		first->cost = first_len - first->i;
}

static void	case_three(t_node *first, int first_len, int second_len)
{
	first->cost = first->i + second_len - first->target_node->i;
	if ((second_len - first->target_node->i) > (first_len - first->i))
		first->cost = second_len - first->target_node->i;
	else if (first->i > first->target_node->i)
		first->cost = first->i;
}

static void	case_four(t_node *first, int first_len, int second_len)
{
	first->cost = first_len - first->i + first->target_node->i;
	if ((first_len - first->i) > (second_len - first->target_node->i))
		first->cost = first_len - first->i;
	else if (first->target_node->i > first->i)
		first->cost = first->target_node->i;
}

void	calculate_cost_a(t_node *a, t_node *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while (a)
	{
		if (a->median_up && a->target_node->median_up)
		{
			if (a->i > a->target_node->i)
				a->cost = a->i;
			else
				a->cost = a->target_node->i;
		}
		else if (!(a->median_up) && !(a->target_node->median_up))
			case_two(a, a_len, b_len);
		else if (a->median_up && !(a->target_node->median_up))
			case_three(a, a_len, b_len);
		else if (!(a->median_up) && a->target_node->median_up)
			case_four(a, a_len, b_len);
		a = a->next;
	}
}

void	calculate_cost_b(t_node *a, t_node *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while (b)
	{
		if (b->median_up && b->target_node->median_up)
		{
			if (b->i > b->target_node->i)
				b->cost = b->i;
			else
				b->cost = b->target_node->i;
		}
		else if (!(b->median_up) && !(b->target_node->median_up))
			case_two(b, b_len, a_len);
		else if (b->median_up && !(b->target_node->median_up))
			case_three(b, b_len, a_len);
		else if (!(b->median_up) && b->target_node->median_up)
			case_four(b, b_len, a_len);
		b = b->next;
	}
}
