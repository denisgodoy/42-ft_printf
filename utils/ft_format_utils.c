/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 22:27:16 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/13 00:38:07 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../ft_printf.h"

int	ft_put_di(va_list args)
{
	int		size;
	char	*temp;

	temp = ft_itoa(va_arg(args, int));
	ft_putstr_fd(temp, 1);
	size = ft_strlen(temp);
	free(temp);
	return (size);
}

int	ft_put_u(va_list args)
{
	int		size;
	char	*temp;

	temp = ft_utoa(va_arg(args, int));
	ft_putstr_fd(temp, 1);
	size = ft_strlen(temp);
	free(temp);
	return (size);
}

int	ft_put_x(int c, va_list args)
{
	int		size;
	int		j;
	char	*temp;

	j = 0;
	temp = ft_utoa_hex(va_arg(args, int));
	if (c == 'X')
	{
		while (temp[j])
		{
			temp[j] = ft_toupper(temp[j]);
			j++;
		}
		j = 0;
	}
	ft_putstr_fd(temp, 1);
	size = ft_strlen(temp);
	free(temp);
	return (size);
}

int	ft_put_cs(int c, va_list args)
{
	int		size;
	char	*temp;

	size = 0;
	if (c == 's')
	{
		temp = va_arg(args, char *);
		if (!temp)
		{
			ft_putstr_fd("(null)", 1);
			size = 6;
		}
		else
		{
			ft_putstr_fd(temp, 1);
			size = ft_strlen(temp);
		}
	}
	else if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		size = 1;
	}
	return (size);
}

int	ft_put_p(va_list args)
{
	int		size;
	size_t	temp_i;
	char	*temp;

	temp_i = va_arg(args, size_t);
	temp = ft_stoa_hex(temp_i);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(temp, 1);
	size = (ft_strlen(temp) + 2);
	free(temp);
	return (size);
}
