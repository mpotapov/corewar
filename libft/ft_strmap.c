/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:40:24 by sromanet          #+#    #+#             */
/*   Updated: 2016/12/26 18:20:19 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*copy;
	int		i;

	if (!s)
		return (NULL);
	copy = ft_strnew(ft_strlen(s));
	i = 0;
	if (copy)
		while (*s)
			copy[i++] = f(*s++);
	return (copy);
}
