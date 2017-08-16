/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:14:18 by sromanet          #+#    #+#             */
/*   Updated: 2016/12/26 18:20:34 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*copy;
	unsigned int	i;

	if (!s)
		return (NULL);
	copy = ft_strnew(ft_strlen(s));
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = f(i, s[i]);
		i++;
	}
	return (copy);
}
