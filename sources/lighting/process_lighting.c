/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 03:30:26 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/14 03:16:13 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	process_lighting(t_env *e, t_ray *ray, t_intersection *inter, t_pixel *pixel)
{
	double			coef = 2.0;
	double			refl;
	int				level = 0;

	t_vec3			new_start;
	t_vec3			n;
	double			tmp;
	int				i;

	t_light			*current;
	t_vec3			dist;
	double			t;
	t_ray			light_ray;
	t_intersection	*new_inter;

	double			lambert;
	pixel->color.r = inter->obj->color.r;
	pixel->color.g = inter->obj->color.g;
	pixel->color.b = inter->obj->color.b;

	while (coef > 0.000000 && level < 10)
	{
		new_start = vec_add(ray->origin, vec_mul_d(ray->dir, inter->t));
		n = vec_sub(new_start, inter->obj->pos);
		vec_normalize(&n);
		tmp = vec_mul_to_d(n, n);
		if (tmp == 0.00000)
			return ;
		tmp = 1.0 / sqrtf(tmp);
		n = vec_mul_d(n, tmp);

		i = 0;
		while (i < e->scene->n_light)
		{
			current = &e->scene->lights[i];

			dist = vec_sub(current->pos, new_start);
			if (vec_mul_to_d(n, dist) > 0.000000)
			{
				t = sqrtf(vec_mul_to_d(dist, dist));
				if (t > 0.00000)
				{
					light_ray.origin = new_start;
					light_ray.dir = vec_mul_d(dist, (1 / t));
					new_inter = throw_ray(e, &light_ray, 0);
					if (!new_inter->obj)
					{
						//if (pixel->color.r > 0.001)
							//printf("%f ", pixel->color.r);
						lambert = vec_mul_to_d(light_ray.dir, n) * coef;
						// couleur
						pixel->color.r += lambert * current->color.r * inter->obj->color.r;
						pixel->color.g += lambert * current->color.g * inter->obj->color.g;
						pixel->color.b += lambert * current->color.b * inter->obj->color.b;

						double exposure = -0.6;
						pixel->color.r = 1.0 - expf(pixel->color.r * exposure);
						pixel->color.g = 1.0 - expf(pixel->color.g * exposure);
						pixel->color.b = 1.0 - expf(pixel->color.b * exposure);
						//if (pixel->color.r > 0.001)
							//printf("%f\n", pixel->color.r);
					}
				}
			}
			
			++i;
		}

		coef *= inter->obj->refl;
		refl = 2 * vec_mul_to_d(ray->dir, n);
		ray->origin = new_start;
		n.x *= refl;
		n.y *= refl;
		n.z *= refl;
		ray->dir = vec_sub(ray->dir, n);
		
		level++;
	}

	pixel->color.r = (pixel->color.r * 255 > 255) ? 255 : pixel->color.r * 255;
	pixel->color.g = (pixel->color.g * 255 > 255) ? 255 : pixel->color.g * 255;
	pixel->color.b = (pixel->color.b * 255 > 255) ? 255 : pixel->color.b * 255;
}
