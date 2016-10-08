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

static void	print_vec3(t_vec3 *v)
{
	printf("%f, %f, %f\n", v->x, v->y, v->z);
}

t_vec3		mul_d_to_vec(double d, t_vec3 *v)
{
	t_vec3 ret;

	ret.x = v->x * d;
	ret.y = v->y * d;
	ret.z = v->z * d;
	return (ret);
}

static int	test_hit(t_ray *ray, t_plane *p)
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
		0.9,
		0.1,
		0
	};
	vec_normalize(&N);
	//print_vec3(&N);


	m = vec_mul_to_d(&N, &ray->dir);

	if (fabs(m) < 0.000001)
		return (0);
	//ft_putchar('a');
	L = vec_sub(&ray->origin, &p->pos);
	d = vec_mul_to_d(&N, &L);
	t = -d / m;
	if (t <= 0)
		return (0);
	tmp = mul_d_to_vec(t, &ray->dir);
	ret = vec_add(&ray->origin, &tmp);
	printf("%f\n", ret.z);
	return (1);

	// version 1

	// t_vec3	tmp_p0;
	// t_vec3	tmp_l0;
	// t_vec3	p0l0;
	// t_vec3	n;
	// double	denom;
	// double	t;
	// double	a;

	// n = (t_vec3)
	// {
	// 	p->rot.x * M_PI / 180,
	// 	p->rot.y * M_PI / 180,
	// 	p->rot.z * M_PI / 180
	// };
	// vec_normalize(&n);
	// denom = vec_mul_to_d(&n, &ray->dir);
	// if (denom > 0.1)
	// {
	// 	tmp_p0 = (t_vec3){p->pos.x, p->pos.y, p->pos.z};
	// 	tmp_l0 = (t_vec3){ray->origin.x, ray->origin.y, ray->origin.z};
	// 	p0l0 = vec_sub(&tmp_p0, &tmp_l0);

	// 	vec_normalize(&p0l0);

	// 	//print_vec3(&tmp_p0); print_vec3(&tmp_l0); print_vec3(&p0l0);
		
	// 	a = vec_mul_to_d(&p0l0, &n);
	// 	//printf("%f\n\n", a);
	// 	t = a / denom;

	// 	if (t >= 0.000001)
	// 	{
	// 		//if (t >= 0)
	// 		return (1);	
	// 	}
		
	// }
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
