#include "../inc/push_swap.h"

static void	swap(t_node **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_node	**a, int print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_node **b, int print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_node **a, t_node **b, int print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
