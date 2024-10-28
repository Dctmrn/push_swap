#include "../push_swap.h"

void	a_to_b_r(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rr(a, b);
	get_index(*a);
	get_index(*b);
}

void	a_to_b_rev_r(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rrr(a, b);
	get_index(*a);
	get_index(*b);
}

void	b_to_a_r(t_stack **a, t_stack **b, t_stack *bcheapest)
{
	while (*b != bcheapest && *a != bcheapest->target)
		rr(a, b);
	get_index(*a);
	get_index(*b);
}

void	b_to_a_rev_r(t_stack **a, t_stack **b, t_stack *bcheapest)
{
	while (*b != bcheapest && *a != bcheapest->target)
		rrr(a, b);
	get_index(*a);
	get_index(*b);
}
