#include "../inc/push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_node **a, int print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_node **b, int print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b, int print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}
