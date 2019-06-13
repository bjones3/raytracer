/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <bjones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 23:27:31 by bjones            #+#    #+#             */
/*   Updated: 2018/03/24 20:00:39 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double	check_plane(t_plane plane, t_vec ray_pos, t_vec ray_dir)
{
	double num;
	double denom;

	num = (plane.pos.x - ray_pos.x) * plane.normal.x
		+ (plane.pos.y - ray_pos.y) * plane.normal.y
		+ (plane.pos.z - ray_pos.z) * plane.normal.z;
	denom = ray_dir.x * plane.normal.x +
		ray_dir.y * plane.normal.y + ray_dir.z * plane.normal.z;
	if (denom == 0)
	{
		if (num == 0)
			return (0);
		else
			return (-1);
	}
	else
	{
		return (num / denom);
	}
}

double	check_cylinder(t_cylinder cy, t_vec rp, t_vec rd)
{
	t_vec	c;
	t_vec	d;
	t_vec	e;
	double	sol1;
	double	sol2;

	d = sub(rd, scale(dot(rd, cy.dir), cy.dir));
	e = sub(sub(rp, cy.pos), scale(dot(sub(rp, cy.pos), cy.dir), cy.dir));
	c.x = dot(d, d);
	c.y = 2 * dot(d, e);
	c.z = dot(e, e) - cy.r * cy.r;
	if (c.x == 0)
	{
		if (c.y == 0)
			return (-1);
		else
			return (-1 * c.z / c.y);
	}
	sol1 = (-1 * c.y + sqrt(c.y * c.y - 4 * c.x * c.z)) / (2 * c.x);
	sol2 = (-1 * c.y - sqrt(c.y * c.y - 4 * c.x * c.z)) / (2 * c.x);
	if (sol1 >= 0 && sol1 <= sol2)
		return (sol1);
	if (sol2 >= 0 && sol2 <= sol1)
		return (sol2);
	return (-1);
}

double	check_cone(t_cone cone, t_vec ray_pos, t_vec ray_dir)
{
	t_vec	c;
	t_vec	s;
	double	sol1;
	double	sol2;

	s = sub(ray_pos, cone.pos);
	c.x = pow(dot(ray_dir, cone.dir), 2) - cos(cone.a) * cos(cone.a);
	c.y = 2 * (dot(ray_dir, cone.dir) * dot(s, cone.dir)
		- dot(ray_dir, s) * pow(cos(cone.a), 2));
	c.z = pow(dot(s, cone.dir), 2) - dot(s, s) * pow(cos(cone.a), 2);
	if (c.x == 0)
	{
		if (c.y == 0)
			return (-1);
		else
			return (-1 * c.z / c.y);
	}
	sol1 = (-1 * c.y + sqrt(c.y * c.y - 4 * c.x * c.z)) / (2 * c.x);
	sol2 = (-1 * c.y - sqrt(c.y * c.y - 4 * c.x * c.z)) / (2 * c.x);
	if (sol1 >= 0 && sol1 <= sol2)
		return (sol1);
	if (sol2 >= 0 && sol2 <= sol1)
		return (sol2);
	return (-1);
}

double	intersect2(t_vec ray_pos, t_vec ray_dir, int i, t_env *e)
{
	if (e->obj[i].type == 1)
		return (check_sphere(e->obj[i].sphere, ray_pos, ray_dir));
	else if (e->obj[i].type == 2)
		return (check_plane(e->obj[i].plane, ray_pos, ray_dir));
	else if (e->obj[i].type == 3)
		return (check_cylinder(e->obj[i].cylinder, ray_pos, ray_dir));
	else if (e->obj[i].type == 4)
		return (check_cone(e->obj[i].cone, ray_pos, ray_dir));
	else
		return (-1);
}

t_vec	*intersect(t_vec ray_pos, t_vec ray_dir, t_env *e)
{
	//int		obj_ind;
	int		i;
	double	scalar;

	e->ray_dir_scalar = -1;
	if (e->sr == 0)
		e->obj_ind = -1;
	i = 0;
	scalar = -1;
	while (i < 11)
	{
		scalar = intersect2(ray_pos, ray_dir, i, e);
		if (scalar >= 0 &&
			(scalar < e->ray_dir_scalar || e->ray_dir_scalar < 0))
		{
			e->ray_dir_scalar = scalar;
			if (e->sr == 0)
				e->obj_ind = i;
		}
		i++;
	}
	if (e->ray_dir_scalar == -1)
	{
		//printf("   no intersection found\n");
		return (NULL);
	}
	t_vec	*hit_pt = malloc(sizeof(t_vec));
	*hit_pt = add(ray_pos, scale(e->ray_dir_scalar, ray_dir));
	//printf("  intersection found. surface object point x: %f y: %f z: %f\n", hit_pt->x, hit_pt->y, hit_pt->z);
	return (hit_pt);
}
