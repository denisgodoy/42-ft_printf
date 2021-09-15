/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa_hex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:18:44 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/15 15:11:27 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../ft_printf_bonus.h"

static int	ft_count_decimal_u(size_t n);

char	*ft_stoa_hex(size_t n)
{
	int		i;
	char	*buffer;
	char	*hex;
	char	*str;

	hex = "0123456789abcdef";
	i = 0;
	buffer = (char *)ft_calloc(ft_count_decimal_u(n) + 1, sizeof(char));
	if (!buffer)
		return (0);
	else if (n == 0)
		buffer[0] = '0';
	while (n)
	{
		buffer[i++] = hex[n % 16];
		n = n / 16;
	}
	str = ft_strrev(buffer);
	free(buffer);
	return (str);
}

static int	ft_count_decimal_u(size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}
