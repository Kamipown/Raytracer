/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 17:01:40 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/08/16 01:40:41 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join_str(char *s1, char *s2)
{
	char	*ret;

	ret = NULL;
	if (s1 && s2)
	{
		if ((ret = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
			return (NULL);
		ft_strcpy(ret, s1);
		ft_strcat(ret, s2);
		free((char*)s1);
	}
	return (ret);
}

static int	cut_next_line(int fd, char **line, char **str, char *pos)
{
	int		ret;

	*line = ft_strdup(*str);
	while (!pos)
	{
		if ((ret = read(fd, *str, BUFF_SIZE)) < 0)
			return (-1);
		if ((pos = ft_strchr(*str, '\n')) == NULL && !ret)
			return ((*str)[0] = 0);
		else if (pos)
		{
			(*str)[ret] = ret ? 0 : (*str)[ret];
			pos[0] = 0;
			*line = join_str(*line, *str);
			ft_strcpy(*str, pos + 1);
		}
		else
		{
			(*str)[ret] = ret ? 0 : (*str)[ret];
			*line = join_str(*line, *str);
			(*str)[0] = 0;
		}
	}
	return (*line ? 1 : -1);
}

int			get_next_line(int const fd, char **line)
{
	static char	*str;
	int			ret;
	char		*pos;

	if (BUFF_SIZE < 1 || !line)
		return (-1);
	if (!str)
		if ((str = (char*)malloc(BUFF_SIZE + 1)) == NULL
				&& !(*str = 0))
			return (-1);
	pos = ft_strchr(str, '\n');
	if (pos)
	{
		pos[0] = 0;
		*line = ft_strdup(str);
		ft_strcpy(str, pos + 1);
		return (*line ? 1 : -1);
	}
	else
		ret = cut_next_line(fd, line, &str, NULL);
	if (ret == 0 && ft_strlen(*line) == 0)
		free(str);
	if (ret == -1)
		return (-1);
	return (ret ? 1 : ft_strlen(*line) != 0);
}
