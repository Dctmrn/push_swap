#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../.ft/gnl/gnl.h"
# include "../.ft/libft/libft.h"
# include "../.ft/printf/ft_printf.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				cost;
	int				over_med;
	int				cheap;
	struct s_stack	*target;			
	struct s_stack	*next;
}	t_stack;

//COMMANDS ---------------------------------------------------

//commands/push.c
void		push(t_stack **dest, t_stack **src);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **b, t_stack **a);

//commands/rev_rotate.c
void		rev_rotate(t_stack **stack);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
t_stack		*beforelast_node(t_stack *stack);

//commads/rotate.c
void		rotate(t_stack **stack);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
t_stack		*last_node(t_stack *stack);

//commands/swap.c
void		swap(t_stack **stack);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

//COMMANDS ---------------------------------------------------

//push_swap.c
int			main(int argc, char **argv);
bool		sorted(t_stack *a);

//create_stack.c
t_stack		*create_stack(int argc, char **argv);
t_stack		*check_and_build_stack(char **argv, int start, int is_split);
void		fill_stack(t_stack **a, char **tab);
int			is_valid_integer(char *str);
int			check_duplicates(t_stack *a);

//sort.c
int			sort(t_stack **a);
void		sort_three(t_stack **a);
void		b_to_a(t_stack **a, t_stack **b);
void		a_to_b(t_stack **a, t_stack **b);

//fill.c
void		fill_nodes_b(t_stack *a, t_stack *b);
void		get_btarget(t_stack *a, t_stack *b);
void		get_bcost(t_stack *a, t_stack *b);
void		find_cheap_node(t_stack *stack);
void		get_index(t_stack *stack);

//rotate_both.c
void		b_to_a_rev_r(t_stack **a, t_stack **b, t_stack *bcheapest);
void		b_to_a_r(t_stack **a, t_stack **b, t_stack *bcheapest);
void		a_to_b_rev_r(t_stack **a, t_stack **b, t_stack *cheapest);
void		a_to_b_r(t_stack **a, t_stack **b, t_stack *cheapest);

//sort_utils.c
t_stack		*get_max_node(t_stack *stack);
t_stack		*get_min_node(t_stack *stack);
t_stack		*get_cheap_node(t_stack *stack);
void		move_node_top(t_stack **stack, t_stack *node, char name);
int			get_stack_size(t_stack *stack);

//utils.c
void		error(void);
void		free_tab(char **tab);
void		free_stack(t_stack **stack);

#endif
