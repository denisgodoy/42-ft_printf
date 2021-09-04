/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:22:40 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/04 19:18:59 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_printf(const char *, ...);

int	ft_printf(const char	*format, ...)
{
	va_list	args;
	char	*value;
	size_t	args_count;

	args_count = ft_count_format(format);
	va_start(args, format);
	while (args_count)
	{
		value = va_arg(args, char *);
		ft_putstr_fd((char *)value, 1);
		args_count--;
	}
	va_end(args);
	return (1);
}

int main(void)
{
	char	*str;
	char	*str2;

	str = "olá mundo";
	str2 = "hello world";
	ft_printf("%s %s", str, str2);
	return(0);
}
