/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:22:40 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/15 18:16:11 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;
	int		i;
	int		k;

	if (!format)
		return (-1);
	size = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("# +cspdiuxX%", format[i + 1]))
		{
			k = i;
			if (ft_strchr("# +", format[i + 1]))
			{
				while (!ft_strchr("csdixX", format[k++]))
					size += ft_pre_format(format[i + 1], format[k], args);
				i = k - 2;
			}
			else
				size += ft_format_str(format[i + 1], args);
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
