/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_d_type_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:44:15 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/23 21:44:33 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_j(intmax_t value, t_arg *arg)
{
	char		*res;
	uintmax_t	v;

	res = NULL;
	v = value;
	if (value < 0)
		v = value * -1;
	while (v)
	{
		res = ft_first_zero(res, 0, 1);
		res[0] = (v % 10) + '0';
		v /= 10;
	}
	if (value == 0 || arg->precision > (int)ft_strlen(res))
		res = ft_precision(value == 0, res, arg);
	if (value < 0 || arg->plus || arg->space)
		res = ft_signed(res, arg, value < 0);
	return (res);
}

char	*ft_itoa_z(size_t v, t_arg *arg, int z)
{
	char	*res;
	size_t	n;

	res = NULL;
	n = v;
	while (v)
	{
		res = ft_first_zero(res, 0, 1);
		res[0] = (v % 10) + '0';
		v /= 10;
	}
	if (n == 0 || arg->precision > (int)ft_strlen(res))
		res = ft_precision(n == 0, res, arg);
	if (arg->plus || arg->space || z)
		res = ft_signed(res, arg, z);
	return (res);
}

char	*ft_itoa_t(ptrdiff_t value, t_arg *arg)
{
	char					*res;
	unsigned long long int	v;

	res = NULL;
	v = value;
	if (value < 0)
		v = value * -1;
	while (v)
	{
		res = ft_first_zero(res, 0, 1);
		res[0] = (v % 10) + '0';
		v /= 10;
	}
	if (value == 0 || arg->precision > (int)ft_strlen(res))
		res = ft_precision(value == 0, res, arg);
	if (value < 0 || arg->plus || arg->space)
		res = ft_signed(res, arg, 0);
	return (res);
}
