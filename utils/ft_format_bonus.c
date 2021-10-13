/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 21:39:06 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/13 00:37:54 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../ft_printf_bonus.h"

int	ft_format(int c, va_list args)
{
	int	size;

	size = 0;
	if (ft_strchr("di", c))
		size = ft_put_di(args);
	else if (c == 'u')
		size = ft_put_u(args);
	else if (c == 's')
		size = ft_put_cs(c, args);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		size = 1;
	}
	else if (c == 'c')
		size = ft_put_cs(c, args);
	else if (ft_strchr("xX", c))
		size = ft_put_x(c, args);
	else if (c == 'p')
		size = ft_put_p(args);
	return (size);
}
