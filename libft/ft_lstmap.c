/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:00:46 by sromanet          #+#    #+#             */
/*   Updated: 2016/12/23 18:10:50 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;

	if (lst && f)
	{
		fresh = (t_list *)malloc(sizeof(f(lst)));
		if (!fresh)
			return (0);
		fresh = f(lst);
		fresh->next = ft_lstmap(lst->next, f);
		return (fresh);
	}
	return (0);
}
