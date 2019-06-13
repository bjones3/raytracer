/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <bjones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 22:13:45 by bjones            #+#    #+#             */
/*   Updated: 2018/03/28 22:18:52 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_sphere	new_sphere(t_vec v, double r, t_scol color)
{
	t_sphere sphere;

	sphere.pos = v;
	sphere.r = r;
	sphere.dif = color;
	return (sphere);
}

t_plane		new_plane(t_vec point, t_vec normal, t_scol color)
{
	t_plane plane;

	plane.pos = point;
	plane.normal = norm(normal);
	plane.dif = color;
	return (plane);
}

t_cylinder	new_cylinder(t_vec pos, t_vec dir, double r, t_scol color)
{
	t_cylinder cylinder;

	cylinder.pos = pos;
	cylinder.dir = norm(dir);
	cylinder.r = r;
	cylinder.dif = color;
	return (cylinder);
}

t_cone		new_cone(t_vec pos, t_vec dir, double a, t_scol color)
{
	t_cone cone;

	cone.pos = pos;
	cone.dir = norm(dir);
	cone.a = a;
	cone.dif = color;
	return (cone);
}

t_light		new_light(t_vec pos, double intensity, t_scol color)
{
	t_light light;

	light.pos = pos;
	light.flux = intensity;
	light.emi = color;
	return (light);
}
