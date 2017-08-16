/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:51:51 by sromanet          #+#    #+#             */
/*   Updated: 2016/12/23 17:59:04 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		n;
	int		over;
	size_t	r;

	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r' ||
			*str == '\f' || *str == '\v')
		str++;
	n = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	over = 0;
	r = 0;
	while (*str >= '0' && *str <= '9' && ++over)
		r = r * 10 + (*str++ - '0');
/*	if (over > 18 && n == 1 && !((int)r <= 2147483647))
		return (-1);
	if (!((int)r >= -2147483648) && n == -1)
		return (0);
*/	return ((int)r * n);
}
