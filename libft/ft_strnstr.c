/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:00:50 by sromanet          #+#    #+#             */
/*   Updated: 2016/12/26 17:02:47 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *l, size_t len)
{
	size_t	i;
	size_t	n;

	if (l[0] == '\0')
		return ((char *)big);
	i = 0;
	n = 0;
	while (big[i] && i < len)
	{
		while (big[i] && l[n] && big[i] == l[n] && i < len)
		{
			i++;
			n++;
		}
		if (n == ft_strlen(l))
			return ((char *)big + i - n);
		else
			i = (i - n) + 1;
		n = 0;
	}
	return (NULL);
}
