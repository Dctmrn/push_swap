#include "../push_swap.h"

void	get_atarget(t_stack *a, t_stack *b)
{
	t_stack	*tmp_b;
	t_stack	*target;
	long	closest_small;

	while (a)
	{
		closest_small = -2147483649;
		tmp_b = b;
		while (tmp_b)
		{
			if (tmp_b->nbr > closest_small && tmp_b->nbr < a->nbr)
			{
				closest_small = tmp_b->nbr;
				target = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (closest_small == -2147483649)
			a->target = get_max_node(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	get_cost(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	while (a)
	{
		a->cost = 0;
		if (a->over_med && a->target->over_med)
			a->cost = a->index + a->target->index;
		if (a->over_med && !(a->target->over_med))
			a->cost = a->index + (size_b - (a->target->index));
		if (!(a->over_med) && !(a->target->over_med))
			a->cost = (size_a - a->index) + (size_b - (a->target->index));
		if (!(a->over_med) && a->target->over_med)
			a->cost = (size_a - a->index) + a->target->index;
		a = a->next;
	}
}



void	fill_nodes_a(t_stack *a, t_stack *b)
{
	get_index(a);
	get_index(b);
	get_atarget(a, b);
	get_cost(a, b);
	find_cheap_node(a);
}


void	find_cheap_node(t_stack *stack)
{
	t_stack	*cheap_node;
	long	cheap_node_value;

	if (!stack)
		return ;
	cheap_node_value = 2147483648;
	while (stack)
	{
		stack->cheap = false;
		if (stack->cost < cheap_node_value)
		{
			cheap_node_value = stack->cost;
			cheap_node = stack;
		}
		stack = stack->next;
	}
	cheap_node->cheap = true;
}
