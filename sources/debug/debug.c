/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: splace <splace@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 19:51:54 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/23 04:35:27 by splace           ###   ########.fr       */
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

void	debug_print_counts(t_scene *s)
{
	int		i;
	int		c[4];

	c[0] = 0; c[1] = 0; c[2] = 0; c[3] = 0;
	i = 0;
	while (i < s->n_obj)
	{
		if (s->objs[i].type == SPHERE) ++c[0];
		else if (s->objs[i].type == CYLINDER) ++c[1];
		else if (s->objs[i].type == CONE) ++c[2];
		else if (s->objs[i].type == PLANE) ++c[3];
		++i;
	}
	printf("COUNTS\n");
	printf("lights     : %d\n", s->n_light);
	printf("objects    : %d\n", s->n_obj);
	printf("    spheres    : %d\n", c[0]);
	printf("    cylinders  : %d\n", c[1]);
	printf("    cones      : %d\n", c[2]);
	printf("    planes     : %d\n\n", c[3]);
}

void	debug_print_lights(t_scene *s)
{
	int		i;

	printf("LIGHTS\n");
	i = 0;
	while (i < s->n_light)
	{
		printf("light %d    :\n", i);
		printf("    position    : %f, %f, %f\n", s->lights[i].pos.x, s->lights[i].pos.y, s->lights[i].pos.z);
		printf("    color       : %f, %f, %f\n", s->lights[i].color.r, s->lights[i].color.g, s->lights[i].color.b);
		printf("    intensity   : %f\n", s->lights[i].intensity);
		++i;
	}
	printf("\n");
}

void	debug_print_spheres(t_scene *s)
{
	int		i;

	printf("SPHERES\n");
	i = 0;
	while (i < s->n_obj)
	{
		if (s->objs[i].type == SPHERE)
		{
			printf("sphere %d   :\n", i);
			printf("    position    : %f, %f, %f\n", s->objs[i].pos.x, s->objs[i].pos.y, s->objs[i].pos.z);
			printf("    color       : %f, %f, %f\n", s->objs[i].color.r, s->objs[i].color.g, s->objs[i].color.b);
			printf("    reflection  : %f\n", s->objs[i].refl);
		}
		++i;
	}
	printf("\n");
}

void	debug_print_cylinder(t_scene *s)
{
	int		i;

	printf("cylinder\n");
	i = 0;
	while (i < s->n_obj)
	{
		if (s->objs[i].type == CYLINDER)
		{
			printf("sphere %d   :\n", i);
			printf("    position    : %f, %f, %f\n", s->objs[i].pos.x, s->objs[i].pos.y, s->objs[i].pos.z);
			printf("    rotation    : %f, %f, %f\n", s->objs[i].rot.x, s->objs[i].rot.y, s->objs[i].rot.z);
			printf("    color       : %f, %f, %f\n", s->objs[i].color.r, s->objs[i].color.g, s->objs[i].color.b);
			printf("    reflection  : %f\n", s->objs[i].refl);
		}
		++i;
	}
	printf("\n");
}

void	debug_print_planes(t_scene *s)
{
	int		i;

	printf("PLANES\n");
	i = 0;
	while (i < s->n_obj)
	{
		if (s->objs[i].type == PLANE)
		{
			printf("plane %d    :\n", i);
			printf("    position    : %f, %f, %f\n", s->objs[i].pos.x, s->objs[i].pos.y, s->objs[i].pos.z);
			printf("    rotation    : %f, %f, %f\n", s->objs[i].rot.x, s->objs[i].rot.y, s->objs[i].rot.z);
			printf("    color       : %f, %f, %f\n", s->objs[i].color.r, s->objs[i].color.g, s->objs[i].color.b);
			printf("    reflection  : %f\n", s->objs[i].refl);
		}
		++i;
	}
	printf("\n");
}
