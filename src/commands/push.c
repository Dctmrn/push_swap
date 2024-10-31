#include "../push_swap.h"

/**
 * @brief Déplace le premier élément d'une pile vers une autre pile.
 *
 * Cette fonction prend le premier élément de la pile source 'b' et
 * l'ajoute au début de la pile destination 'a'. Elle ajuste les pointeurs
 * pour maintenir l'intégrité des deux piles.
 *
 * @param a Pointeur vers la pile de destination.
 * @param b Pointeur vers la pile source.
 */

static void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	*b = (*b)->next;
	add_front(a, tmp);
	if (*b)
		(*b)->prev = NULL;
}

/**
 * @brief Pousse le premier élément de la pile 'b' vers la pile 'a'.
 *
 * Cette fonction utilise 'push' pour déplacer l'élément, puis affiche
 * l'opération "pa" pour indiquer le déplacement vers 'a'. Si 'b' est vide,
 * la fonction ne fait rien.
 *
 * @param a Pointeur vers la pile de destination.
 * @param b Pointeur vers la pile source.
 */

void	pa(t_stack **a, t_stack **b)
{
	if (!*b)
		return ;
	push(a, b);
	ft_printf("pa\n");
}

/**
 * @brief Pousse le premier élément de la pile 'a' vers la pile 'b'.
 *
 * Cette fonction utilise 'push' pour déplacer l'élément, puis affiche
 * l'opération "pb" pour indiquer le déplacement vers 'b'. Si 'a' est vide,
 * la fonction ne fait rien.
 *
 * @param a Pointeur vers la pile source.
 * @param b Pointeur vers la pile de destination.
 */

void	pb(t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	push(b, a);
	ft_printf("pb\n");
}
