#include "../inc/push_swap.h"

void	sort_three(t_node **a)
{
	t_node	*max;

	max = find_max(*a);
	if (max == *a)
		ra(a, 0);
	else if ((*a)->next == max)
		rra(a, 0);
	if ((*a)->data > (*a)->next->data)
		sa(a, 0);
}

void	rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rr(a, b, 0);
	set_median_and_index(*a);
	set_median_and_index(*b);
}

void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rrr(a, b, 0);
	set_median_and_index(*a);
	set_median_and_index(*b);
}

void	move_min_to_top(t_node **a)
{
	while ((*a)->data != find_min(*a)->data)
	{
		if (find_min(*a)->median_up)
			ra(a, 0);
		else
			rra(a, 0);
	}
}
