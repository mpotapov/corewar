/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 19:03:41 by sromanet          #+#    #+#             */
/*   Updated: 2016/12/26 18:21:16 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = ft_memalloc(1 + ft_strlen(s1) + ft_strlen(s2));
	if (!s3)
		return (NULL);
	return (ft_strcat(ft_strcpy(s3, s1), s2));
}
