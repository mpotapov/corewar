/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_min_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 18:02:51 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/28 18:03:11 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_arg(t_arg *arg, int n)
{
	if (arg)
	{
		if (arg->buf)
			free(arg->buf);
		if (arg->global)
		{
			while (++n < 7)
				free(arg->global[n]);
			free(arg->global);
		}
		free(arg);
	}
}

void	ft_check_data(t_arg *arg, const char *f, int i)
{
	if (ft_data_flag(f[i + arg->ii]))
		arg->flag = f[i + arg->ii];
}

void	ft_check_type(t_arg *arg, const char *f, int i, char **global)
{
	char	*tmp;
	int		t;

	tmp = ft_strnew(2);
	if (ft_type(f[i + arg->ii]) && (t = -1))
	{
		while (ft_type(f[i + arg->ii + ++t]) && tk(tmp[0], f[i + arg->ii + t]))
			tmp[t] = f[i + arg->ii + t];
	}
	if (ft_type(arg->length[0]))
	{
		if (ft_size_length(tmp, arg->length, global))
		{
			ft_strcpy(arg->length, tmp);
			arg->ii += ft_strlen(arg->length);
		}
		else
			arg->ii += ft_strlen(tmp);
	}
	else
	{
		ft_strcpy(arg->length, tmp);
		arg->ii += ft_strlen(arg->length);
	}
	free(tmp);
}

void	ft_return_n(va_list ap, int n)
{
	int *i;

	i = va_arg(ap, int *);
	*i = n;
}
