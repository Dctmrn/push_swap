#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../.ft/gnl/gnl.h"
# include "../.ft/libft/libft.h"
# include "../.ft/printf/ft_printf.h"

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_move
{
	int	up;
	int	move;
	int	biggest;
}	t_move;

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
				COMMANDS
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

// push.c
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);

// rev_rotate.c
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

// rotate.c
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);

// swap.c
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

/*-------------- push_swap.c --------------*/

void		sort_in_position(t_stack **a);
int			check_duplicates(t_stack *a);
int			sorted(t_stack *a);
void		push_swap(int ac, char *av[], t_stack **a, t_stack **b);

/*-------------- checks_init.c --------------*/

void		free_split(char **split);
int			init_stack(int value, t_stack **a);
int			check_arg(char *av, t_stack **a);

/*-------------- basic_sort.c --------------*/

void		sort_two(t_stack **a);
void		sort_three(t_stack	**a);
void		start_sort(t_stack **a);
void		assign_index(t_stack *a);
void		init_sort(t_stack **a, t_stack **b);

/*-------------- sort.c --------------*/

void		rotate_list(t_stack **x, t_move *dir, int is_stack_a);
void		ra_or_rra(t_stack *x, t_move *dir_x, int index);
int			find_position(t_stack *a, int index, int *biggest);
void		cheaper_move(t_stack *a, t_stack *b, t_move *dir_a, t_move *dir_b);
void		calculate_and_sort(t_stack **a, t_stack **b);

/*-------------- utils.c --------------*/

void		free_list(t_stack *x);
int			get_stack_size(t_stack *a);
t_stack		*get_last(t_stack *lst);
void		add_front(t_stack **lst, t_stack *new);
void		error(void);

#endif
