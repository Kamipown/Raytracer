/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_spheres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:18:06 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/17 14:11:56 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	print_spheres(t_scene *s)
{
	int		i;

	i = 0;
	while (i < s->n_sphere)
	{
		ft_putstr("Sphere ");
		ft_putnbr(i);
		ft_putstr(" : ");
		ft_putstr("\tpos(");
		ft_putnbr(s->spheres[i].pos.x);
		ft_putstr(", ");
		ft_putnbr(s->spheres[i].pos.y);
		ft_putstr(", ");
		ft_putnbr(s->spheres[i].pos.z);
		ft_putstr(") color(");
		ft_putnbr(s->spheres[i].color);
		ft_putstr(") radius(");
		ft_putnbr(s->spheres[i].radius);
		ft_putendl(")");
		++i;
	}
	ft_putchar('\n');
}

void		fill_spheres_data(t_scene *s, char *data)
{
	int		i;
	char	*request;

	i = 0;
	while (i < s->n_sphere)
	{
		request = construct_request_int("spheres.#.pos.x", i);
		s->spheres[i].pos.x = read_int_data(data, request);
		free(request);
		request = construct_request_int("spheres.#.pos.y", i);
		s->spheres[i].pos.y = read_int_data(data, request);
		free(request);
		request = construct_request_int("spheres.#.pos.z", i);
		s->spheres[i].pos.z = read_int_data(data, request);
		free(request);
		request = construct_request_int("spheres.#.color", i);
		s->spheres[i].color = read_color_data(data, request);
		free(request);
		request = construct_request_int("spheres.#.radius", i);
		s->spheres[i].radius = read_int_data(data, request);
		free(request);
		++i;
	}
	print_spheres(s);
}
