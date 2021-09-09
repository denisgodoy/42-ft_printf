/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:18:55 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/09 18:18:56 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

char	*ft_utoa(int n)
{
	unsigned int	nbr;
	int				i;
	char			*ptr;

	nbr = (unsigned int)n;
	ptr = (char *)ft_calloc(ft_count_decimal_u(nbr) + 1, sizeof(char));
	if (!ptr)
		return (0);
	if (n == 0)
		ptr[0] = '0';
	i = ft_count_decimal_u(nbr) - 1;
	while (nbr)
	{
		ptr[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	return (ptr);
}
