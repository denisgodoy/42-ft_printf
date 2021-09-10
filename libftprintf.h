/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 00:23:43 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/09 23:14:23 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
char	*ft_strrev(char *str);
char	*ft_utoa_hex(int n);
char	*ft_utoa(int n);

#endif