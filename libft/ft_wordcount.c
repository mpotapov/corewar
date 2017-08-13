/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 20:13:22 by sromanet          #+#    #+#             */
/*   Updated: 2016/12/19 20:13:27 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char const *s, char c)
{
	int i;
	int w;
	int one;

	i = 0;
	w = 0;
	one = 1;
	while (s[i])
	{
		if (s[i] != c && one)
		{
			w++;
			one = 0;
		}
		else if (s[i] == c)
			one = 1;
		i++;
	}
	return (w);
}
