#include "../inc/push_swap.h"

static void	push(t_node **dest, t_node **src)
{
	t_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

void	pa(t_node **a, t_node **b, int print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_node **b, t_node **a, int print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
