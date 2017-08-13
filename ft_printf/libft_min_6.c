/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_min_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:08:58 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/29 19:09:00 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_data_flag(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
		|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'
		|| c == 'c' || c == 'C' || c == '%' || c == 'n')
		return (1);
	return (0);
}

int	ft_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

int	ft_type(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 't')
		return (1);
	return (0);
}

int	tk(char c, char s)
{
	if (c == 0)
		return (1);
	if (c == s)
		return (1);
	return (0);
}

int	ft_all(char c)
{
	if (!ft_flag(c) && c != '.' && c != '*' && !ft_isdigit(c) && c != '+'
												&& c != '-' && !ft_type(c))
		return (1);
	return (0);
}
