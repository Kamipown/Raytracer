/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_ff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 12:31:06 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/11/16 12:31:34 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_ff(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		while (s1[i])
		{
			str[i] = s1[i];
			++i;
		}
		while (s2[j])
		{
			str[i + j] = s2[j];
			++j;
		}
		str[i + j] = '\0';
		free(s2);
		free(s2);
		return (str);
	}
	return (NULL);
}
