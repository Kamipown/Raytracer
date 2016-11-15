/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:01:43 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/08 04:11:16 by gromon           ###   ########.fr       */
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

typedef struct		s_equation
{
	double			a;
	double			b;
	double			c;
	double			delta;
	double			z1;
	double			z2;
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
	t_vec3			rot;
	int				fov;
	double			focal_dist;
}					t_cam;

typedef struct		s_light
{
	t_vec3			pos;
	t_color			color;
	int				type;
	t_vec3			dir;
	double			radius;
	double			intensity;
}					t_light;

typedef struct		s_obj
{
	t_vec3			pos;
	t_vec3			rot;
	int				radius;
	t_color			color;
	double			refl;
	double			refr;
	int				type;
	int				id;
	int				textures;
	double			bump;
	SDL_Surface		*bmp;
}					t_obj;

typedef struct		s_intersection
{
	t_obj			*obj;
	double			t;
	int				type;
}					t_intersection;

typedef struct		s_rtc
{
	int				x;
	int				y;
	int				i;
	int				old;
	int				tmp;
	int				pc;
}					t_rtc;

typedef struct		s_lambert
{
	t_obj			*obj;
	t_light			*l;
	t_vec3			*new_start;
	t_vec3			*n;
	t_vec3			dist;
	t_vec3			impact;
	t_color			*c;
	t_intersection	inter;
	double			coef;
	double			t;
	double			lambert;
}					t_lambert;

typedef struct		s_scene
{
	SDL_DisplayMode	mode_win;
	SDL_DisplayMode	mode_fs;
	SDL_DisplayMode	*current_mode;
	t_cam			cam;
	t_light			*lights;
	t_obj			*objs;
	double			exposure;
	int				n_light;
	int				n_obj;
	t_size			size;
	t_ray			ray;
	t_ray			light_ray;
	t_intersection	selected;
	t_color			ambient;
	int				brightness;
	int				effect;
	t_bool			ssaa;
}					t_scene;

typedef struct		s_inputs
{
	t_bool			escape;
	t_bool			key_0;
	t_bool			key_1;
	t_bool			key_2;
	t_bool			key_3;
	t_bool			key_4;
	t_bool			key_5;
	t_bool			key_6;
	t_bool			key_f;
	t_bool			key_e;
	t_bool			key_left;
	t_bool			key_right;
	t_bool			key_up;
	t_bool			key_down;
	t_bool			key_forward;
	t_bool			key_backward;
	t_bool			mouse_left;
	t_bool			key_screenshoot;
	int				mouse_x;
	int				mouse_y;
}					t_inputs;

typedef struct		s_options
{
	t_bool			fullscreen;
	t_bool			quit;
	t_bool			need_redraw;
	t_bool			need_redraw_sub;
	t_bool			mode;
	t_bool			first_loop;
}					t_options;

typedef struct		s_textures
{
	SDL_Surface		*map;
}					t_textures;

typedef struct		s_interface
{
	SDL_Texture		*background;
	SDL_Texture		*checkbox;
}					t_interface;

typedef struct		s_env
{
	SDL_Window		*win;
	SDL_Window		*win_sub;
	SDL_Renderer	*renderer;
	SDL_Renderer	*renderer_sub;
	SDL_Event		event;
	t_scene			scene;
	t_inputs		inputs;
	t_options		options;
	t_textures		textures;
	t_interface		interface;
}					t_env;

#endif
