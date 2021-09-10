/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:22:40 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/09 21:53:02 by degabrie         ###   ########.fr       */
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
	int		temp_i;
	size_t	i;
	size_t	j;
	size_t	size;

	size = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	j = 0;
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
			else if (format[i + 1] == 'u')
			{
				temp = ft_utoa(va_arg(args, int));
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
			else if (ft_strchr("xX", format[i + 1]))
			{
				temp = ft_utoa_hex(va_arg(args, int));
				if (format[i + 1] == 'X')
				{
					while (temp[j])
					{
						temp[j] = ft_toupper(temp[j]);
						j++;
					}
					j = 0;
				}
				ft_putstr_fd(temp, 1);
				size += ft_strlen(temp);
				free(temp);
			}
			else if (format[i + 1] == 'p')
			{
				temp_i = va_arg(args, int);
				if (!temp_i)
				{
					ft_putstr_fd("0x0", 1);
					size += 3;
				}
				else
				{
					temp = ft_utoa_hex(temp_i);
					ft_putstr_fd("0x", 1);
					ft_putstr_fd(temp, 1);
					size += (ft_strlen(temp) + 2);
					free(temp);
				}
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

// int	main(void)
// {
// 	char *str = "42";
// 	int ret = ft_printf("OLÁ %s %d %i HELLO %s %%%% %u %x %X %x %p %p ", NULL, INT_MAX, INT_MIN, "world", -111, 0, -1000, -99, (void *)str, (void *)0);
// 	ft_printf("\n%d\n", ret);
// 	int ret2 = printf("OLÁ %s %d %i HELLO %s %%%% %u %x %X %x %p %p ", NULL, INT_MAX, INT_MIN, "world", -111, 0, -1000, -99, (void *)str, (void *)0);
// 	printf("\n%d\n", ret2);
// 	return (0);
// }
