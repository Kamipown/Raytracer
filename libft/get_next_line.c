/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 10:33:01 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/04/19 13:14:05 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_strrevchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	ft_bzero(str, ft_strlen(s));
	if (!str)
		return (NULL);
	while (s[i] != '\0' && s[i] != (char)c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int			norme_gnl(char **line, char *temp, char *buf)
{
	temp = *line;
	*line = ft_strrevchr(*line, '\n');
	free(temp);
	temp = ft_strdup(buf);
	ft_bzero(buf, BUFF_SIZE + 1);
	ft_strcpy(buf, ft_strchr(temp, '\n') + 1);
	free(temp);
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	int			i;
	char		*str;
	static char	buf[INT_MAX][BUFF_SIZE + 1];
	char		*temp;

	if (line == NULL || fd < 0 || fd > INT_MAX)
		return (-1);
	*line = ft_strdup(buf[fd]);
	buf[fd][BUFF_SIZE] = '\0';
	while (!(ft_strchr(buf[fd], '\n')))
	{
		ft_bzero(buf[fd], BUFF_SIZE + 1);
		if ((i = read(fd, buf[fd], BUFF_SIZE)) <= 0)
			return ((ft_strlen(*line) > 0) ? 1 : i);
		str = ft_strdup(buf[fd]);
		temp = *line;
		*line = ft_strjoin(*line, str);
		free(temp);
		free(str);
		str = NULL;
	}
	return (norme_gnl(line, temp, buf[fd]));
}
