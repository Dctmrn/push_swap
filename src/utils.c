#include "../push_swap.h"

void	free_list(t_stack *x)
{
	t_stack	*tmp;

	if (!x)
		return ;
	while (x)
	{
		tmp = x->next;
		free(x);
		x = tmp;
	}
}

int	get_stack_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

t_stack	*get_last(t_stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_front(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *lst;
	new->next = tmp;
	new->prev = NULL;
	if (tmp)
		tmp->prev = new;
	*lst = new;
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
