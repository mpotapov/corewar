/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:50:06 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/23 21:52:29 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_hash(t_arg *arg)
{
	if ((arg->flag == 'x' || arg->flag == 'X') && (int)arg->data)
	{
		arg->buf = ft_first_zero(arg->buf, 0, 1);
		arg->buf[0] = arg->flag;
		arg->buf = ft_first_zero(arg->buf, 0, 1);
	}
	if ((arg->flag == 'o' || arg->flag == 'O'))
		arg->buf = ft_first_zero(arg->buf, 0, 1);
	if (arg->flag == 'p')
	{
		arg->buf = ft_first_zero(arg->buf, 0, 1);
		arg->buf[0] = 'x';
		arg->buf = ft_first_zero(arg->buf, 0, 1);
	}
}

void			ft_data_width(t_arg *arg)
{
	if (((arg->flag == 'x' || arg->flag == 'X' || arg->flag == 'o'
				|| arg->flag == 'O') && arg->hash == 1) || arg->flag == 'p')
		ft_hash(arg);
	if (!arg->buf)
		arg->buf = ft_strnew(1);
	if (arg->width && arg->width > (int)ft_strlen(arg->buf))
	{
		if (arg->minus)
			ft_data_minus(arg, ' ');
		else
		{
			if (arg->zero && arg->precision <= -1)
				ft_data(arg, '0');
			else
				ft_data(arg, ' ');
		}
	}
}

static	void	ft_data_d2(t_arg *arg, char **global_type)
{
	if (ft_strequ(arg->length, global_type[2]))
	{
		arg->buf = ft_itoa_j((intmax_t)arg->data, arg);
		ft_data_width(arg);
	}
	else if (ft_strequ(arg->length, global_type[5]))
	{
		arg->buf = ft_itoa_h((short int)arg->data, arg);
		ft_data_width(arg);
	}
	else if (ft_strequ(arg->length, global_type[6]))
	{
		arg->buf = ft_itoa_hh((char)arg->data, arg);
		ft_data_width(arg);
	}
	else
	{
		arg->buf = ft_itoa_int((int)arg->data, arg);
		ft_data_width(arg);
	}
}

void			ft_data_d(t_arg *arg, char **global_type)
{
	if (ft_strequ(arg->length, global_type[0]))
	{
		arg->buf = ft_itoa_t((ptrdiff_t)arg->data, arg);
		ft_data_width(arg);
	}
	else if (ft_strequ(arg->length, global_type[3]))
	{
		arg->buf = ft_itoa_ll((long long int)arg->data, arg);
		ft_data_width(arg);
	}
	else if (ft_strequ(arg->length, global_type[4]) || arg->flag == 'D')
	{
		arg->buf = ft_itoa_l((long int)arg->data, arg);
		ft_data_width(arg);
	}
	else if (ft_strequ(arg->length, global_type[1]))
	{
		arg->buf = ft_itoa_z((size_t)arg->data, arg,
											(long long int)arg->data < 0);
		ft_data_width(arg);
	}
	else
		ft_data_d2(arg, global_type);
}
