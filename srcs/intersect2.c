/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <bjones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 23:41:22 by bjones            #+#    #+#             */
/*   Updated: 2018/03/23 21:29:27 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double	check_sphere(t_sphere sphere, t_vec rp, t_vec rd)
{
	double	dot;
	double	right;
	double	sol1;
	double	sol2;

	dot = rd.x * (rp.x - sphere.pos.x) +
		rd.y * (rp.y - sphere.pos.y) + rd.z * (rp.z - sphere.pos.z);
	right = dot * dot - pow(dist(sphere.pos, rp), 2) + sphere.r * sphere.r;
	if (right < 0)
		return (-1);
	else if (right == 0)
		return (-1 * dot);
	else
	{
		sol1 = -1 * dot + sqrt(right);
		sol2 = -1 * dot - sqrt(right);
		if (sol1 >= 0 && sol1 <= sol2)
			return (sol1);
		if (sol2 >= 0 && sol2 <= sol1)
			return (sol2);
		return (-1);
	}
}
