/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marida-c <marida-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:21:28 by marida-c          #+#    #+#             */
/*   Updated: 2023/11/20 17:21:31 by marida-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned long nb, char deci)
{
	int		count;
	char	*deci_min;
	char	*deci_max;

	count = 0;
	deci_min = "0123456789abcdef";
	deci_max = "0123456789ABCDEF";
	if (nb >= 16)
	{
		count += ft_print_hexa(nb / 16, deci);
		count += ft_print_hexa(nb % 16, deci);
	}
	else if (nb < 16 && deci == 'x')
	count += ft_print_char(deci_min[nb]);
	else if (nb < 16 && deci == 'X')
	count += ft_print_char(deci_max[nb]);
	return (count);
}
