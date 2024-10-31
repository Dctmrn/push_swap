#include "../push_swap.h"

static void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	*b = (*b)->next;
	add_front(a, tmp);
	if (*b)
		(*b)->prev = NULL;
}

void	pa(t_stack **a, t_stack **b)
{
	if (!*b)
		return ;
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	push(b, a);
	ft_printf("pb\n");
}
