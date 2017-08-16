/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_min_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:58:21 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/23 22:58:30 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_data_minus(t_arg *arg, char c)
{
	int		n;
	int		len;
	char	*str;
	char	*tmp;

	tmp = arg->buf;
	len = ft_strlen(tmp);
	str = ft_strnew(arg->width);
	n = -1;
	while (n < arg->width)
	{
		if (len > 0)
		{
			while (tmp[++n])
			{
				str[n] = tmp[n];
				len--;
			}
		}
		str[n++] = c;
	}
	arg->buf = str;
	if (tmp)
		free(tmp);
}

void	ft_data(t_arg *arg, char c)
{
	int		n;
	int		i;
	char	*str;

	str = ft_strnew(arg->width);
	i = ft_strlen(arg->buf);
	if (arg->minus)
	{
		n = i;
		str = new_ft_strjoin(str, arg->buf);
		while (n < arg->width - i)
			str[n++] = c;
	}
	else
	{
		n = 0;
		while (n < arg->width - i)
			str[n++] = c;
		arg->buf = new_ft_strjoin(str, arg->buf);
	}
}

char	**ft_global_type(void)
{
	char	**global;
	int		n;

	global = (char **)malloc(sizeof(char *) * 7);
	n = -1;
	while (++n < 7)
		global[n] = ft_strnew(2);
	ft_strcpy(global[0], "t");
	ft_strcpy(global[1], "z");
	ft_strcpy(global[2], "j");
	ft_strcpy(global[3], "ll");
	ft_strcpy(global[4], "l");
	ft_strcpy(global[5], "h");
	ft_strcpy(global[6], "hh");
	return (global);
}

t_arg	*ft_create_arg(int n)
{
	t_arg	*arg;

	arg = (t_arg *)malloc(sizeof(t_arg));
	if (arg)
	{
		arg->n = n;
		arg->ii = 1;
		arg->zero = 0;
		arg->plus = 0;
		arg->minus = 0;
		arg->space = 0;
		arg->hash = 0;
		arg->width = 0;
		arg->precision = -1;
		ft_bzero(arg->length, 3);
		arg->flag = 0;
		arg->notvalid = 0;
		arg->buf = NULL;
		arg->data = NULL;
		arg->global = ft_global_type();
	}
	return (arg);
}
