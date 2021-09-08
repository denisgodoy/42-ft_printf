/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:22:40 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/08 19:20:23 by degabrie         ###   ########.fr       */
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
		if (format[i] == '%' && ft_strchr("spdiuxX%", format[i + 1]))
		{
			if (format[i + 1] == 'd')
			{
				temp = ft_itoa(va_arg(args, int));
				ft_putstr_fd(temp, 1);
				size += ft_strlen(temp);
				free(temp);
			}
			else if (format[i + 1] == 's')
			{
				temp = va_arg(args, char *);
				ft_putstr_fd(temp, 1);
				size += ft_strlen(temp);
			}
			else if (format[i + 1] == '%')
			{
				ft_putchar_fd('%', 1);
				size++;
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
	int ret = ft_printf(" %d %% %s", 10, "hello");
	ft_printf("\n%d", ret);
	return (0);
}
