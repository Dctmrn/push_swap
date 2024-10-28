#include "../push_swap.h"

t_stack	*last_node(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*beforelast_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
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

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		(free(tab[i]), i++);
	free(tab);
}

void	error(void)
{
	write(2, "error\n", 6);
	exit(1);
}