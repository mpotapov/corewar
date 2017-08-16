/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:40:35 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/23 21:41:46 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_int(unsigned int value, int base, t_arg *arg)
{
	char			*res;
	unsigned int	v;
	int				n;

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
	if ((value == 0 || arg->precision > (int)ft_strlen(res)
			|| arg->width > (int)ft_strlen(res)) && arg->precision != -2)
		res = ft_precision(value == 0, res, arg);
	if (arg->plus || arg->space)
		res = ft_signed(res, arg, 0);
	return (res);
}

char	*ft_itoa_base_hh(unsigned char value, int base, t_arg *arg)
{
	char			*res;
	unsigned char	v;
	int				n;

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

char	*ft_itoa_base_h(unsigned short int value, int base, t_arg *arg)
{
	char				*res;
	unsigned short int	v;
	int					n;

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

char	*ft_itoa_base_l(long int value, int base, t_arg *arg)
{
	char				*res;
	unsigned long int	v;
	int					n;

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

char	*ft_itoa_base_ll(unsigned long long int value, int base, t_arg *arg)
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
	if ((arg->plus || arg->space) && arg->flag != 'p')
		res = ft_signed(res, arg, 0);
	return (res);
}
