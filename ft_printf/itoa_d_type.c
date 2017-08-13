/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_d_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:42:08 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/23 21:44:10 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_int(int value, t_arg *arg)
{
	char			*res;
	unsigned int	v;

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
	if ((value == 0 || arg->precision > (int)ft_strlen(res)
				|| arg->width > (int)ft_strlen(res)) && arg->precision != -2)
		res = ft_precision(value == 0, res, arg);
	if (value < 0 || arg->plus || arg->space)
		res = ft_signed(res, arg, value < 0);
	return (res);
}

char	*ft_itoa_hh(signed char value, t_arg *arg)
{
	char			*res;
	unsigned char	v;

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

char	*ft_itoa_h(short int value, t_arg *arg)
{
	char				*res;
	unsigned short int	v;

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

char	*ft_itoa_l(long int value, t_arg *arg)
{
	char				*res;
	unsigned long int	v;

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

char	*ft_itoa_ll(long long int value, t_arg *arg)
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
		res = ft_signed(res, arg, value < 0);
	return (res);
}
