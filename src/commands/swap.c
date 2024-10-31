#include "../push_swap.h"

/**
 * @brief Échange les deux premiers éléments de la pile 'a' (sa).
 *
 * Si 'a' contient moins de deux éléments, l'opération est annulée.
 * Sinon, échange les deux premiers éléments en ajustant les liens
 * 'next' et 'prev' pour maintenir l'intégrité de la liste chaînée.
 *
 * @param a Pointeur vers la pile 'a'.
 */

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

/**
 * @brief Échange les deux premiers éléments de la pile 'b' (sb).
 *
 * Identique à 'sa', mais pour la pile 'b'. Si 'b' contient moins
 * de deux éléments, l'opération est annulée.
 *
 * @param b Pointeur vers la pile 'b'.
 */

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

/**
 * @brief Effectue un échange simultané des deux premiers éléments des piles 'a' 
 * et 'b' (ss).
 *
 * Applique les fonctions 'sa' et 'sb' pour permuter les deux premiers éléments
 * des piles 'a' et 'b' respectivement.
 *
 * @param a Pointeur vers la pile 'a'.
 * @param b Pointeur vers la pile 'b'.
 */

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
