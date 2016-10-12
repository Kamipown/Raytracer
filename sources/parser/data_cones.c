/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_cones.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:18:06 by dcognata          #+#    #+#             */
/*   Updated: 2016/09/17 14:11:56 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	print_cone(t_scene *s)
{
	int		i;

	i = 0;
	while (i < s->n_cone)
	{
		ft_putstr("cone ");
		ft_putnbr(i);
		ft_putstr(" : ");
		ft_putstr("\tpos(");
		ft_putnbr(s->cones[i].pos.x);
		ft_putstr(", ");
		ft_putnbr(s->cones[i].pos.y);
		ft_putstr(", ");
		ft_putnbr(s->cones[i].pos.z);
		ft_putstr(") color(");
		ft_putnbr(s->cones[i].color);
		ft_putendl(")");
		++i;
	}
	ft_putchar('\n');
}

void		fill_cones_data(t_scene *s, char *data)
{
	int		i;
	char	*request;

	i = 0;
	while (i < s->n_cone)
	{
		request = construct_request_int("cones.#.pos.x", i);
		s->cones[i].pos.x = read_int_data(data, request);
		free(request);
		request = construct_request_int("cones.#.pos.y", i);
		s->cones[i].pos.y = read_int_data(data, request);
		free(request);
		request = construct_request_int("cones.#.pos.z", i);
		s->cones[i].pos.z = read_int_data(data, request);
		free(request);
		request = construct_request_int("cones.#.color", i);
		s->cones[i].color = read_color_data(data, request);
		free(request);
		++i;
	}
	print_cone(s);
}
