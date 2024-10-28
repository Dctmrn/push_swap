#include "../push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
	before_last = beforelast_node(*stack);
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}

t_stack	*beforelast_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}
