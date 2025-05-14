#include "../inc/push_swap.h"

t_node	*find_last(t_node *a)
{
	t_node	*temp;

	temp = a;
	while (a->next)
	{
		temp = a->next;
		a = a->next;
	}
	return (temp);
}

static void	add_node(t_node **a, int data)
{
	t_node	*current;
	t_node	*last;

	if (!a)
		return ;
	current = malloc(sizeof(t_node));
	if (!current)
		return ;
	current->next = NULL;
	current->data = data;
	if (!(*a))
	{
		*a = current;
		current->prev = NULL;
	}
	else
	{
		last = find_last(*a);
		last->next = current;
		current->prev = last;
	}
}

static int	check_duplicate(t_node **a, int data)
{
	t_node	*temp;

	temp = *a;
	if (!temp)
		return (0);
	while (temp->next)
	{
		if (temp->data == data)
			return (1);
		temp = temp->next;
	}
	if (temp->data == data)
		return (1);
	return (0);
}

static void	free_error(t_node **a, char **list)
{
	t_node	*temp;

	if ((*a) == NULL)
	{
		ft_putendl_fd("Error", 2);
		free_list(list);
		exit(1);
	}
	while ((*a)->next)
	{
		temp = (*a);
		(*a) = (*a)->next;
		free(temp);
	}
	free((*a));
	ft_putendl_fd("Error", 2);
	free_list(list);
	exit(1);
}

void	put_stack_a(t_node **a, char **list)
{
	long	n;
	int		i;

	i = 0;
	if (!list[i])
		free_error(a, list);
	while (list[i])
	{
		if (check_error(list[i]))
			free_error(a, list);
		n = ft_atol(list[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_error(a, list);
		if (check_duplicate(a, (int)n))
			free_error(a, list);
		add_node(a, (int)n);
		i++;
	}
}
