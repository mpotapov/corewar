/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_type_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:39:26 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/23 21:40:31 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_j(uintmax_t value, int base, t_arg *arg)
{
	char		*res;
	uintmax_t	v;
	int			n;

	res = NULL;
	v = value;
	while (v)
	{
		res = ft_first_zero(res, 0, 1);
		n = v % base;
		if (n <= 9)
			res[0] = n + 48;
		else if (arg->flag == 'x' || arg->flag == 'p')
			res[0] = n + 87;
		else if (arg->flag == 'X')
			res[0] = n + 55;
		v /= base;
	}
	if (value == 0 || arg->precision > (int)ft_strlen(res))
		res = ft_precision(value == 0, res, arg);
	if (arg->plus || arg->space)
		res = ft_signed(res, arg, 0);
	return (res);
}

char	*ft_itoa_base_z(size_t v, int base, t_arg *arg)
{
	char	*res;
	size_t	val;
	int		n;

	res = NULL;
	val = v;
	while (v)
	{
		res = ft_first_zero(res, 0, 1);
		n = v % base;
		if (n <= 9)
			res[0] = n + 48;
		else if (arg->flag == 'x' || arg->flag == 'p')
			res[0] = n + 87;
		else if (arg->flag == 'X')
			res[0] = n + 55;
		v /= base;
	}
	if (val == 0 || arg->precision > (int)ft_strlen(res))
		res = ft_precision(val == 0, res, arg);
	if (arg->plus || arg->space)
		res = ft_signed(res, arg, 0);
	return (res);
}

char	*ft_itoa_base_t(ptrdiff_t value, int base, t_arg *arg)
{
	char					*res;
	unsigned long long int	v;
	int						n;

	res = NULL;
	v = value;
	while (v)
	{
		res = ft_first_zero(res, 0, 1);
		n = v % base;
		if (n <= 9)
			res[0] = n + 48;
		else if (arg->flag == 'x' || arg->flag == 'p')
			res[0] = n + 87;
		else if (arg->flag == 'X')
			res[0] = n + 55;
		v /= base;
	}
	if (value == 0 || arg->precision > (int)ft_strlen(res))
		res = ft_precision(value == 0, res, arg);
	if (arg->plus || arg->space)
		res = ft_signed(res, arg, 0);
	return (res);
}
