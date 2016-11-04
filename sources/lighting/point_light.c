/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 03:42:29 by gromon            #+#    #+#             */
/*   Updated: 2016/11/04 04:00:54 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


    dist = vec_sub(l->pos, *new_start);
	if (vec_mul_to_d(*n, dist) <= 0.00000)
		return ;
	t = sqrtf(vec_mul_to_d(dist, dist));
	if (t <= 0.00000)
		return ;
	e->scene.light_ray.origin = *new_start;
	e->scene.light_ray.dir = (t_vec3){dist.x, dist.y, dist.z};
	vec_normalize(&e->scene.light_ray.dir);
	inter = throw_ray(e, &e->scene.light_ray);