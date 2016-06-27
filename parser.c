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

static void	get_counts(t_scene *s, char *str)
{
	char			**counts;

	counts = ft_strsplit(str, ' ');
	if (counts[0])
		s->n_light = ft_atoi(counts[0]);
	else
		error(4, "Unable to parse the object counts.");
	if (counts[1])
		s->n_sphere = ft_atoi(counts[1]);
	else
		error(4, "Unable to parse the object counts.");
	if (counts[2])
		s->n_cylinder = ft_atoi(counts[2]);
	else
		error(4, "Unable to parse the object counts.");
	if (counts[3])
		s->n_cone = ft_atoi(counts[3]);
	else
		error(4, "Unable to parse the object counts.");
	if (counts[4])
		s->n_plane = ft_atoi(counts[4]);
	else
		error(4, "Unable to parse the object counts.");
	ft_putnbr(s->n_light); ft_putstr(" - ");
	ft_putnbr(s->n_sphere); ft_putstr(" - ");
	ft_putnbr(s->n_cylinder); ft_putstr(" - ");
	ft_putnbr(s->n_cone); ft_putstr(" - ");
	ft_putnbr(s->n_plane); ft_putchar('\n');
}

void		parse_scene(t_scene *s, char *filename)
{
	int		fd;
	char	*str;

	(void)s;
	if ((fd = open(filename, O_RDONLY)) == -1)
		error(3, "Unable to open the file. Check path.");
	if (get_next_line(fd, &str))
		get_counts(s, str);
	while (get_next_line(fd, &str))
	{
		ft_putendl(str);
		free(str);
	}
	free(str);
	close(fd);
}
