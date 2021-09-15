/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_format_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 21:39:06 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/15 17:58:16 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../ft_printf_bonus.h"

static void	ft_check_format(int p, int c, int *size, va_list args);

int	ft_pre_format(int p, int c, va_list args)
{
	int	size;

	size = 0;
	ft_check_format(p, c, &size, args);
	if (ft_strchr("di", c))
		size += ft_put_di(args);
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
		size += ft_put_x(c, args);
	else if (c == 'p')
		size = ft_put_p(args);
	return (size);
}

static void	ft_check_format(int p, int c, int *size, va_list args)
{
	va_list	temp_args;
	
	va_copy(temp_args, args);
	if (p == '#' && ft_strchr("xX", c))
	{
		if (va_arg(temp_args, int) != 0)
		{
			if (c == 'X')
				ft_putstr_fd("0X", 1);
			else
				ft_putstr_fd("0x", 1);
			*size = 2;
		}
	}
	else if (p == ' ' && ft_strchr("di", c))
	{
		if (va_arg(temp_args, int) >= 0)
		{
			ft_putchar_fd(' ', 1);
			*size = 1;
		}
	}
	else if (p == '+' && ft_strchr("di", c))
	{
		if (va_arg(temp_args, int) >= 0)
		{
			ft_putchar_fd('+', 1);
			*size = 1;
		}
	}
	else
		return ;
}
