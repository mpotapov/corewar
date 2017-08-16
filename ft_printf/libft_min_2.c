/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_min_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:23:14 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/23 22:23:16 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	new_ft_strjoin_2(char *fresh, char *s2)
{
	char *ptr2;

	if (s2)
	{
		ptr2 = s2;
		while (*s2)
			*(fresh++) = *(s2++);
		free(ptr2);
		s2 = NULL;
	}
}

char		*new_ft_strjoin(char *s1, char *s2)
{
	char	*fresh;
	char	*ptr1;
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	if (s1)
		i += ft_strlen(s1);
	if (s2)
		i += ft_strlen(s2);
	fresh = ft_strnew(i);
	if (fresh && s1)
	{
		tmp = fresh;
		ptr1 = s1;
		while (*s1)
			*(fresh++) = *(s1++);
		free(ptr1);
		s1 = NULL;
	}
	new_ft_strjoin_2(fresh, s2);
	return (tmp);
}

char		*ft_str_spase(size_t n)
{
	char	*space;

	space = (char *)malloc(sizeof(char) * n + 1);
	space[n] = '\0';
	while (n)
		space[--n] = ' ';
	return (space);
}

void		ft_ls_minus(t_arg *arg)
{
	int		len;

	len = arg->width - ft_strlen(arg->buf);
	arg->buf = new_ft_strjoin(arg->buf, ft_str_spase(len));
}

void		ft_putstr_zero(char const *s)
{
	size_t	n;

	n = 0;
	if (s)
		while (s[n])
			write(1, &s[n++], 1);
}
