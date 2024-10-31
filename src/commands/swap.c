#include "../push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp->prev = *a;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	tmp->prev = *b;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
