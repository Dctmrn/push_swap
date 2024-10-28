#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../.ft/gnl/gnl.h"
# include "../.ft/libft/libft.h"
# include "../.ft/printf/ft_printf.h"

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define RESET "\033[0m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[1;96m"
# define ITALIC "\033[3m"

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
	int			over_med;
	int			cheap;
	struct s_stack	*target;			
	struct s_stack	*next;
}	t_stack;


void        print_stack(t_stack *stack);

int			main(int argc, char **argv);
void		error(void);
int			check_int(char *str);
int			check_size(char *str);
t_stack		*one_arg(char **argv);
t_stack		*multiple_args(int argc, char **argv);
void		create_astack(t_stack **a, char **tab);
void		add_back(t_stack **stack, t_stack *stack_new);
void		*addvalue_stack(int newnbr);
bool		sorted(t_stack *a);
int			check_duplicates(t_stack *a);
void		free_stack(t_stack **stack);
int			get_stack_size(t_stack *stack);

void		fill_nodes_a(t_stack *a, t_stack *b);
void		get_atarget(t_stack *a, t_stack *b);
void		get_cost(t_stack *a, t_stack *b);
void		find_cheap_node(t_stack *stack);

void		fill_nodes_b(t_stack *a, t_stack *b);
void		get_btarget(t_stack *a, t_stack *b);
void		get_bcost(t_stack *a, t_stack *b);

t_stack		*last_node(t_stack *stack);
t_stack		*beforelast_node(t_stack *stack);
t_stack		*get_min_node(t_stack *stack);
t_stack		*get_max_node(t_stack *stack);

void		push(t_stack **dst, t_stack **src);
void		pb(t_stack **b, t_stack **a);
void		pa(t_stack **a, t_stack **b);

void		swap(t_stack **stack);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

void		rotate(t_stack **stack);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);

void		rev_rotate(t_stack **stack);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

void		get_index(t_stack *stack);
t_stack     *get_cheap_node(t_stack *stack);
void		move_node_top(t_stack **stack, t_stack *node, char name);
void		get_min_top(t_stack **a);



void		sort(t_stack **a);
void		sort_three(t_stack **a);
void		sort_stacks(t_stack **a, t_stack **b);
void		a_to_b(t_stack **a, t_stack **b);
void		b_to_a(t_stack **a, t_stack **b);

void		arotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void		arev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);

void		brotate_both(t_stack **a, t_stack **b, t_stack *bcheapest);
void		brev_rotate_both(t_stack **a, t_stack **b, t_stack *bcheapest);

void	free_tab(char **tab);

int	is_valid_integer(char *str);
t_stack *create_stack(int argc, char **argv);
void	fill_stack(t_stack **a, char **tab);
void b_to_a_rev_r(t_stack **a, t_stack **b, t_stack *bcheapest);
void b_to_a_r(t_stack **a, t_stack **b, t_stack *bcheapest);
void a_to_b_rev_r(t_stack **a, t_stack **b, t_stack *cheapest);
void a_to_b_r(t_stack **a, t_stack **b, t_stack *cheapest);
void rotate_both(t_stack **a, t_stack **b, t_stack *target_a, t_stack *target_b, int reverse);


#endif
