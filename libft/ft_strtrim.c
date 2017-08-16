/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 19:22:22 by sromanet          #+#    #+#             */
/*   Updated: 2016/12/26 18:21:31 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ws(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*str;

	start = 0;
	str = NULL;
	if (!s)
		return (NULL);
	while (ws(s[start]) == 1)
		start++;
	end = (ft_strlen(s)) - 1;
	while (ws(s[end]) == 1)
		end--;
	end++;
	if (start >= end)
		str = ft_strdup("\0");
	else
		str = ft_strsub(s, start, (end - start));
	return (str);
}
