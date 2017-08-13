/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:55:17 by sromanet          #+#    #+#             */
/*   Updated: 2016/12/26 17:53:35 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *copy;

	copy = (unsigned char*)s;
	while (n--)
		if (*copy != (unsigned char)c)
			copy++;
		else
			return (copy);
	return (NULL);
}
