#include "../push_swap.h"

int	get_stack_size(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

//find the cheapest node in the stack
t_stack	*get_cheap_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheap)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	move_node_top(t_stack **stack, t_stack *node, char name)
{
	while (*stack != node)
	{
		if (name == 'a')
		{
			if (node->over_med)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (node->over_med)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

t_stack	*get_min_node(t_stack *stack)
{
	t_stack	*min_node;
	int		min;

	min = INTMAX;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->nbr <= min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*get_max_node(t_stack *stack)
{
	t_stack	*max_node;
	int		max;

	max = INTMIN;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->nbr >= max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
