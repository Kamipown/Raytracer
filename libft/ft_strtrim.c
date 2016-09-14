/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 15:45:11 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/11/09 16:29:37 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_l_whitespaces(char const *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			return (i);
		++i;
	}
	return (i);
}

static size_t	ft_r_whitespaces(char const *s, size_t len)
{
	size_t	i;

	i = 0;
	while (len > 0)
	{
		if (s[len - 1] != ' ' && s[len - 1] != '\n' && s[len - 1] != '\t')
			return (i);
		--len;
		++i;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	lws;
	size_t	rws;
	char	*str;
	size_t	i;

	len = ft_strlen(s);
	lws = ft_l_whitespaces(s, len);
	rws = ft_r_whitespaces(s, len);
	if (lws == len)
		rws = 0;
	if ((str = (char *)malloc(sizeof(*str) * (len - lws - rws + 1))))
	{
		i = lws;
		while (s[i] && i < (len - rws))
		{
			str[i - lws] = s[i];
			++i;
		}
		str[i - lws] = '\0';
		return (str);
	}
	else
		return (NULL);
}
