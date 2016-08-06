/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_counts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 08:50:54 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/08/02 08:50:56 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	valid_count(char *count)
{
	int		n;

	if (!ft_isdigit_str(count))
		error(5, "Parsing error. Not a number or negative value.");
	n = ft_atoi(count);
	if (n < 0)
		error(6, "Parsing error. Negative number.");
	return (n);
}

static void	get_counts(t_scene *s, char *str)
{
	char			**counts;
	unsigned int	i;

	counts = ft_strsplit(str, ' ');
	i = 0;
	while (counts[i])
		++i;
	if (i != 5)
		error(4, "Parsing error. Need 5 values.");
	s->n_light = valid_count(counts[0]);
	s->n_sphere = valid_count(counts[1]);
	s->n_cylinder = valid_count(counts[2]);
	s->n_cone = valid_count(counts[3]);
	s->n_plane = valid_count(counts[4]);
	i = 0;
	while (counts[i])
		free(counts[i++]);
	free(counts);
}

void		parse_counts(t_scene *s, int fd)
{
	char	*str;

	(void)s;
	if (get_next_line(fd, &str))
		get_counts(s, str);
	free(str);
}
