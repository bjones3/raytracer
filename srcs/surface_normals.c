/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_normals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <bjones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:02:06 by bjones            #+#    #+#             */
/*   Updated: 2018/03/23 21:30:52 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vec	cylinder_normal(t_vec hit, t_cylinder c)
{
	double	x;
	t_vec	n;

	x = (c.dir.x * hit.x - c.dir.x * c.pos.x + c.dir.y * hit.y
		- c.dir.y * c.pos.y + c.dir.z * hit.z - c.dir.z * c.pos.z)
		/ (c.dir.x * c.dir.x + c.dir.y * c.dir.y + c.dir.z * c.dir.z);
	n = scale(1.0 / c.r, sub(sub(hit, c.pos), scale(x, c.dir)));
	return (n);
}

t_vec	cone_normal(t_vec hit, t_cone c)
{
	double	x;
	t_vec	n;
	t_vec	hp;

	hp = sub(hit, c.pos);
	x = (hit.x * hp.x - c.pos.x * hp.x + hit.y * hp.y
		- c.pos.y * hp.y + hit.z * hp.z - c.pos.z * hp.z)
		/ (c.dir.x * hp.x + c.dir.y * hp.y + c.dir.z * hp.z);
	n = scale(1.0 / (x * sin(c.a)), sub(sub(hit, c.pos), scale(x, c.dir)));
	if (dot(hp, c.dir) < 0)
		return (scale(-1, n));
	return (n);
}

t_vec	find_normal(t_vec hit_pt, t_env *e, t_vec ray_dir)
{
	t_vec n;

	if (e->obj[e->obj_ind].type == 1)
		n = sub(hit_pt, e->obj[e->obj_ind].sphere.pos);
	if (e->obj[e->obj_ind].type == 2)
	{
		if (dot(ray_dir, e->obj[e->obj_ind].plane.normal) < 0)
			return (e->obj[e->obj_ind].plane.normal);
		else
			return (scale(-1, e->obj[e->obj_ind].plane.normal));
	}
	if (e->obj[e->obj_ind].type == 3)
		n = cylinder_normal(hit_pt, e->obj[e->obj_ind].cylinder);
	if (e->obj[e->obj_ind].type == 4)
		n = cone_normal(hit_pt, e->obj[e->obj_ind].cone);
	n = norm(n);
	return (n);
}
