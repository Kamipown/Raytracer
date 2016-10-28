/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_perlin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 03:25:42 by gromon            #+#    #+#             */
/*   Updated: 2016/10/28 03:48:46 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		setup_x(t_noise *n, t_vec3 vec)
{
	n->t = vec.x + PN;
	n->bx0 = ((int)n->t) & BM;
	n->bx1 = (n->bx0 + 1) & BM;
	n->rx0 = n->t - (int)n->t;
	n->rx1 = n->rx0 - 1.;
}

void		setup_y(t_noise *n, t_vec3 vec)
{
	n->t = vec.y + PN;
	n->by0 = ((int)n->t) & BM;
	n->by1 = (n->by0 + 1) & BM;
	n->ry0 = n->t - (int)n->t;
	n->ry1 = n->ry0 - 1.;
}

void		setup_z(t_noise *n, t_vec3 vec)
{
	n->t = vec.z + PN;
	n->bz0 = ((int)n->t) & BM;
	n->bz1 = (n->bz0 + 1) & BM;
	n->rz0 = n->t - (int)n->t;
	n->rz1 = n->rz0 - 1.;
}
