/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:05:40 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/23 21:45:39 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_per_minus(t_arg *arg)
{
	int		n;
	char	*str;

	str = ft_strnew(arg->width);
	n = 0;
	while (n < arg->width)
	{
		if (n == 0)
			str[n++] = '%';
		str[n++] = ' ';
	}
	arg->buf = str;
}

void			ft_per(t_arg *arg, int i)
{
	int		n;
	char	*str;

	str = ft_strnew(arg->width);
	n = 0;
	while (n < arg->width)
	{
		while (arg->width > i++)
		{
			if (arg->zero == 0)
				str[n++] = ' ';
			else
				str[n++] = '0';
		}
		str[n++] = '%';
	}
	arg->buf = str;
}

void			ft_data_per(t_arg *arg)
{
	if (arg->width && arg->width > 1)
	{
		if (arg->minus)
			ft_per_minus(arg);
		else
			ft_per(arg, 1);
	}
	else
	{
		arg->buf = ft_strnew(1);
		arg->buf[0] = '%';
	}
}

void			ft_choice_function(t_arg *arg, va_list ap, char **global)
{
	if (ft_data_flag(arg->flag) && arg->flag != '%' && !arg->notvalid)
		arg->data = va_arg(ap, void *);
	else
		;
	if (arg->flag == '%')
		ft_data_per(arg);
	else if (arg->flag == 'p')
		ft_data_p(arg);
	else if (arg->flag == 'd' || arg->flag == 'i' || arg->flag == 'D')
		ft_data_d(arg, global);
	else if (arg->flag == 'o' || arg->flag == 'O')
		ft_data_o(arg, global);
	else if (arg->flag == 'u' || arg->flag == 'U')
		ft_data_u(arg, global);
	else if (arg->flag == 'x' || arg->flag == 'X')
		ft_data_x(arg, global);
	else if (arg->flag == 's' || arg->flag == 'S')
		ft_data_s(arg, global);
	else if (arg->flag == 'c' || arg->flag == 'C')
		ft_data_c(arg);
}
