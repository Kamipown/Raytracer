/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:46:45 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/21 13:50:52 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# include "./sdl2/SDL.h"
# include "libft.h"
# include "structs.h"
# include "prototypes.h"

# define BUFF_SIZE		32

# define MIN_SCREEN_W	640
# define MIN_SCREEN_H	480
# define SCREEN_W		800
# define SCREEN_H		600
# define MAX_SCREEN_W	2560
# define MAX_SCREEN_H	1440

# define ESCAPE			53

# define FOV			30

# define RAY_START		-10000.0f
# define RAY_END		20000.0f

# define FALSE			0
# define TRUE			1

# define SPHERE			0
# define CYLINDER		1
# define CONE			2
# define PLANE			3

#endif
