/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 21:18:48 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/13 21:18:49 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		interval_d(double val, double min, double max)
{
	if (val < min)
		val = min;
	else if (val > max)
		val = max;
	return (val);
}
