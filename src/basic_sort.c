#include "../push_swap.h"

/**
 * @brief Trie deux éléments dans la pile 'a' si nécessaire.
 *
 * Cette fonction compare les valeurs des deux premiers éléments
 * de la pile 'a'. Si la première valeur est plus grande que la 
 * deuxième, elle appelle `sa(a)` pour les échanger.
 *
 * @param a Double pointeur vers la pile 'a'.
 */

void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
/**
 * @brief Trie trois éléments dans la pile 'a' en suivant les règles de tri.
 *
 * Cette fonction vérifie les relations entre les valeurs des trois premiers 
 * éléments de la pile 'a'. En fonction de l'ordre, elle effectue une ou 
 * plusieurs rotations (ra ou rra) et appelle `sort_two` pour finaliser le tri.
 *
 * - Si le premier élément est le plus grand, il appelle `ra` pour le placer en 
 *   fin, puis trie les deux autres.
 * - Si le second est le plus grand et le dernier le plus petit, elle appelle 
 *   `rra` pour mettre le plus grand en bas, puis trie les deux premiers.
 * - Sinon, elle appelle `sort_two` directement pour finir le tri.
 *
 * @param a Double pointeur vers la pile 'a'.
 */

void	sort_three(t_stack	**a)
{
	if ((*a)->value > (*a)->next->value && \
		(*a)->value > (*a)->next->next->value)
	{
		ra(a);
		sort_two(a);
	}
	else if ((*a)->value < (*a)->next->value && \
		(*a)->next->value > (*a)->next->next->value)
	{
		rra(a);
		sort_two(a);
	}
	else if ((*a)->value < (*a)->next->next->value && \
		(*a)->next->value < (*a)->next->next->value)
		sort_two(a);
}
/**
 * @brief Déclenche les routines de tri appropriées pour 2 ou 3 éléments.
 *
 * Cette fonction vérifie la taille de la pile 'a' et appelle `sort_two` ou 
 * `sort_three` selon que la pile contient deux ou trois éléments.
 *
 * @param a Double pointeur vers la pile 'a'.
 */

void	start_sort(t_stack **a)
{
	if (get_stack_size(*a) == 2)
		sort_two(a);
	else if (get_stack_size(*a) == 3)
		sort_three(a);
}
/**
 * @brief Assigne un index à chaque élément de la pile 'a' basé sur leur valeur.
 *
 * Cette fonction attribue un index à chaque élément de la pile 'a', en 
 * fonction de sa valeur relative. Elle parcourt d'abord tous les éléments
 * pour trouver le maximum non indexé, puis l'assigne avec la plus haute valeur 
 * d'index, en décrémentant cette valeur à chaque tour de boucle.
 *
 * @param a Pointeur vers la pile 'a'.
 */

void	assign_index(t_stack *a)
{
	size_t	size;
	int		min;
	t_stack	*highest;
	t_stack	*nbr;

	size = get_stack_size(a);
	while (--size)
	{
		min = -2147483648;
		highest = NULL;
		nbr = a;
		while (nbr)
		{
			if (min < nbr->value && !nbr->index)
			{
				min = nbr->value;
				highest = nbr;
			}
			nbr = nbr->next;
		}
		highest->index = size;
	}
}

/**
 * @brief Routine d'initialisation et tri principal de la pile 'a' et transfert 
 *        vers 'b'.
 *
 * Cette fonction commence par attribuer des index aux éléments de la pile 'a' en
 * appelant `assign_index`. Ensuite, si la taille de la pile est de 3 éléments 
 * ou moins, elle appelle `start_sort` pour trier directement 'a'. Sinon, elle 
 * transfère dans la pile 'b' les éléments ayant les plus petits index, en 
 * gardant trois éléments dans 'a'. Enfin, elle appelle `sort_three` sur 'a'.
 *
 * @param a Double pointeur vers la pile 'a'.
 * @param b Double pointeur vers la pile 'b'.
 */

void	init_sort(t_stack **a, t_stack **b)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = get_stack_size(*a);
	assign_index(*a);
	start_sort(a);
	if (size > 3)
	{
		while (size - i > 3 && i < size / 2)
		{
			if ((*a)->index < (int)size / 2)
			{
				i++;
				pb(a, b);
			}
			else
				ra(a);
		}
		while (++i <= size - 3)
			pb(a, b);
		sort_three(a);
	}
}
