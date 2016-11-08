/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brightness.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 02:28:01 by gromon            #+#    #+#             */
/*   Updated: 2016/11/08 02:34:19 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		get_brightness(t_env *e, t_lambert *lamb)
{
	t_vec3	blinndir;
	double	projection;
	double	tmp;
	double	blinn;

	projection = vec_mul_to_d(e->scene.ray.dir, *lamb->n);
	blinnDir = vec_sub(e->scene.light_ray.dir, e->scene.ray.dir);
	tmp = vec_mul_to_d(blinndir, blinndir);
	if (tmp != 0.000000)
	{
		blinn = 1 / sqrtf(tmp) * fmax(0.9 - projection, 0.00000);
		blinn = lamb->coef * powf(blinn, 60);
		lamb->c->r += blinn * 1.0 * 2.0;
		lamb->c->g += blinn * 1.0 * 2.0;
		lamb->c->b += blinn * 1.0 * 2.0;
	}
}
