/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 19:40:21 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/03 19:40:22 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	throw_ray(t_env *e, t_ray *ray)
{
	// Le rayon part donc de (z: -1000) a (z: +1000)
	while (ray->pos.z <= RAY_END)
	{
		// Ici on cherche donc une intersection avec un objet de la scene
		// Le plan c'est de faire 4 fonctions de calculs d'intersection, une par type d'objets: sphere, cylindres, cones et plans.
		// Ces fonctions doivent retourner 0 si aucune intersection n'est trouvée, sinon, elle retourne la couleur de l'objet touché.
		
		// Pour ces fonctions, on a besoin de la position du rayon en x y z (ray->pos), et de la scene qui contient les objets (e->scene).
		if (e)
			++ray->pos.z;
	}
}

void		raytrace(t_env *e)
{
	int		x;
	int		y;
	t_ray	*ray;

	ray = init_ray();
	y = 0;
	while (y < e->scene->size.h)
	{
		x = 0;
		while (x < e->scene->size.w)
		{
			// on met a jour le rayon pour chaque pixel de la fenetre.
			// d'abord il vaudra	(x: 0, y: 0, z: -1000)
			// puis					(x: 1, y: 0, z: -1000)
			// puis					(x: 2, y: 0, z: -1000)
			// jusqu'a				(x: 799, y: 599, z: -1000)
			// Pour une fenetre en 800 * 600 par exemple
			update_ray(ray, x, y);

			// Une fois le rayon mis a jour, on lance le rayon pour que le z aille de -1000 (RAY_START) a +1000 (RAY_END)
			throw_ray(e, ray);
			++x;
		}
		++y;
	}
	free(ray);
}
