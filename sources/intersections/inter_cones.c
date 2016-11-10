/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: splace <splace@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:10:10 by opettex-          #+#    #+#             */
/*   Updated: 2016/10/28 01:03:08 by splace           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			apply_rotations(t_vec3 *dir, t_vec3 *rot)
{
	double	t;

	t = dir->y;
	dir->y = dir->y * cos(deg_to_rad(rot->x)) + dir->z
					* -(sin(deg_to_rad(rot->x)));
	dir->z = t * sin(deg_to_rad(rot->x)) + dir->z
					* cos(deg_to_rad(rot->x));
	t = dir->x;
	dir->x = dir->x * cos(deg_to_rad(rot->y)) + dir->z
					* sin(deg_to_rad(rot->y));
	dir->z = t * -(sin(deg_to_rad(rot->y))) + dir->z
					* cos(deg_to_rad(rot->y));
	t = dir->x;
	dir->x = dir->x * cos(deg_to_rad(rot->z)) + dir->y
					* -(sin(deg_to_rad(rot->z)));
	dir->y = t * sin(deg_to_rad(rot->z)) + dir->y
					* cos(deg_to_rad(rot->z));
}

t_bool	inter_cones(t_ray *ray, t_obj *s, double *t)
{
	t_equation	e;
	double		rayon;
	t_vec3		tmp_dir;

	tmp_dir = (t_vec3){ray->dir.x, ray->dir.y, ray->dir.z};
	apply_rotations(&tmp_dir, &s->rot);
	rayon = sin(DEG_TO_RAD(s->radius)) * sin(DEG_TO_RAD(s->radius));
	e.a = tmp_dir.x * tmp_dir.x
		- (tmp_dir.y * tmp_dir.y) * rayon
		+ tmp_dir.z * tmp_dir.z;
	e.b = tmp_dir.x * (ray->origin.x - s->pos.x)
		- (tmp_dir.y * (ray->origin.y - s->pos.y)) * rayon
		+ tmp_dir.z * (ray->origin.z - s->pos.z);
	e.b *= 2.0;
	e.c = (ray->origin.x - s->pos.x) * (ray->origin.x - s->pos.x)
		- ((ray->origin.y - s->pos.y) * (ray->origin.y - s->pos.y)) * rayon
		+ (ray->origin.z - s->pos.z) * (ray->origin.z - s->pos.z);
	return (solve_quadratic(e, t));
}
