/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:06:46 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/29 19:06:48 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_data_p(t_arg *arg)
{
	arg->buf = ft_itoa_base_ll((unsigned long long int)arg->data, 16, arg);
	ft_data_width(arg);
}
