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



void	get_min_top(t_stack **a)
{
	while ((*a)->nbr != get_min_node(*a)->nbr)
	{
		if (get_min_node(*a)->over_med)
			ra(a);
		else
			rra(a);
	}
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


