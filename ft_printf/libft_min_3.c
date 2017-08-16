/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_min_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:24:58 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/23 22:25:01 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_signed(char *res, t_arg *arg, int minus)
{
	if (arg->flag == 'u' || arg->flag == 'U' || arg->flag == 'x'
		|| arg->flag == 'X' || arg->flag == 'o' || arg->flag == 'O')
		return (res);
	res = ft_first_zero(res, 0, 1);
	if (arg->space == 1)
		res[0] = ' ';
	if (minus == 1)
		res[0] = '-';
	else if (arg->plus == 1)
		res[0] = '+';
	return (res);
}

static	char	*ft_precision_2(char *res, t_arg *arg, int len)
{
	len = ft_strlen(res);
	while (arg->precision > len++)
	{
		if ((arg->flag == 'o' || arg->flag == 'O') && arg->hash == 1)
			len++;
		res = ft_first_zero(res, 0, 1);
	}
	len = ft_strlen(res);
	if (arg->zero == 1 && arg->width > len && arg->precision < 0
		&& arg->minus != 1 && arg->hash == 1
		&& (arg->flag == 'x' || arg->flag == 'X'))
		while (arg->width > ++len + 1)
			res = ft_first_zero(res, 0, 1);
	if (arg->zero == 1 && arg->width > len && arg->precision < 0
		&& arg->minus != 1)
	{
		if (arg->flag == 'p')
			len++;
		while (arg->width > ++len)
			res = ft_first_zero(res, 0, 1);
	}
	return (res);
}

char			*ft_precision(int zero, char *res, t_arg *arg)
{
	if (zero == 1)
	{
		if (arg->precision == 0 || arg->precision == -2 || (arg->precision <= 0
								&& arg->flag == 'o' && arg->length[0] == '\0'))
			return (res);
		else
			res = ft_first_zero(res, 0, 1);
	}
	res = ft_precision_2(res, arg, 0);
	return (res);
}

int				ft_nbr_len(const char *f, int i)
{
	int len;

	len = 0;
	while (ft_isdigit(f[i]))
	{
		len++;
		i++;
	}
	return (len);
}
