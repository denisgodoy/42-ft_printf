/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:22:40 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/08 19:10:08 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include 	<stdio.h>
#include 	<limits.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*temp;
	size_t 	i;
	size_t	size;

	size = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX", format[i +1]))
		{
			if (format[i + 1] == 'd')
			{
				temp = ft_itoa(va_arg(args, int));
				size += ft_strlen(temp);
				ft_putstr_fd(temp, 1);
				free(temp);
			}
			else if (format[i + 1] == 's')
			{
				temp = va_arg(args, char *);
				size += ft_strlen(temp);
				ft_putstr_fd(temp, 1);
			}
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			size++;	
		}
		i++;
	}
	va_end(args);
	return (size);
}

int	main(void)
{
	int ret = ft_printf(" %d %d %s ", 10, 20, "hello");
	ft_printf("\n%d", ret);
	return (0);
}
