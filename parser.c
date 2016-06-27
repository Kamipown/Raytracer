/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:25:27 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/04/27 16:25:28 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_scene(t_scene *s, char *filename)
{
	int		fd;
	char	*str;

	(void)s;
	if ((fd = open(filename, O_RDONLY)) == -1)
		error(3, "Unable to open the file. Check path.");
	while (get_next_line(fd, &str))
	{
		ft_putendl(str);
		free(str);
	}
	free(str);
	close(fd);
}
