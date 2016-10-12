/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_cylinders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:18:06 by dcognata          #+#    #+#             */
/*   Updated: 2016/09/17 14:11:56 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	print_cylinder(t_scene *s)
{
	int		i;

	i = 0;
	while (i < s->n_cylinder)
	{
		ft_putstr("Cylinder ");
		ft_putnbr(i);
		ft_putstr(" : ");
		ft_putstr("\tpos(");
		ft_putnbr(s->cylinders[i].pos.x);
		ft_putstr(", ");
		ft_putnbr(s->cylinders[i].pos.y);
		ft_putstr(", ");
		ft_putnbr(s->cylinders[i].pos.z);
		ft_putstr(") color(");
		ft_putnbr(s->cylinders[i].color);
		ft_putstr(") radius(");
		ft_putnbr(s->cylinders[i].radius);
		ft_putendl(")");
		++i;
	}
	ft_putchar('\n');
}

void		fill_cylinders_data(t_scene *s, char *data)
{
	int		i;
	char	*request;

	i = 0;
	while (i < s->n_cylinder)
	{
		request = construct_request_int("cylinders.#.pos.x", i);
		s->cylinders[i].pos.x = read_int_data(data, request);
		free(request);
		request = construct_request_int("cylinders.#.pos.y", i);
		s->cylinders[i].pos.y = read_int_data(data, request);
		free(request);
		request = construct_request_int("cylinders.#.pos.z", i);
		s->cylinders[i].pos.z = read_int_data(data, request);
		free(request);
		request = construct_request_int("cylinders.#.color", i);
		s->cylinders[i].color = read_color_data(data, request);
		free(request);
		request = construct_request_int("cylinders.#.radius", i);
		s->cylinders[i].radius = read_int_data(data, request);
		free(request);
		++i;
	}
	print_cylinder(s);
}
