/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:46:45 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/04/18 19:46:46 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

# include "libft.h"
# include "shapes.h"

# define BUFF_SIZE		32

# define MIN_SCREEN_W	640
# define MIN_SCREEN_H	480
# define SCREEN_W		800
# define SCREEN_H		600
# define MAX_SCREEN_W	2560
# define MAX_SCREEN_H	1440

# define ESCAPE			53

typedef struct		s_scene
{
	t_light			*lights;
	t_sphere		*spheres;
	t_cylinder		*cylinders;
	t_cone			*cones;
	t_plane			*planes;
	int				n_light;
	int				n_sphere;
	int				n_cylinder;
	int				n_cone;
	int				n_plane;
	int				screen_w;
	int				screen_h;
}					t_scene;

typedef struct		s_img
{
	void			*data;
	int				bpp;
	int				size;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_scene			*scene;
}					t_env;

void				init(t_env *e, char *filename);

void				parse_scene(t_scene *s, char *filename);
char				*read_file(char *filename);
char				*read_data(char *data, char *request);
int					read_int_data(char *data, char *request);

void				fill_screen_data(t_scene *scene, char *data);

int					expose_hook(t_env *e);
int					key_hook(int k, t_env *e);

void				draw_image(t_env *e);
void				draw_pixel(char *buf, int x, int y, int color);

void				error(int n, char *mes);

#endif
