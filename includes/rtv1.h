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
# include <sys/uio.h>
# include <sys/types.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

# include "libft.h"
# include "shapes.h"

# define BUFF_SIZE 32

# define SCREEN_W 800
# define SCREEN_H 600

# define ESCAPE 53

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
int					read_data(char *data, char *request);
int					get_next_line(const int fd, char **line);

int					expose_hook(t_env *e);
int					key_hook(int k, t_env *e);

void				draw_image(t_env *e);
void				draw_pixel(char *buf, int x, int y, int color);

void				error(int n, char *mes);

#endif
