/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 21:01:05 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/08/06 21:01:06 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static char	*join_data(char *data, char *add)
{
	char	*ret;
	int		i;
	int		j;

	if (!(ret = (char *)malloc(ft_strlen(data) + ft_strlen(add) + 2)))
		error(-10, "Unable to add data.");
	i = 0;
	while (data[i])
	{
		ret[i] = data[i];
		++i;
	}
	j = 0;
	while (add[j])
	{
		ret[i + j] = add[j];
		++j;
	}
	ret[i + j] = '\n';
	ret[i + j + 1] = '\0';
	free(data);
	free(add);
	return (ret);
}

char		*read_data(char *filename)
{
	char	*data;
	char	*line;
	int		fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	 	error(-9, "Unable to open the file. Check path or read access.");
	data = ft_strdup("");
	line = ft_strdup("");
	while (get_next_line(fd, &line) > 0)
		data = join_data(data, line);
	free(line);
	close(fd);
	return (data);
}
