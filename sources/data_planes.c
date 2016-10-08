/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_planes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 14:23:51 by dcognata          #+#    #+#             */
/*   Updated: 2016/10/08 22:06:41 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	print_plans_rest(t_scene *s, int i)
{
	ft_putnbr(s->planes[i].color);
	ft_putstr(") width(");
	ft_putnbr(s->planes[i].width);
	ft_putstr(") height(");
	ft_putnbr(s->planes[i].height);
	ft_putendl(")");
}

static void	print_plans(t_scene *s)
{
	int		i;

	i = 0;
	while (i < s->n_plane)
	{
		ft_putstr("Plane ");
		ft_putnbr(i);
		ft_putstr(" : ");
		ft_putstr("\tpos(");
		ft_putnbr(s->planes[i].pos.x);
		ft_putstr(", ");
		ft_putnbr(s->planes[i].pos.y);
		ft_putstr(", ");
		ft_putnbr(s->planes[i].pos.z);
		printf("\tnormal(%f, %f, %f", s->planes[i].normal.x, s->planes[i].normal.y, s->planes[i].normal.z);
		ft_putstr(") color(");
		print_plans_rest(s, i);
		++i;
	}
	ft_putchar('\n');
}

static void	fill_planes_data_rest(t_scene *s, char *data, char *request, int i)
{
	request = construct_request_int("planes.#.normal.x", i);
	s->planes[i].normal.x = read_double_data(data, request);
	free(request);
	request = construct_request_int("planes.#.normal.y", i);
	s->planes[i].normal.y = read_double_data(data, request);
	free(request);
	request = construct_request_int("planes.#.normal.z", i);
	s->planes[i].normal.z = read_double_data(data, request);
	free(request);
	request = construct_request_int("planes.#.size.height", i);
	s->planes[i].height = read_int_data(data, request);
	free(request);
	request = construct_request_int("planes.#.size.width", i);
	s->planes[i].width = read_int_data(data, request);
	free(request);
	request = construct_request_int("planes.#.color", i);
	s->planes[i].color = read_color_data(data, request);
	free(request);
}

void		fill_planes_data(t_scene *s, char *data)
{
	int		i;
	char	*request;

	i = 0;
	while (i < s->n_plane)
	{
		request = construct_request_int("planes.#.pos.x", i);
		s->planes[i].pos.x = read_int_data(data, request);
		free(request);
		request = construct_request_int("planes.#.pos.y", i);
		s->planes[i].pos.y = read_int_data(data, request);
		free(request);
		request = construct_request_int("planes.#.pos.z", i);
		s->planes[i].pos.z = read_int_data(data, request);
		free(request);
		fill_planes_data_rest(s, data, request, i);
		++i;
	}
	print_plans(s);
	return ;
}
