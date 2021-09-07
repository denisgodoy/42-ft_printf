/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:22:40 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/07 18:23:57 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include 	<stdio.h>
#include 	<limits.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*value;
	char	*temp;
	char	new_arr[100];
	size_t 	i;
	size_t 	j;

	if (!format)
		return (-1);
	if (!ft_strchr(format, '%'))
	{
		ft_putstr_fd((char *)format, 1);
		return (ft_strlen((char *)format));
	}
	va_start(args, format);
	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX", format[i +1]))
		{
			if (format[i + 1] == 'd')
			{
				temp = ft_itoa(va_arg(args, int));
				ft_strlcpy(&new_arr[j], temp, ft_strlen(temp) + ft_strlen(new_arr));
				j += ft_strlen(temp);
				free(temp);
			}
			else if (format[i + 1] == 's')
			{
				value = va_arg(args, char *);
				ft_strlcpy(&new_arr[j], value, ft_strlen(value) + ft_strlen(new_arr));
				j += ft_strlen(value);
			}
			i += 2;
		}
		if (i > ft_strlen(format))
			break ;
		else
			new_arr[j++] = format[i++];
	}
	va_end(args);
	ft_putstr_fd(new_arr, 1);
	ft_putnbr_fd(ft_strlen(new_arr), 1);
	return (ft_strlen(new_arr));
}

int	main(void)
{
	char	*str;
	int ret;
	
	str = "olá mundo";
	int n = INT_MIN;
	int nbr = INT_MAX;
	ft_printf("OLÁ MUNDO %d %s", n, str);
	return (0);
}
