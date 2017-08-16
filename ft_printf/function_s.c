/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:04:49 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/23 21:52:50 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_s_precision(t_arg *arg)
{
	int		n;
	char	*str;
	char	*tmp;

	n = -1;
	tmp = arg->buf;
	str = ft_strnew(arg->precision);
	while (++n < arg->precision)
		str[n] = tmp[n];
	free(tmp);
	arg->buf = str;
}

char			*ft_write_null(int i)
{
	char *buf;

	buf = ft_strnew(i);
	buf[0] = '(';
	buf[1] = 'n';
	buf[2] = 'u';
	buf[3] = 'l';
	buf[4] = 'l';
	buf[5] = ')';
	return (buf);
}

static	void	ft_data_s_2(t_arg *arg)
{
	if (arg->minus)
		ft_data_minus(arg, ' ');
	else
	{
		if (arg->zero == 0)
			ft_data(arg, ' ');
		else
			ft_data(arg, '0');
	}
}

void			ft_data_s(t_arg *arg, char **global_type)
{
	if (arg->precision == -2)
		arg->precision = 0;
	if (ft_strequ(arg->length, global_type[4]) || arg->flag == 'S')
	{
		ft_data_wchar_t(arg);
		return ;
	}
	if (arg->data == NULL)
		arg->buf = ft_write_null(6);
	else
	{
		arg->buf = ft_strnew(ft_strlen((char *)arg->data));
		arg->buf = ft_strcpy(arg->buf, (char *)arg->data);
	}
	if (arg->precision >= 0)
		if ((int)ft_strlen(arg->buf) > arg->precision)
			ft_s_precision(arg);
	if (arg->width && arg->width > (int)ft_strlen(arg->buf))
		ft_data_s_2(arg);
}
