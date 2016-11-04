/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 02:33:29 by gromon            #+#    #+#             */
/*   Updated: 2016/11/03 23:25:40 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		bump_mapping(t_intersection *inter, t_ray *ray, t_vec3 *n)
{
	t_vec3	pos;
	double	noisecoefx;
	double	noisecoefy;
	double	noisecoefz;

	pos = vec_add(ray->origin, vec_mul_d(ray->dir, inter->t));
	noisecoefx = noise3((t_vec3){0.05 * pos.x, 0.05 * pos.y, 0.05 * pos.z});
	noisecoefy = noise3((t_vec3){0.05 * pos.y, 0.05 * pos.z, 0.05 * pos.x});
	noisecoefz = noise3((t_vec3){0.05 * pos.z, 0.05 * pos.x, 0.05 * pos.y});
	n->x = (1.0f - inter->obj->bump) * n->x + inter->obj->bump * noisecoefx;
	n->y = (1.0f - inter->obj->bump) * n->y + inter->obj->bump * noisecoefy;
	n->z = (1.0f - inter->obj->bump) * n->z + inter->obj->bump * noisecoefz;
	vec_normalize(n);
}
