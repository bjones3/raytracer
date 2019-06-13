/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:12:22 by bjones            #+#    #+#             */
/*   Updated: 2018/01/26 01:57:19 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double	dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec	cross(t_vec u, t_vec v)
{
	t_vec new;

	new.x = u.y * v.z - u.z * v.y;
	new.y = u.z * v.x - u.x * v.z;
	new.z = u.x * v.y - u.y * v.x;
	return (new);
}

t_vec	add(t_vec a, t_vec b)
{
	t_vec new;

	new.x = b.x + a.x;
	new.y = b.y + a.y;
	new.z = b.z + a.z;
	return (new);
}

t_vec	sub(t_vec a, t_vec b)
{
	t_vec new;

	new.x = a.x - b.x;
	new.y = a.y - b.y;
	new.z = a.z - b.z;
	return (new);
}

t_vec	scale(double scalar, t_vec vec)
{
	t_vec new;

	new.x = scalar * vec.x;
	new.y = scalar * vec.y;
	new.z = scalar * vec.z;
	return (new);
}
