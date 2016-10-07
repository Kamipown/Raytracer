/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_planes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 13:35:39 by dcognata          #+#    #+#             */
/*   Updated: 2016/10/07 16:36:33 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

static int	test_hit(t_ray *ray, t_plane *p)
{
	// t_vec3	dist;
	// t_vec3	dist_n;	
	// t_vec3 	n;
	// t_vec3 	dir_n;
	// float	ret;


	// dist_n = vec_mul(&dist, &n);
	// vec_normalize(&p->rot);
	// dist = vec_sub(&p->pos, &ray->origin);
	// n = (t_vec3){p->rot.x, p->rot.y, p->rot.z};
	// dir_n = vec_mul(&ray->dir, &n);
	// ret = vec_div_to_f((&dist_n), (&dir_n));
	// return ((ret > 0) ? 1 : 0);
	float	denom;
	float	t;
	t_vec3	n;
	t_vec3	tmp_p0;
	t_vec3	tmp_l0;
	t_vec3	p0l0;

	// Convertir les degres de p->rot en radians puis normaliser le vecteur = n
	n = (t_vec3)
	{
		p->rot.x * M_PI / 180,
		p->rot.y * M_PI / 180,
		p->rot.z * M_PI / 180,
	};
	vec_normalize(&n);
	denom = vec_mul_to_f(&n, &ray->dir);
	if (denom > 0.000001f)
	{
		tmp_p0 = (t_vec3){p->pos.x, p->pos.y, p->pos.z};
		tmp_l0 = (t_vec3){ray->origin.x, ray->origin.y, ray->origin.z};
		vec_normalize(&tmp_p0);
		vec_normalize(&tmp_l0);
		p0l0 = vec_sub(&tmp_p0, &tmp_l0);
		if (denom < 0.1f)
		{
			printf("denom trop petit : %f\n", denom);
			return (0);
		}
		else
		{
			t = vec_mul_to_f(&p0l0, &n) / denom;
			printf("denom ok : %f\n", denom);
			return (1);
		}
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
