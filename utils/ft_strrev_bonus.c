/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:18:41 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/15 15:11:32 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../ft_printf_bonus.h"

char	*ft_strrev(char *str)
{
	int		len;
	int		j;
	char	*ptr;

	j = 0;
	len = ft_strlen(str);
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (0);
	while (len)
		ptr[j++] = str[--len];
	return (ptr);
}
