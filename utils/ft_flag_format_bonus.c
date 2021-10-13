/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_format_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 21:39:06 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/13 00:37:46 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../ft_printf_bonus.h"

static void	ft_check_flag(int p, int c, int *size, va_list args);
static void	ft_put_flag(int **size, int p, int c);

int	ft_flag_format(int p, int c, va_list args)
{
	int	size;

	size = 0;
	ft_check_flag(p, c, &size, args);
	if (ft_strchr("di", c))
		size += ft_put_di(args);
	else if (c == 'u')
		size = ft_put_u(args);
	else if (ft_strchr("cs", c))
		size += ft_put_cs(c, args);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		size = 1;
	}
	else if (ft_strchr("xX", c))
		size += ft_put_x(c, args);
	else if (c == 'p')
		size = ft_put_p(args);
	return (size);
}

static void	ft_check_flag(int p, int c, int *size, va_list args)
{
	va_list	temp_args;

	va_copy(temp_args, args);
	if (p == '#' && ft_strchr("xX", c))
	{
		if (va_arg(temp_args, int) != 0)
			ft_put_flag(&size, p, c);
	}
	else if ((p == ' ' || p == '+') && ft_strchr("di", c))
	{
		if (va_arg(temp_args, int) >= 0)
			ft_put_flag(&size, p, c);
	}
}

static void	ft_put_flag(int **size, int p, int c)
{
	if (p == '#')
	{
		if (c == 'X')
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
		**size = 2;
	}
	else if (p == ' ')
	{
		ft_putchar_fd(' ', 1);
		**size = 1;
	}
	else if (p == '+')
	{
		ft_putchar_fd('+', 1);
		**size = 1;
	}
}
