#include "../push_swap.h"

void	a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheap_node(*a);
	if (cheapest->over_med && cheapest->target->over_med)
		a_to_b_r(a, b, cheapest);
	else if (!(cheapest->over_med) && !(cheapest->target->over_med))
		a_to_b_rev_r(a, b, cheapest);
	move_node_top(a, cheapest, 'a');
	move_node_top(b, cheapest->target, 'b');
	pb(b, a);
}

void	b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*bcheapest;

	bcheapest = get_cheap_node(*b);
	if (bcheapest->over_med && bcheapest->target->over_med)
		b_to_a_r(a, b, bcheapest);
	else if (!(bcheapest->over_med) && !(bcheapest->target->over_med))
		b_to_a_rev_r(a, b, bcheapest);
	move_node_top(b, bcheapest, 'b');
	move_node_top(a, bcheapest->target, 'a');
	pa(a, b);
}

void	sort_three(t_stack **a)
{
	if (sorted(*a))
		return;

	t_stack	*max_node;

	max_node = get_max_node(*a);
	if (*a == max_node)
		ra(a);
	else if ((*a)->next == max_node)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}
void sort(t_stack **a)
{
    t_stack *b = NULL;
    int stack_size = get_stack_size(*a);

    if (stack_size == 0)
        return;
    if (stack_size == 1)
        return; 
    if (stack_size == 2)
    {
        sa(a);
        return;
    }
    if (stack_size == 3)
    {
        sort_three(a);
        return;
    }
    while (stack_size-- > 3 && !sorted(*a))
    {
        pb(&b, a);
    }
    sort_three(a);
    while (b)
    {
        fill_nodes_b(*a, b);
        b_to_a(a, &b);
    }
    get_index(*a);
}

