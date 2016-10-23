/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 15:36:13 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/11/09 15:40:02 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*telem;
	t_list	*prev;

	ret = NULL;
	if (lst && f)
	{
		ret = (*f)(lst);
		prev = ret;
		lst = lst->next;
		while (lst)
		{
			telem = (*f)(lst);
			prev->next = telem;
			prev = telem;
			lst = lst->next;
		}
		prev->next = NULL;
	}
	return (ret);
}
