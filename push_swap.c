#include "../push_swap.h"

bool	sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a && a->next)
	{
		if (a->nbr > a->next->nbr)
			return (false);
		a = a->next;
	}
	return (true);
}

// int	main(int argc, char **argv)
// {
// 	t_stack	*a;

// 	a = NULL;
// 	if (argc == 1)
// 		exit(0);
// 	if (argc == 2)
// 		a = one_arg(argv);
// 	else if (argc > 2)
// 		a = multiple_args(argc, argv);
// 	if (!a || check_duplicates(a))
// 	{
// 		free_stack(&a);
// 		error();
// 	}
// 	if (!sorted(a))
// 		sort(&a);
// 	free_stack(&a);
// 	return (0);
// }
int	main(int argc, char **argv)
{
	t_stack	*a = NULL;

	if (argc < 2)
		return (0);

	a = create_stack(argc, argv);
	if (!sorted(a))
		sort(&a);
	free_stack(&a);
	return (0);
}