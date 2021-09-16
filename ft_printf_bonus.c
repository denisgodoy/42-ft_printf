/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:22:40 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/16 10:09:34 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf_bonus.h"

static int	ft_convert(const char **format, int *size, va_list args, int i);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;
	int		i;

	if (!format)
		return (-1);
	size = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("# +cspdiuxX%", format[i + 1]))
			i = ft_convert(&format, &size, args, i);
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

static int	ft_convert(const char **format, int *size, va_list args, int i)
{
	int	j;

	if ((*format)[i] == '%' && ft_strchr("# +cspdiuxX%", (*format)[i + 1]))
	{
		j = i;
		if (ft_strchr("# +", (*format)[i + 1]))
		{
			while (!ft_strchr("sdixX", (*format)[j++]))
			{
				*size += ft_flag_format((*format)[i + 1], (*format)[j], args);
				if (ft_isdigit((*format)[j]))
				{
					ft_putchar_fd(' ', 1);
					*size += 1;
				}
			}
			i = j - 2;
		}
		else
			*size += ft_format((*format)[i + 1], args);
		i++;
	}
	return (i);
}
