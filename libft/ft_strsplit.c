/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 14:10:17 by sromanet          #+#    #+#             */
/*   Updated: 2016/12/26 18:21:51 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		w;
	int		len;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * ft_wordcount(s, c) + 1);
	if (!str)
		return (NULL);
	w = 0;
	i = 0;
	while (w < ft_wordcount(s, c))
	{
		len = ft_wordlen(s, c, &i);
		str[w] = ft_strsub(s, i, len);
		i += len;
		w++;
	}
	str[w] = NULL;
	return (str);
}
