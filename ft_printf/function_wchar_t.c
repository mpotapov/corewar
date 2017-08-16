/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_wchar_t.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:05:02 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/23 21:55:12 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wchar_t_precision(t_arg *arg)
{
	int		n;
	int		len;
	char	*str;
	char	*tmp;
	wchar_t	*wchar;

	wchar = (wchar_t *)arg->data;
	str = ft_strnew(1);
	len = 0;
	n = -1;
	while (len < arg->precision)
	{
		tmp = unicode_to_utf8(wchar[++n]);
		if ((len += ft_strlen(tmp)) > arg->precision)
			break ;
		str = new_ft_strjoin(str, tmp);
	}
	if (arg->buf)
		free(arg->buf);
	arg->buf = str;
}

void	ft_ls_width(t_arg *arg, int i)
{
	int		n;
	char	*str;

	str = ft_strnew(arg->width);
	n = 0;
	while (arg->width > i++)
	{
		if (arg->zero == 1)
			str[n++] = '0';
		else
			str[n++] = ' ';
	}
	str = new_ft_strjoin(str, arg->buf);
	arg->buf = str;
}

void	ft_ls(t_arg *arg)
{
	int		n;
	char	*str;
	wchar_t	*tmp;

	tmp = (wchar_t *)arg->data;
	str = ft_strnew(1);
	n = -1;
	while (tmp[++n])
		str = new_ft_strjoin(str, unicode_to_utf8(tmp[n]));
	arg->buf = str;
}

void	ft_data_wchar_t(t_arg *arg)
{
	int		i;

	if (arg->data == NULL)
		arg->buf = ft_write_null(6);
	else
	{
		ft_ls(arg);
		if (arg->precision >= 0)
			if ((int)ft_strlen(arg->buf) > arg->precision)
				ft_wchar_t_precision(arg);
		i = ft_strlen(arg->buf);
		if (arg->width && arg->width > i)
		{
			if (arg->minus)
				ft_ls_minus(arg);
			else
				ft_ls_width(arg, i);
		}
	}
}
