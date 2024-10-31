#include "../push_swap.h"

/**
 * @brief Libère la mémoire de tous les éléments d'une liste chaînée.
 *
 * Cette fonction parcourt chaque élément de la liste 'x' et libère
 * la mémoire associée, permettant d'éviter les fuites de mémoire.
 *
 * @param x Pointeur vers le premier élément de la liste.
 */

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
/**
 * @brief Calcule la taille d'une pile.
 *
 * Cette fonction parcourt tous les éléments de la pile 'a' et
 * retourne le nombre total d'éléments présents.
 *
 * @param a Pointeur vers le premier élément de la pile.
 * @return int Nombre d'éléments dans la pile.
 */

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
/**
 * @brief Récupère le dernier élément d'une liste chaînée.
 *
 * Cette fonction parcourt la liste 'lst' jusqu'à atteindre l'élément
 * dont le pointeur 'next' est nul, indiquant la fin de la liste.
 *
 * @param lst Pointeur vers le premier élément de la liste.
 * @return t_stack* Pointeur vers le dernier élément de la liste.
 */

t_stack	*get_last(t_stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/**
 * @brief Ajoute un élément au début d'une liste chaînée.
 *
 * Cette fonction ajoute le nouvel élément 'new' au début de la liste 'lst'.
 * Elle met à jour les pointeurs 'next' et 'prev' pour maintenir l'intégrité
 * de la liste doublement chaînée.
 *
 * @param lst Pointeur vers le pointeur de la liste à modifier.
 * @param new Pointeur vers le nouvel élément à ajouter au début.
 */

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
/**
 * @brief Affiche un message d'erreur et quitte le programme.
 *
 * Cette fonction affiche "Error" sur la sortie d'erreur (fd 2) et
 * quitte le programme en retournant un code d'erreur (1).
 */

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
