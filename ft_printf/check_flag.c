/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:05:31 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/23 21:45:21 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag(t_arg *arg, const char *f, int i)
{
	while (f[i + arg->ii] == '-' || f[i + arg->ii] == '+'
		|| f[i + arg->ii] == ' ' || f[i + arg->ii] == '#'
		|| f[i + arg->ii] == '0' || f[i + arg->ii] == 39)
	{
		if (f[i + arg->ii] == '-')
			arg->minus = 1;
		else if (f[i + arg->ii] == '+')
			arg->plus = 1;
		else if (f[i + arg->ii] == ' ')
			arg->space = 1;
		else if (f[i + arg->ii] == '#')
			arg->hash = 1;
		else if (f[i + arg->ii] == '0')
			arg->zero = 1;
		arg->ii++;
	}
}

int		ft_atoi_str(const char *f, int i)
{
	int r;

	r = 0;
	while (f[i] >= '0' && f[i] <= '9')
		r = r * 10 + (f[i++] - '0');
	return (r);
}

void	ft_check_width(t_arg *arg, const char *f, int i, va_list ap)
{
	if (f[i + arg->ii] == '*')
	{
		arg->width = va_arg(ap, int);
		arg->ii += 1;
	}
	else if (ft_isdigit(f[i + arg->ii]))
	{
		arg->width = ft_atoi_str(f, i + arg->ii);
		arg->ii += ft_nbr_len(f, i + arg->ii);
	}
	if (arg->width < 0)
	{
		arg->width *= -1;
		arg->minus = 1;
	}
}

void	ft_check_precision(t_arg *arg, const char *f, int i, va_list ap)
{
	if (f[i + arg->ii] == '.')
	{
		arg->ii++;
		if (f[i + arg->ii] == '*')
		{
			arg->precision = va_arg(ap, int);
			arg->ii++;
		}
		else if (ft_isdigit(f[i + arg->ii]))
		{
			arg->precision = ft_atoi_str(f, i + arg->ii);
			arg->ii += ft_nbr_len(f, i + arg->ii);
		}
		if (arg->precision == -1)
			arg->precision = -2;
	}
}

int		ft_size_length(char *tmp, char *length, char **global)
{
	int a;
	int b;

	a = -1;
	while (++a < 7)
		if (ft_strequ(tmp, global[a]))
			break ;
	b = -1;
	while (++b < 7)
		if (ft_strequ(length, global[b]))
			break ;
	if (a < b)
		return (1);
	return (0);
}
