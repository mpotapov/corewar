/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:55:50 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/23 22:23:05 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_first_zero(char *s, int a, int b)
{
	char *new;

	if (!s)
		new = ft_strnew(1);
	else
		new = ft_strnew(ft_strlen(s) + 1);
	new[0] = '0';
	if (s)
		while (s[a])
			new[b++] = s[a++];
	free(s);
	return (new);
}
