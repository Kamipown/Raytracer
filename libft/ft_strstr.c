/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 15:44:47 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/01/14 10:11:47 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strstr_loop(char **ts1, char **ts2)
{
	while (**ts1 == **ts2 && **ts2 && **ts2)
	{
		++(*ts2);
		++(*ts1);
	}
}

char		*ft_strstr(const char *s1, const char *s2)
{
	char	*ts1;
	char	*ts2;
	char	*ret;
	char	*tstr;

	tstr = (char *)s1;
	if (!*s2)
		return ((char*)s1);
	while (*tstr)
	{
		ts1 = (char*)tstr;
		ts2 = (char *)s2;
		while ((*ts1 != *ts2) && *ts1)
			++ts1;
		ret = ts1;
		ft_strstr_loop(&ts1, &ts2);
		if (!(*ts2))
			return (ret);
		++tstr;
	}
	return (NULL);
}
