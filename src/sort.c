#include "../push_swap.h"

void	rotate_list(t_stack **x, t_move *move, int is_stack_a)
{
	if (!move->up)
	{
		while (move->move--)
		{
			if (is_stack_a)
				ra(x);
			else
				rb(x);
		}
	}
	else
	{
		while (move->move--)
		{
			if (is_stack_a)
				rra(x);
			else
				rrb(x);
		}
	}
}

void	ra_or_rra(t_stack *x, t_move *dir_x, int index)
{
	t_move	tmp;

	dir_x->up = 0;
	dir_x->move = 0;
	tmp.up = 1;
	tmp.move = 1;
	tmp.biggest = dir_x->biggest;
	while (x->next)
	{
		if (x->index == index)
			break ;
		dir_x->move++;
		x = x->next;
	}
	while (x->next)
		x = x->next;
	while (x->prev)
	{
		if (x->index == index)
			break ;
		tmp.move++;
		x = x->prev;
	}
	if (dir_x->move > tmp.move)
		*dir_x = tmp;
}

int	find_position(t_stack *a, int index, int *biggest)
{
	t_stack	*tmp;
	int		first_b;

	tmp = a;
	first_b = -1;
	while (a)
	{
		if (a->index > index && (first_b == -1 || first_b > a->index))
			first_b = a->index;
		a = a->next;
	}
	*biggest = 0;
	if (first_b == -1)
		*biggest = 1;
	if (*biggest == 0)
		return (first_b);
	first_b = tmp->index;
	while (tmp)
	{
		if (tmp->index > first_b)
			first_b = tmp->index;
		tmp = tmp->next;
	}
	return (first_b);
}

void	cheaper_move(t_stack *a, t_stack *b, t_move *dir_a, t_move *dir_b)
{
	t_stack	*tmp;
	t_move	lower;
	int		index;

	tmp = b;
	lower.move = -1;
	while (b)
	{
		ra_or_rra(tmp, dir_b, b->index);
		ra_or_rra(a, dir_a, find_position(a, b->index, &dir_a->biggest));
		if (lower.move == -1 || dir_b->move + dir_a->move < lower.move)
		{
			lower.move = dir_b->move + dir_a->move;
			index = b->index;
		}
		b = b->next;
	}
	ra_or_rra(tmp, dir_b, index);
	ra_or_rra(a, dir_a, find_position(a, index, &dir_a->biggest));
}

void	calculate_and_sort(t_stack **a, t_stack **b)
{
	t_move	dir_a;
	t_move	dir_b;

	while (*b)
	{
		dir_a.biggest = 0;
		dir_b.biggest = 0;
		cheaper_move(*a, *b, &dir_a, &dir_b);
		rotate_list(a, &dir_a, 1);
		rotate_list(b, &dir_b, 0);
		pa(a, b);
		if (dir_a.biggest)
			sa(a);
	}
}
