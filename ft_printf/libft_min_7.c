/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_min_7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 17:24:34 by sromanet          #+#    #+#             */
/*   Updated: 2017/04/07 17:24:54 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*unicode_to_utf8(wchar_t c)
{
	char	*utf;

	utf = ft_strnew(4);
	if (c < (1 << 7))
		utf[0] = (char)(c);
	else if (c < (1 << 11))
	{
		utf[0] = (char)((c >> 6) | 0xC0);
		utf[1] = (char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 16))
	{
		utf[0] = (char)(((c >> 12)) | 0xE0);
		utf[1] = (char)(((c >> 6) & 0x3F) | 0x80);
		utf[2] = (char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
	{
		utf[0] = (char)(((c >> 18)) | 0xF0);
		utf[1] = (char)(((c >> 12) & 0x3F) | 0x80);
		utf[2] = (char)(((c >> 6) & 0x3F) | 0x80);
		utf[3] = (char)((c & 0x3F) | 0x80);
	}
	return (utf);
}
