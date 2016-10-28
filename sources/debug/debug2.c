/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: splace <splace@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 01:13:09 by splace            #+#    #+#             */
/*   Updated: 2016/10/28 01:14:25 by splace           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	debug_print_screen(t_size *size)
{
	printf("SCREEN\n");
	printf("width      : %d\n", size->w);
	printf("height     : %d\n\n", size->h);
}

void	debug_print_camera(t_cam *cam)
{
	printf("CAMERA\n");
	printf("fov        : %d\n", cam->fov);
	printf("focal dist : %f\n", cam->focal_dist);
	printf("position   : %f, %f, %f\n\n", cam->pos.x, cam->pos.y, cam->pos.z);
}
