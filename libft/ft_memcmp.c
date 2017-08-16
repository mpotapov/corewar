/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:13:24 by sromanet          #+#    #+#             */
/*   Updated: 2016/12/26 17:54:25 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *a;
	const unsigned char *b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (n--)
		if (*a != *b)
			return (*a - *b);
		else
		{
			a++;
			b++;
		}
	return (0);
}
