#include "../push_swap.h"

/**
 * @brief Effectue une rotation inverse sur la pile 'a' (rra).
 *
 * Déplace le dernier élément de la pile 'a' au début de celle-ci. 
 * Les pointeurs 'prev' et 'next' sont ajustés pour préserver
 * la continuité de la liste.
 *
 * @param a Pointeur vers la pile 'a'.
 */

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*a))
		return ;
	if ((*a) && (*a)->next)
	{
		last = get_last(*a);
		tmp = last->prev;
		last->prev = NULL;
		last->next = (*a);
		tmp->next = NULL;
		(*a)->prev = last;
		(*a) = last;
		ft_printf("rra\n");
	}
}
/**
 * @brief Effectue une rotation inverse sur la pile 'b' (rrb).
 *
 * Déplace le dernier élément de la pile 'b' au début de celle-ci. 
 * Les pointeurs 'prev' et 'next' sont ajustés pour maintenir la continuité.
 *
 * @param b Pointeur vers la pile 'b'.
 */

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*b))
		return ;
	if ((*b) && (*b)->next)
	{
		last = get_last(*b);
		tmp = last->prev;
		last->prev = NULL;
		last->next = (*b);
		tmp->next = NULL;
		(*b)->prev = last;
		(*b) = last;
		ft_printf("rrb\n");
	}
}
/**
 * @brief Effectue une rotation inverse sur les piles 'a' et 'b' (rrr).
 *
 * Applique les fonctions 'rra' et 'rrb' sur les piles 'a' et 'b' 
 * respectivement, effectuant une rotation inverse simultanée.
 *
 * @param a Pointeur vers la pile 'a'.
 * @param b Pointeur vers la pile 'b'.
 */

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
