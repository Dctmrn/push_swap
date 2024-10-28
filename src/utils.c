#include "../push_swap.h"

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
