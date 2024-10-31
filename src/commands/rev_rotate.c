#include "../push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*a))
		return ;
	if ((*a) && (*a)->next)
	{
		last = get_last(*a);
		tmp = last->prev;
		last->prev = NULL;
		last->next = (*a);
		tmp->next = NULL;
		(*a)->prev = last;
		(*a) = last;
		ft_printf("rra\n");
	}
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*b))
		return ;
	if ((*b) && (*b)->next)
	{
		last = get_last(*b);
		tmp = last->prev;
		last->prev = NULL;
		last->next = (*b);
		tmp->next = NULL;
		(*b)->prev = last;
		(*b) = last;
		ft_printf("rrb\n");
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
