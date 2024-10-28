#include "../push_swap.h"

void	get_btarget(t_stack *a, t_stack *b)
{
	t_stack	*tmp_a;
	t_stack	*target;
	long	closest_big;

	while (b)
	{
		closest_big = 2147483648;
		tmp_a = a;
		while (tmp_a)
		{
			if (tmp_a->nbr < closest_big && tmp_a->nbr > b->nbr)
			{
				closest_big = tmp_a->nbr;
				target = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (closest_big == 2147483648)
			b->target = get_min_node(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	get_bcost(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	while (b)
	{
		b->cost = 0;
		if (b->over_med && b->target->over_med)
			b->cost = b->index + b->target->index;
		if (b->over_med && !(b->target->over_med))
			b->cost = b->index + (size_a - (b->target->index));
		if (!(b->over_med) && !(b->target->over_med))
			b->cost = (size_b - b->index) + (size_a - (b->target->index));
		if (!(b->over_med) && b->target->over_med)
			b->cost = (size_b - b->index) + b->target->index;
		b = b->next;
	}
}

void	fill_nodes_b(t_stack *a, t_stack *b)
{
	get_index(a);
	get_index(b);
	get_btarget(a, b);
	get_bcost(a, b);
	find_cheap_node(b);
}
