/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:14:30 by bjones            #+#    #+#             */
/*   Updated: 2018/01/26 01:57:22 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vec	norm(t_vec v)
{
	double	mag;

	mag = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	v.x = v.x / mag;
	v.y = v.y / mag;
	v.z = v.z / mag;
	return (v);
}

double	rad(double degrees)
{
	return (degrees * (PI / 180));
}

double	dist(t_vec v1, t_vec v2)
{
	return (sqrt(pow(v2.x - v1.x, 2) +
		pow(v2.y - v1.y, 2) + pow(v2.z - v1.z, 2)));
}
