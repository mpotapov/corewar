/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 13:39:16 by sromanet          #+#    #+#             */
/*   Updated: 2016/12/23 18:17:27 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa(int n)
{
	char			*num;
	int				len;
	unsigned int	m;

	len = ft_nbrlen(n);
	num = ft_strnew(len);
	if (!num)
		return (0);
	m = n;
	if (n < 0)
	{
		num[0] = '-';
		m = -n;
	}
	if (n == 0)
		num[0] = '0';
	num[len--] = '\0';
	while (m != 0)
	{
		num[len--] = (m % 10) + '0';
		m /= 10;
	}
	return (num);
}
