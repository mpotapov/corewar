/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 19:58:24 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/23 21:47:57 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_kk(const char *f, int i, va_list ap, t_arg *arg)
{
	if (ft_flag(f[i + arg->ii]) && arg->precision != -2)
		ft_check_flag(arg, f, i);
	if (f[i + arg->ii] == '*' || ft_isdigit(f[i + arg->ii]))
		ft_check_width(arg, f, i, ap);
	if (f[i + arg->ii] == '.')
		ft_check_precision(arg, f, i, ap);
	if (ft_type(f[i + arg->ii]))
		ft_check_type(arg, f, i, arg->global);
	if (ft_all(f[i + arg->ii]) && f[i + arg->ii])
	{
		ft_check_data(arg, f, i);
		if (!ft_data_flag(arg->flag))
		{
			arg->data = (void *)&f[i + arg->ii];
			arg->notvalid = f[i + arg->ii];
			arg->flag = 'c';
		}
		if (arg->flag != 'n')
			ft_choice_function(arg, ap, arg->global);
		return (1);
	}
	return (0);
}

t_arg	*ft_arg(const char *f, int i, va_list ap, int n)
{
	t_arg *arg;

	arg = ft_create_arg(n);
	while (f[i + arg->ii])
		if (ft_kk(f, i, ap, arg))
			break ;
	return (arg);
}

int		ft_printf_kostyl_kostyl(char *str)
{
	ft_putstr(str);
	return (ft_strlen(str));
}

int		ft_printf_kostyl(const char *f, int i, va_list ap, int n)
{
	int		kostyl;
	t_arg	*arg;

	kostyl = 0;
	while (f[i] != '\0')
	{
		if (f[i] == '%')
		{
			arg = ft_arg(f, i, ap, ++kostyl);
			if (arg->flag == 'n')
				ft_return_n(ap, n + i - kostyl + arg->ii);
			n += ft_printf_kostyl_kostyl(arg->buf);
			(f[i + 1] != '\0') ? n -= arg->ii : 0;
			i += arg->ii;
			ft_free_arg(arg, -1);
		}
		else
			write(1, &f[i], 1);
		(f[i] != '\0') ? i++ : 0;
	}
	return (n + i - kostyl);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		n;

	va_start(ap, format);
	n = ft_printf_kostyl(format, 0, ap, 0);
	va_end(ap);
	if (n == -1)
		n = 0;
	return (n);
}
