/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brightness.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 02:28:01 by gromon            #+#    #+#             */
/*   Updated: 2016/11/15 03:00:41 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		get_brightness(t_env *e, t_lambert *lamb)
{
	t_color	tmp_c;
	double	angle;

	angle = acos(vec_mul_to_d(e->scene.light_ray.dir, *lamb->n)
		/ (sqrt(e->scene.light_ray.dir.x * e->scene.light_ray.dir.x
			+ e->scene.light_ray.dir.y * e->scene.light_ray.dir.y
			+ e->scene.light_ray.dir.z * e->scene.light_ray.dir.z
		* sqrt(lamb->n->x * lamb->n->x
			+ lamb->n->y * lamb->n->y
			+ lamb->n->z * lamb->n->z))));
	angle = fabs(rad_to_deg(angle));
	if (angle < e->scene.brightness)
	{
		tmp_c = (t_color){1 - lamb->c->r, 1 - lamb->c->g, 1 - lamb->c->b};
		lamb->c->r += tmp_c.r * (1 - (angle / e->scene.brightness))
			* lamb->l->intensity;
		lamb->c->g += tmp_c.g * (1 - (angle / e->scene.brightness))
			* lamb->l->intensity;
		lamb->c->b += tmp_c.b * (1 - (angle / e->scene.brightness))
			* lamb->l->intensity;
	}
}
