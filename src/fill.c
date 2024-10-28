#include "../push_swap.h"

void	get_index(t_stack *stack)
{
	int	i;
	int	med;

	i = 0;
	if (!stack)
		return ;
	med = get_stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= med)
			stack->over_med = true;
		else
			stack->over_med = false;
		stack = stack->next;
		i++;
	}
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

void	fill_nodes_b(t_stack *a, t_stack *b)
{
	get_index(a);
	get_index(b);
	get_btarget(a, b);
	get_bcost(a, b);
	find_cheap_node(b);
}
