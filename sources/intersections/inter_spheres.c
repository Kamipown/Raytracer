/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_spheres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 14:42:48 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/05 16:06:12 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

static int	test_hit(t_ray *ray, t_sphere *s, double *z)
{
	// double	a;
	// double	b;
	// double	c;
	// double	d;
	// double	z1;
	// double	z2;
	// int		ret;

	// a = ray->dir.x * ray->dir.x
	// 	+ ray->dir.y * ray->dir.y
	// 	+ ray->dir.z * ray->dir.z;

	// b = ray->dir.x * (ray->origin.x - s->pos.x)
	// 	+ ray->dir.y * (ray->origin.y - s->pos.y)
	// 	+ ray->dir.z * (ray->origin.z - s->pos.z);
	// b *= 2.0;

	// c = (ray->origin.x - s->pos.x) * (ray->origin.x - s->pos.x)
	// 	+ (ray->origin.y - s->pos.y) * (ray->origin.y - s->pos.y)
	// 	+ (ray->origin.z - s->pos.z) * (ray->origin.z - s->pos.z);
	// c -= (s->radius * s->radius);

	// d = (b * b) - (4.0 * a * c);
	
	// if (d < 0.0)
	// 	return (0);

	// z1 = (-b + sqrt(d)) / (2.0 * a);
	// z2 = (-b - sqrt(d)) / (2.0 * a);

	// ret = FALSE;
	// if (z1 > 0.1 && z1 > 0.000001)
	// {
	// 	*z = z1;
	// 	ret = TRUE;
	// }
	// if (z2 > 0.1 && z2 > 0.000001 && z2 < z1)
	// {
	// 	*z = z2;
	// 	ret = TRUE;
	// }
	// return (ret);





	// a = vec_mul_to_d(&ray->dir, &ray->dir);
	// b = (2 * ray->origin.x * ray->dir.x)
	// 	+ (2 * ray->origin.y * ray->dir.y)
	// 	+ (2 * ray->origin.z * ray->dir.z);
	// c = vec_mul_to_d(&ray->origin, &ray->origin) - 1;


	// if (d < 0.0)
	// 	return (0);

	// z1 = (-b - sqrt(d)) / (2 * a);
	// z2 = (-b + sqrt(d)) / (2 * a);

	// ret = FALSE;
	// if (z1 > 0.1 && z1 > 0.000001)
	// {
	// 	*z = z1;
	// 	ret = TRUE;
	// }
	// if (z2 > 0.1 && z2 > 0.000001 && z2 < z1)
	// {
	// 	*z = z2;
	// 	ret = TRUE;
	// }
	// return (ret);





	t_vec3	dist;
	double	b;
	double	d;
	double	z1;
	double	z2;
	t_bool	ret;

	ret = FALSE;
	// printf("Origin: (%f, %f, %f), Position: (%f, %f, %f)\n",
	// 	ray->origin.x, ray->origin.y, ray->origin.z,
	// 	s->pos.x, s->pos.y, s->pos.z);
	dist = vec_sub(&s->pos, &ray->origin);
	//dist = (t_vec3){s->pos.x - ray->origin.x, s->pos.y - ray->origin.y, s->pos.z};
	// printf("dist: %f, %f, %f\n\n", dist.x, dist.y, dist.z);
	//b = vec_mul_to_d(&ray->dir, &dist);
	b = ray->dir.x * dist.x + ray->dir.y * dist.y + ray->dir.z * dist.z;
	//if (b < 10000)
	//	printf("%f ", b);
	d = b * b - vec_mul_to_d(&dist, &dist) + (double)s->radius * (double)s->radius;
	if (d < 0.0)
		return (0);
	z1 = b - sqrtf(d);
	z2 = b + sqrtf(d);
	if (z1 > 0.1)
	{
		//printf("dist: %f, %f, %f\n", dist.x, dist.y, dist.z);
		*z = z1;
		ret = TRUE;
	}
	if (z2 > 0.1 && z2 < z1)
	{
		//printf("dist: %f, %f, %f\n", dist.x, dist.y, dist.z);
		*z = z2;
		ret = TRUE;
	}
	return (ret);
}

void		inter_spheres(t_env *e, t_ray *ray, t_intersection *inter)
{
	int		i;
	double	z;

	i = 0;
	while (i < e->scene->n_sphere)
	{
		if (test_hit(ray, &e->scene->spheres[i], &z))
		{
			//printf("%f\n", z);
			if (z < RAY_END)
			{
				if (!inter->sphere)
				{
					inter->sphere = &e->scene->spheres[i];
					inter->z_sphere = z;
				}
				else
				{
					if (z < inter->z_sphere)
					{
						inter->sphere = &e->scene->spheres[i];
						inter->z_sphere = z;
					}
				}
			}
		}
		++i;
	}
}
