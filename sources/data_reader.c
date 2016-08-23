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

static int		browse(char *line, char *request, int tabs)
{
	while (*line && *line == '\t')
	{
		++line;
		--tabs;
	}
	while (*line && *request && *line == *request && tabs == 0)
	{
		++line;
		++request;
	}
	if (*request == '.' && *line == '\0')
		return (1);
	else if (*request == '\0' && *line == ':')
		return (2);
	return (0);
}

static char		*proceed_request(char *request)
{
	while (*request && *request != '.')
		++request;
	return (request + 1);
}

static char		*read_value(char *line)
{
	char	*ret;
	int		i;

	i = 0;
	while (line[i] && line[i] != ':')
		++i;
	ret = (line[i + 1] ? ft_strdup(&line[i + 1]) : 0);
	free(line);
	return (ret);
}

char			*read_data(char *data, char *request)
{
	char	*line;
	int		tabs;
	int		ret;

	tabs = 0;
	while (*data)
	{
		line = ft_strdup_delim(data, '\n');
		data = ft_skip_line(data);
		ret = browse(line, request, tabs);
		if (ret == 1)
		{
			request = proceed_request(request);
			tabs++;
		}
		else if (ret == 2)
			return (read_value(line));
		free(line);
	}
	return (0);
}
