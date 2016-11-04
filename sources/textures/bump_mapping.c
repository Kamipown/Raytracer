/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 02:33:29 by gromon            #+#    #+#             */
/*   Updated: 2016/10/28 06:03:45 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void        bump_mapping(t_intersection *inter, t_ray *ray, t_vec3 *n)
{
    t_vec3 	pos;
    double  noiseCoefx;
    double  noiseCoefy;
    double  noiseCoefz;

    pos = vec_add(ray->origin, vec_mul_d(ray->dir, inter->t));
    noiseCoefx = noise3((t_vec3){0.05 * pos.x, 0.05 * pos.y, 0.05 * pos.z});
    noiseCoefy = noise3((t_vec3){0.05 * pos.y, 0.05 * pos.z, 0.05 * pos.x});
    noiseCoefz = noise3((t_vec3){0.05 * pos.z, 0.05 * pos.x, 0.05 * pos.y});
    n->x = (1.0f - inter->obj->bump ) * n->x + inter->obj->bump * noiseCoefx;
    n->y = (1.0f - inter->obj->bump ) * n->y + inter->obj->bump * noiseCoefy;
    n->z = (1.0f - inter->obj->bump ) * n->z + inter->obj->bump * noiseCoefz;
    vec_normalize(n);
}
