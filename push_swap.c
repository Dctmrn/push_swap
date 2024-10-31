#include "../push_swap.h"

/**
 * @brief Positionne l'élément avec l'index le plus petit en haut de la pile 'a'.
 *
 * Parcourt la pile pour identifier la position de l'élément avec l'index le 
 * plus petit (0). Puis déplace cet élément en tête de pile en choisissant la 
 * rotation la plus courte (vers le haut ou vers le bas) pour minimiser le nombre
 * d'opérations.
 *
 * @param a Pointeur vers la pile 'a'.
 */

void	sort_in_position(t_stack **a)
{
	t_stack		*tmp;
	size_t		smallest_pos;
	size_t		len;

	tmp = *a;
	len = 0;
	smallest_pos = 0;
	while (tmp)
	{
		if (tmp->index == 0)
			smallest_pos = len;
		len++;
		tmp = tmp->next;
	}
	if ((len + 1) / 2 < smallest_pos)
		while (smallest_pos++ < len)
			rra(a);
	else
		while (smallest_pos-- > 0)
			ra(a);
}

/**
 * @brief Vérifie s'il existe des doublons dans la pile 'a'.
 *
 * Parcourt chaque élément de la pile et vérifie pour chaque élément suivant 
 * s'il y a un doublon. Si un doublon est trouvé, retourne 1 (indiquant une 
 * erreur).
 *
 * @param a Pointeur vers la pile 'a'.
 * @return 1 si des doublons sont trouvés, sinon 0.
 */

int	check_duplicates(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

/**
 * @brief Vérifie si la pile 'a' est triée par ordre croissant.
 *
 * Compare chaque élément avec le suivant. Si un élément est plus grand
 * que le suivant, la pile n'est pas triée et la fonction retourne 0.
 *
 * @param a Pointeur vers la pile 'a'.
 * @return 1 si la pile est triée, sinon 0.
 */

int	sorted(t_stack *a)
{
	int	i;

	i = a->value;
	while (a)
	{
		if (i > a->value)
			return (0);
		i = a->value;
		a = a->next;
	}
	return (1);
}

/**
 * @brief Fonction principale qui exécute l'algorithme de tri pour les piles.
 *
 * Vérifie les arguments, détecte les doublons, et initialise le tri si la pile 
 * n'est pas triée. Si la pile est déjà triée, elle est libérée directement.
 * Sinon, la fonction trie et positionne correctement les éléments.
 *
 * @param ac Nombre d'arguments.
 * @param av Tableau de chaînes représentant les arguments.
 * @param a Pointeur vers la pile 'a'.
 * @param b Pointeur vers la pile 'b'.
 */

void	push_swap(int ac, char *av[], t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!check_arg(av[i], a))
			(free_list(*a), error());
	}
	if (check_duplicates(*a))
		return (free_list(*a), free_list(*b), error());
	if (sorted(*a))
		return (free_list(*a), free_list(*b));
	init_sort(a, b);
	calculate_and_sort(a, b);
	if (!sorted(*a))
		sort_in_position(a);
	return (free_list(*a), free_list(*b));
}

/**
 * @brief Point d'entrée du programme.
 *
 * Vérifie le nombre d'arguments et exécute la fonction principale push_swap
 * si les arguments sont suffisants.
 *
 * @param ac Nombre d'arguments.
 * @param av Tableau de chaînes représentant les arguments.
 * @return 0 à la fin du programme.
 */

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	push_swap (ac, av, &a, &b);
	return (0);
}
