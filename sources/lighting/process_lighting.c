/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 03:30:26 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/13 03:30:28 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	process_lighting(t_env *e, t_ray *ray, t_intersection *inter)
{
	t_vec3	start;
	t_vec3	n;
	double	tmp;
	double	coef = 1.0;
	t_color	color = {0.0, 0.0, 0.0};
	int		level = 0;

	start = vec_add(ray->origin, vec_mul_d(ray->dir, inter->t));
	n = vec_sub(start, inter->obj->pos);
	tmp = vec_mul_to_d(n, n);
	if (tmp == 0.00000)
		return ;
	tmp = 1.0 / sqrtf(tmp);
	n = vec_mul_d(n, tmp);

	int		i;
	i = -1;
	while (++i < e->scene->n_light)
	{
		t_light	*current = &e->scene->lights[i];

		t_vec3	dist = vec_sub(current->pos, start);
		if (vec_mul_to_d(n, dist) <= 0.000000)
			continue ;
		double	t = sqrtf(vec_mul_to_d(dist, dist));
		if (t <= 0.00000)
			continue ;
		t_ray	light_ray;
		light_ray.origin = start;
		light_ray.dir = vec_mul_d(dist, (1 / t));
		t_intersection *tmp_inter;
		tmp_inter = throw_ray(e, &light_ray, 0);
		if (!tmp_inter->obj)
		{
			double	lambert = vec_mul_to_d(light_ray.dir, n) * coef;
		}
	}
}
