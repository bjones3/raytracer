/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <bjones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 01:25:15 by bjones            #+#    #+#             */
/*   Updated: 2018/03/28 21:27:37 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		color_interpolate(int color, double fraction)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (fraction < 0)
		fraction = 0;
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	if (fraction > 1)
		fraction = 1;
	r *= fraction;
	g *= fraction;
	b *= fraction;
	return ((r << 16) | (g << 8) | (b));
}

int		color_interpolate2(int color1, int color2, double fraction)
{
	t_scol col1;
	t_scol col2;
	t_scol new;

	col1.r = (color1 >> 16) & 0xFF;
	col1.g = (color1 >> 8) & 0xFF;
	col1.b = color1 & 0xFF;
	col2.r = (color2 >> 16) & 0xFF;
	col2.g = (color2 >> 8) & 0xFF;
	col2.b = color2 & 0xFF;
	new.r = fraction * (col2.r - col1.r) + col1.r;
	new.g = fraction * (col2.g - col1.g) + col1.g;
	new.b = fraction * (col2.b - col1.b) + col1.b;
	return ((new.r << 16) | (new.g << 8) | (new.b));
}

void	shine(t_vec ray_dir, t_vec obj_normal, t_vec light_dir, t_env *e)
{
	double a;
	double axis;

	a = acos(dot(scale(-1, ray_dir), obj_normal))
		- acos(dot(obj_normal, light_dir));
	axis = dot(norm(cross(scale(-1, ray_dir), light_dir)), obj_normal);
	if (a > -0.2 && a < 0.2 && axis >= -0.2 && axis < 0.2
		&& e->obj[e->obj_ind].type != 2)
		e->shine = 1 - 5 * (sqrt(a * a + axis * axis));
	if (e->shine < 0)
		e->shine = 0;
}

void	init_lighting(t_lighting *l, t_env *e)
{
	l->shadows = 0;
	l->l_val = 0;
	e->shine = 0;
}

/*double	lighting(t_vec ray_dir, t_env *e)
{
	t_lighting	l;
	int			i;

	init_lighting(&l, e);
	l.obj_normal = find_normal(e->hit_pt, e, ray_dir);
	i = 0;
	while (e->light[i].swtch)
	{
		l.l_dir = norm(sub(e->light[i].pos, e->hit_pt));
		l.l_angle = dot(l.obj_normal, l.l_dir);
		if (l.l_angle < 0)
			l.l_angle = 0;
		l.l_dist = dist(e->light[i].pos, e->hit_pt);
		e->hit_ptt = add(e->hit_pt, scale(0.001, l.l_dir));
		if (intersect(e->hit_ptt, l.l_dir, e) >= 0)
		{
			l.hit_pt2 = add(e->hit_pt, scale(e->ray_dir_scalar, l.l_dir));
			if (dist(e->hit_pt, e->light[i].pos) > dist(e->hit_pt, l.hit_pt2))
				l.shadows++;
		}
		l.l_val += l.l_angle * (4 * e->brightness / l.l_dist) * 0.8;
		shine(ray_dir, l.obj_normal, l.l_dir, e);
		i++;
	}
	return ((l.l_val - l.shadows * 0.2) / i);
}*/
