#include "inc/push_swap.h"

static void	free_stack(t_node **a)
{
	t_node	*temp;

	if (*a == NULL)
		return ;
	while ((*a)->next)
	{
		temp = (*a);
		(*a) = (*a)->next;
		free(temp);
	}
	free((*a));
}

static void	sort_and_free_stack(t_node *a, t_node *b)
{
	if (!check_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 0);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort(&a, &b);
	}
	free_stack(&a);
}

void	free_list(char **list)
{
	int	i;

	i = 0;
	if (!list)
		return ;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**list;
	int		i;

	a = NULL;
	b = NULL;
	list = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	if (argc == 2 && !argv[1][0])
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	while (i < argc && argc >= 2)
	{
		list = split(argv[i], ' ');
		put_stack_a(&a, list);
		i++;
		free_list(list);
	}
	sort_and_free_stack(a, b);
	return (0);
}
