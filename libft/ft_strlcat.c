/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:34:06 by sromanet          #+#    #+#             */
/*   Updated: 2016/12/26 16:45:40 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		n;

	n = ft_strlen(dst);
	if (n >= size)
		return (size + ft_strlen(src));
	else
		while (n < size - 1 && *src)
			dst[n++] = *src++;
	dst[n] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}
