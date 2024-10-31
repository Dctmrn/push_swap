#include "../push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		(free(split[i]), i++);
	free (split);
}

int	init_stack(int value, t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = ft_calloc(1, sizeof(t_stack));
	if (!tmp)
		return (0);
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (!*a)
		return (*a = tmp, 1);
	last = (*a);
	while (last->next)
		last = last->next;
	last->next = tmp;
	return (tmp->prev = last, 1);
}

int	check_arg(char *av, t_stack **a)
{
	char	*tmp;
	int		nb;
	char	**split;
	int		i;

	split = ft_split(av, ' ');
	if (!split || !split[0])
		return (free_split(split), 0);
	i = 0;
	while (split[i])
	{
		nb = ft_atoi(split[i]);
		tmp = ft_itoa(nb);
		if (!tmp)
			return (0);
		if (ft_strncmp(tmp, split[i], ft_strlen(split[i])))
			return (free(tmp), free_split(split), 0);
		if (!init_stack(nb, a))
			return (free(tmp), free_split(split), 0);
		free(tmp);
		i++;
	}
	free_split(split);
	return (1);
}
