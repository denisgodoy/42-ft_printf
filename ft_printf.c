/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:22:40 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/07 00:48:20 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include 	<stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*value;
	char	*str;
	int 	i;
	int 	n;

	if (!format)
		return (0);
	if (!ft_strchr(format, '%'))
	{
		ft_putstr_fd((char *)format, 1);
		return (ft_strlen((char *)format));
	}
	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX", format[i +1]))
		{
			if (format[i + 1] == 'd')
			{
				n = va_arg(args, int);
				ft_putnbr_fd(n, 1);
				i += 2;
			}
			if (format[i + 1] == 's')
			{
			value = va_arg(args, char *);
			ft_putstr_fd((char *)value, 1);
			i += 2;
			}
		}
		if (format[i] == '%' && !ft_strchr("cspdiuxX", format[i +1]))
			i += 1;
		ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (1);
}

int	main(void)
{
	char	*str;
	const char	*str2;

	str = "ola mundo";
	int n = 10;
	ft_printf("OLA %d %% MUNDO %s\n", n, str);
	return (0);
}
