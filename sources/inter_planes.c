/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_planes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 13:35:39 by dcognata          #+#    #+#             */
/*   Updated: 2016/10/08 22:11:15 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

t_vec3			mul_d_to_vec(double d, t_vec3 *v)
{
	t_vec3 ret;

	ret.x = v->x * d;
	ret.y = v->y * d;
	ret.z = v->z * d;
	return (ret);
}

static int	test_hit(t_ray *ray, t_plane *p, double *z)
{
	t_vec3	N;
	double	m;
	t_vec3	L;
	double	d;
	double	t;
	t_vec3	ret;
	t_vec3	tmp;

	N = (t_vec3)
	{
		p->normal.x,
		p->normal.y,
		p->normal.z
	};
	vec_normalize(&N);


	m = vec_mul_to_d(&N, &ray->dir);

	if (fabs(m) < 0.000001)
		return (0);
	L = vec_sub(&ray->origin, &p->pos);
	d = vec_mul_to_d(&N, &L);
	t = -d / m;
	if (t <= 0)
		return (0);
	tmp = mul_d_to_vec(t, &ray->dir);
	ret = vec_add(&ray->origin, &tmp);
	*z = ret.z;
	return (1);
}


void		inter_planes(t_env *e, t_ray *ray, t_intersection *inter)
{
	int		i;
	double	z;

	i = 0;
	while (i < e->scene->n_plane)
	{
		if (test_hit(ray, &e->scene->planes[i], &z))
		{
			if (z >= 0.000001 && z < RAY_END)
			{
				if (!inter->plane)
				{
					inter->plane = &e->scene->planes[i];
					inter->z_plane = z;
				}
				else
				{
					if (z < inter->z_plane)
					{
						inter->plane = &e->scene->planes[i];
						inter->z_plane = z;
					}
				}
			}
		}
		++i;
	}
}
