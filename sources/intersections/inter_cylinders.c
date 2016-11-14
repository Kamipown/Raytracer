/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:57:15 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/13 22:47:48 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// static double		deg_to_rad(double a)
// {
// 	return (a * M_PI / 180);
// }

// // static void			apply_rotations(t_vec3 *dir, t_vec3 *rot)
// // {
// // 	double	t;

// // 	t = dir->y;
// // 	dir->y = dir->y * cos(deg_to_rad(rot->x)) + dir->z
// // 					* -(sin(deg_to_rad(rot->x)));
// // 	dir->z = t * sin(deg_to_rad(rot->x)) + dir->z
// // 					* cos(deg_to_rad(rot->x));
// // 	t = dir->x;
// // 	dir->x = dir->x * cos(deg_to_rad(rot->y)) + dir->z
// // 					* sin(deg_to_rad(rot->y));
// // 	dir->z = t * -(sin(deg_to_rad(rot->y))) + dir->z
// // 					* cos(deg_to_rad(rot->y));
// // 	t = dir->x;
// // 	dir->x = dir->x * cos(deg_to_rad(rot->z)) + dir->y
// // 					* -(sin(deg_to_rad(rot->z)));
// // 	dir->y = t * sin(deg_to_rad(rot->z)) + dir->y
// // 					* cos(deg_to_rad(rot->z));
// // }

// static void				apply_rotations(t_vec3 *v)
// {
// 	double	t;

// 	t = v->y;
// 	v->y = v->y * cos(deg_to_rad(45)) + v->z
// 					* -(sin(deg_to_rad(45)));
// 	v->z = t * sin(deg_to_rad(45)) + v->z
// 					* cos(deg_to_rad(45));
// }

// t_bool			inter_cylinders(t_ray *ray, t_obj *s, double *t)
// {
// 	t_equation	e;
// 	t_bool		def_res;
// 	t_vec3		dist;
// 	t_vec3		tmp;

// 	dist = vec_sub(ray->origin, s->pos);
// 	tmp.x = vec_mul_to_d(ray->dir, s->rot);
// 	tmp.y = vec_mul_to_d(dist, s->rot);
// 	e.a = vec_mul_to_d(ray->dir, ray->dir) - (tmp.x * tmp.x);
// 	e.b = 2 * (vec_mul_to_d(ray->dir, dist) - (tmp.x * tmp.y));
// 	e.c = vec_mul_to_d(dist, dist) - (tmp.y * tmp.y) - (s->radius * s->radius);
// 	def_res = solve_quadratic(e, t);
// 	return (def_res);
// }

t_bool			inter_cylinders(t_ray *ray, t_obj *s, double *t)
{
	t_equation	e;
	t_bool		def_res;
	 t_vec3		tmp_dir;

	tmp_dir = (t_vec3){ray->dir.x, ray->dir.y, ray->dir.z};
	vec_rotate(&tmp_dir, s->rot);
	// apply_rotations(&tmp_dir);
	e.a = (tmp_dir.x * tmp_dir.x) + (tmp_dir.z * tmp_dir.z);
	e.b = (tmp_dir.x * (ray->origin.x - s->pos.x))
		+ (tmp_dir.z * (ray->origin.z - s->pos.z));
	e.b *= 2.0;
	e.c =  (ray->origin.x - s->pos.x)
			* (ray->origin.x - s->pos.x)
			+ (ray->origin.z - s->pos.z)
			* (ray->origin.z - s->pos.z);
	e.c -= (s->radius * s->radius);
	def_res = solve_quadratic(e, t);
	return (def_res);
}
