/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:37:31 by sromanet          #+#    #+#             */
/*   Updated: 2016/12/26 18:20:57 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	new = ft_strnew(len);
	if (!s || !new)
		return (NULL);
	i = 0;
	while (i != len)
		new[i++] = s[start++];
	return (new);
}
