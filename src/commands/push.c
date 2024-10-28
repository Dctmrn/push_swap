#include "../push_swap.h"

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp_node;

	tmp_node = *src;
	*src = (*src)->next;
	if (*dst == NULL)
	{
		*dst = tmp_node;
		tmp_node->next = NULL;
	}
	else
	{
		tmp_node->next = *dst;
		*dst = tmp_node;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
