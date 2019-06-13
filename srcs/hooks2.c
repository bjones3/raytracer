/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 22:10:00 by bjones            #+#    #+#             */
/*   Updated: 2018/01/26 01:56:59 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	rot(t_vec a, t_vec *v, double r)
{
	t_vec t;

	t = *v;
	v->x = t.x * (a.x * a.x * (1 - cos(r)) + cos(r))
		+ t.y * (a.y * a.x * (1 - cos(r)) - a.z * sin(r))
		+ t.z * (a.z * a.x * (1 - cos(r)) + a.y * sin(r));
	v->y = t.x * (a.x * a.y * (1 - cos(r)) + a.z * sin(r))
		+ t.y * (a.y * a.y * (1 - cos(r)) + cos(r))
		+ t.z * (a.z * a.y * (1 - cos(r)) - a.x * sin(r));
	v->z = t.x * (a.x * a.z * (1 - cos(r)) - a.y * sin(r))
		+ t.y * (a.y * a.z * (1 - cos(r)) + a.x * sin(r))
		+ t.z * (a.z * a.z * (1 - cos(r)) + cos(r));
}

int		mouse_hooks(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		ray_trace(x, y, e);
		e->obj_sel = e->obj_ind;
		redraw(e);
	}
	return (0);
}

int		exit_hook(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
	return (0);
}
