#include "../push_swap.h"

/**
 * @brief Libère la mémoire allouée pour un tableau de chaînes de caractères.
 *
 * Cette fonction libère la mémoire de chaque chaîne de caractères contenue
 * dans le tableau 'split', puis libère le tableau lui-même.
 *
 * @param split Tableau de chaînes de caractères à libérer.
 */

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
/**
 * @brief Initialise et ajoute un nouvel élément à la pile 'a' avec une valeur 
 * donnée.
 *
 * Cette fonction crée un nouvel élément de type 't_stack' et initialise ses
 * valeurs. Si la pile 'a' est vide, elle affecte directement le nouvel élément
 * comme tête de la pile. Sinon, elle parcourt la pile pour ajouter l'élément à
 * la fin, en reliant correctement les pointeurs 'next' et 'prev'.
 *
 * @param value Valeur à attribuer au nouvel élément de la pile.
 * @param a Double pointeur vers la pile 'a'.
 * @return int Retourne 1 si l'ajout a réussi, 0 en cas d'échec d'allocation.
 */

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

/**
 * @brief Vérifie les arguments fournis sous forme de chaîne de caractères et
 * les ajoute à la pile.
 *
 * Cette fonction divise la chaîne 'av' en plusieurs sous-chaînes de nombres
 * avec 'ft_split'. Ensuite, elle vérifie si chaque sous-chaîne peut être 
 * convertie en entier avec 'ft_atoi' et 'ft_itoa' pour valider le format. 
 * Si la conversion échoue ou ne correspond pas au nombre d'origine, elle libère
 * la mémoire allouée et retourne 0. Les nombres valides sont ajoutés dans la 
 * pile 'a' en appelant 'init_stack'.
 *
 * @param av Chaîne de caractères contenant les arguments.
 * @param a Double pointeur vers la pile 'a'.
 * @return int Retourne 1 si tous les arguments sont valides et ajoutés à la 
 * pile, 0 sinon.
 */

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
