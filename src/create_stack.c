#include "../push_swap.h"

int	check_duplicates(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}
int	is_valid_integer(char *str)
{
	long	num;
	int		i;

	i = 1;
	if (!(str[0] == '+' || str[0] == '-' || ft_isdigit(str[0])))
		return (0);
	if ((str[0] == '-' || str[0] == '+') && !ft_isdigit(str[1]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = ft_atol(str);
	if (num < INTMIN || num > INTMAX)
		return (0);
	return (1);
}
void	fill_stack(t_stack **stack, char **tab)
{
	long	i;
	t_stack	*new;
	t_stack	*last;

	i = 0;
	while (tab[i])
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			error(); 
		new->nbr = ft_atoi(tab[i]);
		new->next = NULL;

		if (!*stack)
			*stack = new;
		else
		{
			last = *stack;
			while (last->next)
				last = last->next;
			last->next = new;
		}
		i++;
	}
}

t_stack *check_and_build_stack(char **argv, int start, int is_split)
{
	t_stack *a = NULL;
	int i = start;

	while (argv[i])
	{
		if (!is_valid_integer(argv[i]))
		{
			if (is_split)
				free_tab(argv);
			error();
		}
		i++;
	}
	fill_stack(&a, argv + start);
	if (check_duplicates(a))
	{
		free_stack(&a);
		if (is_split)
			free_tab(argv);
		error();
	}
	if (is_split)
		free_tab(argv);
	return (a);
}

t_stack *create_stack(int argc, char **argv)
{
	char **split_argv = NULL;

	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		split_argv = ft_split(argv[1], 32);
		if (!split_argv)
			return NULL;
		return check_and_build_stack(split_argv, 0, 1);
	}
	else if (argc > 2 && ft_strchr(argv[1], ' '))
		error();
	
	return (check_and_build_stack(argv, 1, 0));
}




