#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

typedef struct s_node
{
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
	int				cost;
	int				i;
	int				is_cheapest;
	int				median_up;
}					t_node;

void	pa(t_node **a, t_node **b, int print);
void	pb(t_node **a, t_node **b, int print);
void	rra(t_node **a, int print);
void	rrb(t_node **b, int print);
void	rrr(t_node **a, t_node **b, int print);
void	ra(t_node **a, int print);
void	rb(t_node **b, int print);
void	rr(t_node **a, t_node **b, int print);
void	sa(t_node	**a, int print);
void	sb(t_node **b, int print);
void	ss(t_node **a, t_node **b, int print);
void	calculate_cost_a(t_node *a, t_node *b);
void	calculate_cost_b(t_node *a, t_node *b);
int		check_error(char *str);
long	ft_atol(char *str);
t_node	*find_last(t_node *a);
void	put_stack_a(t_node **a, char **list);
int		stack_len(t_node *a);
int		check_sorted(t_node *a);
t_node	*find_max(t_node *stack);
t_node	*find_min(t_node *stack);
void	set_median_and_index(t_node *stack);
void	set_target_a(t_node *a, t_node *b);
void	set_target_b(t_node *a, t_node *b);
void	set_cheapest(t_node *stack);
t_node	*get_cheapest(t_node *stack);
void	prep_for_push(t_node **stack, t_node *target, char a_or_b);
void	move_a_to_b(t_node **a, t_node **b);
void	move_b_to_a(t_node **a, t_node **b);
void	sort_three(t_node **a);
void	rotate_both(t_node **a, t_node **b, t_node *cheapest);
void	move_min_to_top(t_node **a);
void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest);
void	sort(t_node **a, t_node **b);
char	**split(char *s, char c);
void	free_list(char **list);

#endif 