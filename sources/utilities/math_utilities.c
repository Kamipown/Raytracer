/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 03:50:41 by gromon            #+#    #+#             */
/*   Updated: 2016/11/14 02:58:40 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool			solve_quadratic(t_equation e, double *t)
{
	t_bool		ret;

	e.delta = (e.b * e.b - (4 * e.a * e.c));
	if (e.delta < 0.0)
		return (FALSE);
	e.z1 = (-e.b + sqrt(e.delta)) / (2.0 * e.a);
	e.z2 = (-e.b - sqrt(e.delta)) / (2.0 * e.a);
	ret = FALSE;
	if (e.z1 > 0.1)
	{
		*t = e.z1;
		ret = TRUE;
	}
	if (e.z2 > 0.1 && (e.z2 < e.z1 || e.z1 <= 0.1))
	{
		*t = e.z2;
		ret = TRUE;
	}
	return (ret);
}

t_color			uint32_to_color(Uint32 color, SDL_Surface *bmp)
{
	t_color		c;
	Uint8		truecolor[3];

	SDL_GetRGB(color, bmp->format, &truecolor[0], &truecolor[1], &truecolor[2]);
	c = (t_color){truecolor[0] / 255.0,
	truecolor[1] / 255.0, truecolor[2] / 255.0};
	return (c);
}

double			calc_dist(t_vec3 *v1, t_vec3 *v2)
{
	return (sqrtf((v1->x - v2->x) * (v1->x - v2->x)
				+ (v1->y - v2->y) * (v1->y - v2->y)
				+ (v1->z - v2->z) * (v1->z - v2->z)));
}

double			deg_to_rad(double deg)
{
	return (deg * M_PI / 180);
}

double			rad_to_deg(double rad)
{
	return (rad * 180 / M_PI);
}
