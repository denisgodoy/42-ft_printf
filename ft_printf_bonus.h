/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 00:23:43 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/20 11:55:52 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include "42-libft/libft.h"

int		ft_flag_format(int p, int c, va_list args);
int		ft_format(int c, va_list args);
int		ft_printf(const char *format, ...);
int		ft_put_di(va_list args);
int		ft_put_u(va_list args);
int		ft_put_x(int c, va_list args);
int		ft_put_cs(int c, va_list args);
int		ft_put_p(va_list args);
char	*ft_stoa_hex(size_t n);
char	*ft_strrev(char *str);
char	*ft_utoa_hex(int n);
char	*ft_utoa(int n);

#endif