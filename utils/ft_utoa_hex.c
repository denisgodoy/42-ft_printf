/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:18:44 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/09 22:45:11 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../libftprintf.h"

static int	ft_count_decimal_u(unsigned int n);

char	*ft_utoa_hex(int n)
{
	unsigned int	nbr;
	int				i;
	char			*buffer;
	char			*hex;
	char			*str;

	hex = "0123456789abcdef";
	i = 0;
	nbr = (unsigned int)n;
	buffer = (char *)ft_calloc(ft_count_decimal_u(nbr) + 1, sizeof(char));
	if (!buffer)
		return (0);
	if (n == 0)
	{
		buffer[0] = hex[0];
		i = 1;
	}
	while (nbr)
	{
		buffer[i++] = hex[nbr % 16];
		nbr = nbr / 16;
	}
	str = ft_strrev(buffer);
	free(buffer);
	return (str);
}

static int	ft_count_decimal_u(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
