#include "../push_swap.h"

/**
 * @brief Effectue une rotation sur la pile 'a' (ra).
 *
 * Déplace le premier élément de la pile 'a' à la fin de celle-ci.
 * Met à jour les pointeurs pour conserver la continuité de la liste.
 *
 * @param a Pointeur vers la pile 'a'.
 */

void	ra(t_stack **a)
{
	t_stack	*nlast;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	nlast = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = nlast->next;
	last->next = nlast;
	nlast->prev = last;
	nlast->next = NULL;
	(*a)->prev = NULL;
	ft_printf("ra\n");
}

/**
 * @brief Effectue une rotation sur la pile 'b' (rb).
 *
 * Déplace le premier élément de la pile 'b' à la fin de celle-ci.
 * Met à jour les pointeurs pour maintenir la continuité de la liste.
 *
 * @param b Pointeur vers la pile 'b'.
 */

void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*b))
		return ;
	tmp = (*b)->next;
	last = get_last(*b);
	tmp->prev = NULL;
	(*b)->next = NULL;
	(*b)->prev = last;
	last->next = (*b);
	(*b) = tmp;
	ft_printf("rb\n");
}

/**
 * @brief Effectue une rotation simultanée sur les piles 'a' et 'b' (rr).
 *
 * Applique les fonctions 'ra' et 'rb' sur les piles 'a' et 'b' 
 * respectivement, effectuant une rotation pour les deux.
 *
 * @param a Pointeur vers la pile 'a'.
 * @param b Pointeur vers la pile 'b'.
 */

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}
