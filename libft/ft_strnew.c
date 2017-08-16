/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:39:44 by sromanet          #+#    #+#             */
/*   Updated: 2016/12/26 18:19:16 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*s;

	if ((s = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	if (s)
		ft_bzero(s, size + 1);
	return (s);
}
