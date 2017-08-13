/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:48:32 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/23 21:50:00 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c_minus(t_arg *arg, char s)
{
	int		n;
	char	*str;

	str = ft_strnew(arg->width);
	n = 0;
	while (n < arg->width)
	{
		if (n == 0)
			str[n++] = s;
		str[n++] = ' ';
	}
	arg->buf = str;
}

void	ft_c(t_arg *arg, int i, char c, char s)
{
	int		n;
	char	*str;

	str = ft_strnew(arg->width);
	n = 0;
	while (n < arg->width)
	{
		while (arg->width > i++)
			str[n++] = c;
		str[n++] = s;
	}
	arg->buf = str;
}

void	ft_data_c(t_arg *arg)
{
	char	s;

	if (!arg->notvalid)
	{
		if ((char)arg->data == 0)
			s = -1;
		else
			s = (char)arg->data;
	}
	else
		s = arg->notvalid;
	if (arg->width && arg->width > 1)
	{
		if (arg->minus)
			ft_c_minus(arg, s);
		else
			(arg->zero == 0) ? ft_c(arg, 1, ' ', s) : ft_c(arg, 1, '0', s);
	}
	else
	{
		arg->buf = ft_strnew(1);
		arg->buf[0] = s;
	}
}
