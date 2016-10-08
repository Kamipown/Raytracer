/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_planes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 13:35:39 by dcognata          #+#    #+#             */
/*   Updated: 2016/10/08 18:34:57 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

static int	test_hit(t_ray *ray, t_plane *p)
{
	t_vec3	tmp_p0;
	t_vec3	tmp_l0;
	t_vec3	p0l0;
	t_vec3	n;
	double	denom;
	double 	num;
	double	t;


	num = 0;
	n = (t_vec3)
	{
		p->rot.x * M_PI / 180,
		p->rot.y * M_PI / 180,
		p->rot.z * M_PI / 180
	};
	vec_normalize(&n);
	denom = vec_mul_to_d(&n, &ray->dir);
	tmp_p0 = (t_vec3){p->pos.x, p->pos.y, p->pos.z};
	tmp_l0 = (t_vec3){ray->origin.x, ray->origin.y, ray->origin.z};
	vec_normalize(&tmp_p0);
	vec_normalize(&tmp_l0);
	p0l0 = vec_sub(&tmp_p0, &tmp_l0);
	num = vec_mul_to_d(&p0l0, &n);
	if (denom == 0)
	{
		return (0);
	}
	t = num / denom;
	if (denom > 0.1)
	{
		return (1);
	}
	return (0);
}


t_plane		*inter_planes(t_env *e, t_ray *ray, int x, int y)
{
	int		i;

	i = 0;
	while (i < e->scene->n_plane)
	{
		if (test_hit(ray, &e->scene->planes[i]))
		{
			draw_pixel(e, (t_pixel){x, y, e->scene->planes[i].color});
			return (&e->scene->planes[i]);
		}
		++i;
	}
	return (0);
}
