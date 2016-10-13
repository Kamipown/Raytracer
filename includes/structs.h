/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:01:43 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/12 20:46:22 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef unsigned int	t_bool;

typedef struct		s_vec2
{
	int				x;
	int				y;
}					t_vec2;

typedef struct		s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef struct 		s_equation
{
	double 			a;
	double 			b;
	double 			c;
	double 			delta;
	double 			z1;
	double 			z2;
}					t_equation;

typedef struct		s_pixel
{
	int				x;
	int				y;
	t_color			color;
}					t_pixel;

typedef struct		s_size
{
	int				w;
	int				h;
}					t_size;

typedef struct		s_ray
{
	t_vec3			origin;
	t_vec3			dir;
}					t_ray;

typedef struct		s_cam
{
	t_vec3			pos;
	int				fov;
	double			focal_dist;
}					t_cam;

typedef struct		s_light
{
	t_vec3			pos;
	int				color;
	int				intensity;
}					t_light;

// typedef struct		s_sphere
// {
// 	t_vec3			pos;
// 	int				color;
// 	int				radius;
// }					t_sphere;

// typedef struct		s_cylinder
// {
// 	t_vec3			pos;
// 	t_vec3			rot;
// 	int				radius;
// 	int				color;
// }					t_cylinder;

// typedef struct		s_cone
// {
// 	t_vec3			pos;
// 	t_vec3			rot;
// 	t_vec3 			normal;
// 	int				radius;
// 	int				color;
// }					t_cone;

// typedef struct		s_plane
// {
// 	t_vec3			pos;
// 	t_vec3			normal;
// 	int				width;
// 	int				height;
// 	int				color;
// }					t_plane;

typedef struct		s_obj
{
	t_vec3			pos;
	t_vec3			rot;
	int				radius;
	t_color			color;
	double			refl;
	int				type;
}					t_obj;

typedef struct		s_intersection
{
	t_obj			*obj;
	double			z;
	double			t;
	int				type;
}					t_intersection;

typedef struct		s_scene
{
	t_cam			*cam;
	t_light			*lights;
	t_obj			*objs;
	int				n_light;
	int				n_obj;
	t_size			size;
	t_intersection	*selected;
}					t_scene;

typedef struct		s_inputs
{
	t_bool			escape;
	t_bool			key_1;
	t_bool			key_2;
	t_bool			key_f;
	t_bool			key_left;
	t_bool			key_right;
	t_bool			key_up;
	t_bool			key_down;
	t_bool			key_forward;
	t_bool			key_backward;
	t_bool			mouse_left;
	int				mouse_x;
	int				mouse_y;
}					t_inputs;

typedef struct		s_options
{
	t_bool			fullscreen;
	t_bool			quit;
	t_bool			need_redraw;
	t_bool			mode;
}					t_options;

typedef struct		s_env
{
	t_scene			*scene;
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	t_inputs		inputs;
	t_options		options;
}					t_env;

#endif
