/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 02:03:09 by gromon            #+#    #+#             */
/*   Updated: 2016/11/07 02:37:13 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERLIN_H
# define PERLIN_H

# define B 0x100
# define BM 0xff
# define PN 0x1000
# define NP 12
# define NM 0xfff
# define EPSILON 0.000001
# define S_CURVE(t) ( t * t * (3. - 2. * t) )
# define LERP(t, a, b) ( a + t * (b - a) )
# define AT3(rx,ry,rz) ( rx * n.q.x + ry * n.q.y + rz * n.q.z )
# define AT3_POINT(rx,ry,rz) ( rx * n->q.x + ry * n->q.y + rz * n->q.z )

typedef struct	s_noise
{
	int			bx0;
	int			bx1;
	int			by0;
	int			by1;
	int			bz0;
	int			bz1;
	int			b00;
	int			b01;
	int			b11;
	int			b10;
	double		rx0;
	double		rx1;
	double		ry0;
	double		ry1;
	double		rz0;
	double		rz1;
	t_vec3		q;
	double		sy;
	double		sz;
	double		a;
	double		b;
	double		c;
	double		d;
	double		t;
	double		u;
	double		v;
}				t_noise;

void			setup_x(t_noise *n, t_vec3 vec);
void			setup_y(t_noise *n, t_vec3 vec);
void			setup_z(t_noise *n, t_vec3 vec);
void			get_a(t_noise *n, int i, t_vec3 g_g3[B + B + 2]);
void			get_c(t_noise *n, t_vec3 g_g3[B + B + 2]);
void			get_d(t_noise *n, t_vec3 g_g3[B + B + 2]);
double			noise3(t_vec3 vec);
void			perlin_noise(t_intersection *inter, t_color *c, t_ray *ray);
void			perlin_lines(t_intersection *inter, t_color *c, t_ray *ray);
void			perlin_marble(t_intersection *inter, t_color *c, t_ray *ray);
void			earth_texture(t_intersection *inter, t_color *c, t_ray *ray,
					t_obj *obj);
void			select_textures(t_intersection *inter, t_color *c, t_env *e,
					t_obj *obj);
void			bump_mapping(t_intersection *inter, t_ray *ray, t_vec3 *n);

#endif
