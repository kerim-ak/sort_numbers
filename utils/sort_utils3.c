#include "../inc/push_swap.h"

static void	case_three_a(t_node **a, t_node **b, t_node *ch)
{
	int		a_len;
	int		b_len;

	a_len = stack_len(*a);
	b_len = stack_len(*b);
	if (ch->i > ch->target_node->i)
		rotate_both(a, b, ch);
	else if ((b_len - ch->target_node->i) > (a_len - ch->i))
		rev_rotate_both(a, b, ch);
}

void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest;
	int		a_len;
	int		b_len;

	a_len = stack_len(*a);
	b_len = stack_len(*b);
	cheapest = get_cheapest(*a);
	if (cheapest->median_up && cheapest->target_node->median_up)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->median_up) && !(cheapest->target_node->median_up))
		rev_rotate_both(a, b, cheapest);
	else if (cheapest->median_up && !(cheapest->target_node->median_up))
		case_three_a(a, b, cheapest);
	else
	{
		if ((a_len - cheapest->i) > b_len - cheapest->target_node->i)
			rev_rotate_both(a, b, cheapest);
		else if (cheapest->target_node->i > cheapest->i)
			rotate_both(a, b, cheapest);
	}
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target_node, 'b');
	pb(b, a, 0);
}

static void	case_three_b(t_node **b, t_node **a, t_node *ch)
{
	int		a_len;
	int		b_len;

	a_len = stack_len(*a);
	b_len = stack_len(*b);
	if (ch->i > ch->target_node->i)
		rotate_both(b, a, ch);
	else if ((b_len - ch->target_node->i) > (a_len - ch->i))
		rev_rotate_both(b, a, ch);
}

void	move_b_to_a(t_node **a, t_node **b)
{
	t_node	*cheapest;
	int		a_len;
	int		b_len;

	a_len = stack_len(*a);
	b_len = stack_len(*b);
	cheapest = get_cheapest(*b);
	if (cheapest->median_up && cheapest->target_node->median_up)
		rotate_both(b, a, cheapest);
	else if (!(cheapest->median_up) && !(cheapest->target_node->median_up))
		rev_rotate_both(b, a, cheapest);
	else if (cheapest->median_up && !(cheapest->target_node->median_up))
		case_three_b(b, a, cheapest);
	else
	{
		if ((a_len - cheapest->i) > b_len - cheapest->target_node->i)
			rev_rotate_both(b, a, cheapest);
		else if (cheapest->target_node->i > cheapest->i)
			rotate_both(b, a, cheapest);
	}
	prep_for_push(b, cheapest, 'b');
	prep_for_push(a, cheapest->target_node, 'a');
	pa(a, b, 0);
}
