/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: splace <splace@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:10:10 by opettex-          #+#    #+#             */
/*   Updated: 2016/10/23 18:41:22 by splace           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


// inter->x / vec->x;
// inter->y / vec->y;

t_bool	inter_cones(t_ray *ray, t_obj *c, double *t)
{
	// t_equation 		e;

	if (ray && c && t)
		return (FALSE);

	// return(solve_quadratic(e, t));
}
