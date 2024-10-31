#include "../push_swap.h"

/**
 * @brief Effectue des rotations sur la pile selon la direction spécifiée.
 *
 * En fonction de la direction spécifiée par 'move->up', cette fonction effectue
 * le nombre de rotations défini dans 'move->move' sur la pile donnée. Si 
 * 'is_stack_a' est vrai, elle utilise les fonctions de rotation de la pile 'a',
 * sinon elle utilise celles de la pile 'b'.
 *
 * @param x Pointeur vers la pile à faire tourner.
 * @param move Structure contenant le nombre et la direction des mouvements.
 * @param is_stack_a Bool pour indiquer si la rotation s'applique à la pile 'a'.
 */

void	rotate_list(t_stack **x, t_move *move, int is_stack_a)
{
	if (!move->up)
	{
		while (move->move--)
		{
			if (is_stack_a)
				ra(x);
			else
				rb(x);
		}
	}
	else
	{
		while (move->move--)
		{
			if (is_stack_a)
				rra(x);
			else
				rrb(x);
		}
	}
}
/**
 * @brief Calcule le nombre minimal de mouvements pour placer un élément avec 
 * un index donné.
 *
 * Cette fonction détermine si l'élément d'index 'index' doit être placé en
 * utilisant des rotations vers le haut ('ra') ou vers le bas ('rra') pour un
 * placement optimal. Elle ajuste le nombre de mouvements dans 'dir_x' pour
 * minimiser le nombre de déplacements requis. Si les mouvements vers le bas
 * sont plus courts, elle met à jour la structure 'dir_x' pour refléter cela.
 *
 * @param x Pile dans laquelle trouver l'élément à placer.
 * @param dir_x Structure 't_move' qui stocke la direction et le nombre de 
 * mouvements optimaux.
 * @param index Index de l'élément à trouver dans la pile.
 */

void	ra_or_rra(t_stack *x, t_move *dir_x, int index)
{
	t_move	tmp;

	dir_x->up = 0;
	dir_x->move = 0;
	tmp.up = 1;
	tmp.move = 1;
	tmp.biggest = dir_x->biggest;
	while (x->next)
	{
		if (x->index == index)
			break ;
		dir_x->move++;
		x = x->next;
	}
	while (x->next)
		x = x->next;
	while (x->prev)
	{
		if (x->index == index)
			break ;
		tmp.move++;
		x = x->prev;
	}
	if (dir_x->move > tmp.move)
		*dir_x = tmp;
}

/**
 * @brief Trouve la position optimale pour un index donné dans la pile.
 *
 * Cette fonction recherche dans la pile 'a' l'élément ayant l'index 
 * immédiatement supérieur à 'index'. Si aucun n'est trouvé, elle met
 * 'biggest' à 1 et retourne l'index du plus grand élément. Si un 
 * élément plus grand que 'index' existe, elle renvoie cet index.
 *
 * @param a Pile dans laquelle chercher.
 * @param index Index pour lequel trouver une position optimale.
 * @param biggest Pointeur vers un indicateur pour savoir si le plus grand 
 * 	élément est sélectionné.
 * @return int Index de l'élément trouvé ou du plus grand si aucun n'est 
 * supérieur.
 */

int	find_position(t_stack *a, int index, int *biggest)
{
	t_stack	*tmp;
	int		first_b;

	tmp = a;
	first_b = -1;
	while (a)
	{
		if (a->index > index && (first_b == -1 || first_b > a->index))
			first_b = a->index;
		a = a->next;
	}
	*biggest = 0;
	if (first_b == -1)
		*biggest = 1;
	if (*biggest == 0)
		return (first_b);
	first_b = tmp->index;
	while (tmp)
	{
		if (tmp->index > first_b)
			first_b = tmp->index;
		tmp = tmp->next;
	}
	return (first_b);
}
/**
 * @brief Détermine les mouvements les moins coûteux pour trier un élément.
 *
 * Cette fonction analyse les éléments de la pile 'b' pour déterminer le nombre
 * minimal de mouvements nécessaires pour déplacer un élément vers sa position
 * optimale dans la pile 'a'. Elle met à jour les structures 'dir_a' et 'dir_b'
 * avec les directions et le nombre de mouvements les moins coûteux.
 *
 * @param a Pile dans laquelle placer l'élément de manière optimale.
 * @param b Pile contenant les éléments à trier.
 * @param dir_a Structure stockant les mouvements nécessaires pour la pile 'a'.
 * @param dir_b Structure stockant les mouvements nécessaires pour la pile 'b'.
 */

void	cheaper_move(t_stack *a, t_stack *b, t_move *dir_a, t_move *dir_b)
{
	t_stack	*tmp;
	t_move	lower;
	int		index;

	tmp = b;
	lower.move = -1;
	while (b)
	{
		ra_or_rra(tmp, dir_b, b->index);
		ra_or_rra(a, dir_a, find_position(a, b->index, &dir_a->biggest));
		if (lower.move == -1 || dir_b->move + dir_a->move < lower.move)
		{
			lower.move = dir_b->move + dir_a->move;
			index = b->index;
		}
		b = b->next;
	}
	ra_or_rra(tmp, dir_b, index);
	ra_or_rra(a, dir_a, find_position(a, index, &dir_a->biggest));
}
/**
 * @brief Calcule et applique les mouvements nécessaires pour trier les piles.
 *
 * Cette fonction exécute les mouvements calculés pour la pile 'a' et la pile 
 * 'b', puis déplace l'élément le plus optimal de 'b' vers 'a' en utilisant 'pa'.
 * Elle vérifie également si le plus grand élément est en haut de la pile 'a' 
 * pour potentiellement appliquer 'sa' et continuer le tri.
 *
 * @param a Pointeur vers la pile 'a'.
 * @param b Pointeur vers la pile 'b'.
 */

void	calculate_and_sort(t_stack **a, t_stack **b)
{
	t_move	dir_a;
	t_move	dir_b;

	while (*b)
	{
		dir_a.biggest = 0;
		dir_b.biggest = 0;
		cheaper_move(*a, *b, &dir_a, &dir_b);
		rotate_list(a, &dir_a, 1);
		rotate_list(b, &dir_b, 0);
		pa(a, b);
		if (dir_a.biggest)
			sa(a);
	}
}
