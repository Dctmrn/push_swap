#include "../push_swap.h"

void rotate_both(t_stack **a, t_stack **b, t_stack *target_a, t_stack *target_b, int reverse)
{
    while (*a != target_a && *b != target_b)
    {
        if (reverse)
            rrr(a, b);
        else
            rr(a, b);
    }
    get_index(*a);
    get_index(*b);
}

void a_to_b_r(t_stack **a, t_stack **b, t_stack *cheapest)
{
    rotate_both(a, b, cheapest, cheapest->target, 0);
}

void a_to_b_rev_r(t_stack **a, t_stack **b, t_stack *cheapest)
{
    rotate_both(a, b, cheapest, cheapest->target, 1);
}

void b_to_a_r(t_stack **a, t_stack **b, t_stack *bcheapest)
{
    rotate_both(b, a, bcheapest, bcheapest->target, 0);
}

void b_to_a_rev_r(t_stack **a, t_stack **b, t_stack *bcheapest)
{
    rotate_both(b, a, bcheapest, bcheapest->target, 1);
}

