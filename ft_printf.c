/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:22:40 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/08 23:36:28 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	<limits.h>
#include	<stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*temp;
	char	temp_c;
	size_t	i;
	size_t	size;

	size = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			if (ft_strchr("di", format[i + 1]))
			{
				temp = ft_itoa(va_arg(args, int));
				ft_putstr_fd(temp, 1);
				size += ft_strlen(temp);
				free(temp);
			}
			else if (format[i + 1] == 's')
			{
				temp = va_arg(args, char *);
				if (!temp)
				{
					ft_putstr_fd("(null)", 1);
					size += 6;
				}
				else
				{
					ft_putstr_fd(temp, 1);
					size += ft_strlen(temp);
				}
			}
			else if (format[i + 1] == '%')
			{
				ft_putchar_fd('%', 1);
				size++;
			}
			else if (format[i + 1] == 'c')
			{
				temp_c = va_arg(args, int);
				ft_putchar_fd(temp_c, 1);
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
	return ((int)size);
}

int	main(void)
{
	int ret = ft_printf("%s %d %i %s", NULL, INT_MAX, INT_MIN, "hello world");
	ft_printf("\n%d\n", ret);
	int ret2 = printf("%s %d %i %s", NULL, INT_MAX, INT_MIN, "hello world");
	printf("\n%d\n", ret2);
	return (0);
}
