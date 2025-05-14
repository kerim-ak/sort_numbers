#include "../inc/push_swap.h"

static void	set_nodes_a(t_node *a, t_node *b)
{
	set_median_and_index(a);
	set_median_and_index(b);
	set_target_a(a, b);
	calculate_cost_a(a, b);
	set_cheapest(a);
}

static void	set_nodes_b(t_node *a, t_node *b)
{
	set_median_and_index(a);
	set_median_and_index(b);
	set_target_b(a, b);
	calculate_cost_b(a, b);
	set_cheapest(b);
}

void	sort(t_node **a, t_node **b)
{
	int	a_len;

	a_len = stack_len(*a);
	if (a_len-- > 3 && !check_sorted(*a))
		pb(b, a, 0);
	if (a_len-- > 3 && !check_sorted(*a))
		pb(b, a, 0);
	while (a_len-- > 3)
	{
		set_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		set_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_median_and_index(*a);
	move_min_to_top(a);
}
