/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <bjones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 10:37:13 by bjones            #+#    #+#             */
/*   Updated: 2018/03/23 21:28:23 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	cam_hooks2(int keycode, t_env *e)
{
	if (keycode == KEY_U)
	{
		rot(e->cam.dir, &e->down, -1.0 * PI / 8.0);
		rot(e->cam.dir, &e->right, -1.0 * PI / 8.0);
	}
	if (keycode == KEY_O)
	{
		rot(e->cam.dir, &e->down, 1.0 * PI / 8.0);
		rot(e->cam.dir, &e->right, 1.0 * PI / 8.0);
	}
	if (keycode == KEY_A)
		e->cam.pos = sub(e->cam.pos, scale(3, e->right));
	if (keycode == KEY_D)
		e->cam.pos = add(e->cam.pos, scale(3, e->right));
	if (keycode == KEY_W)
		e->cam.pos = sub(e->cam.pos, scale(3, e->down));
	if (keycode == KEY_S)
		e->cam.pos = add(e->cam.pos, scale(3, e->down));
	if (keycode == KEY_Q)
		e->cam.pos = sub(e->cam.pos, scale(3, e->cam.dir));
	if (keycode == KEY_E)
		e->cam.pos = add(e->cam.pos, scale(3, e->cam.dir));
}

void	cam_hooks(int keycode, t_env *e)
{
	if (keycode == KEY_J)
	{
		rot(e->down, &e->cam.dir, -1.0 * PI / 8.0);
		rot(e->down, &e->right, -1.0 * PI / 8.0);
	}
	if (keycode == KEY_L)
	{
		rot(e->down, &e->cam.dir, 1.0 * PI / 8.0);
		rot(e->down, &e->right, 1.0 * PI / 8.0);
	}
	if (keycode == KEY_I)
	{
		rot(e->right, &e->cam.dir, PI / 8.0);
		rot(e->right, &e->down, PI / 8.0);
	}
	if (keycode == KEY_K)
	{
		rot(e->right, &e->cam.dir, -1.0 * PI / 8.0);
		rot(e->right, &e->down, -1.0 * PI / 8.0);
	}
	cam_hooks2(keycode, e);
}

void	obj_hooks2(int keycode, t_vec *p, t_vec *d, t_env *e)
{
	if (keycode == KEY_J)
		rot(e->down, d, -1.0 * PI / 8.0);
	if (keycode == KEY_L)
		rot(e->down, d, 1.0 * PI / 8.0);
	if (keycode == KEY_I)
		rot(e->right, d, PI / 8.0);
	if (keycode == KEY_K)
		rot(e->right, d, -1.0 * PI / 8.0);
	if (keycode == KEY_U)
		rot(e->cam.dir, d, -1.0 * PI / 8.0);
	if (keycode == KEY_O)
		rot(e->cam.dir, d, 1.0 * PI / 8.0);
	if (keycode == KEY_A)
		*p = sub(*p, scale(3, e->right));
	if (keycode == KEY_D)
		*p = add(*p, scale(3, e->right));
	if (keycode == KEY_W)
		*p = sub(*p, scale(3, e->down));
	if (keycode == KEY_S)
		*p = add(*p, scale(3, e->down));
	if (keycode == KEY_Q)
		*p = sub(*p, scale(3, e->cam.dir));
	if (keycode == KEY_E)
		*p = add(*p, scale(3, e->cam.dir));
}

void	obj_hooks(int keycode, t_env *e)
{
	t_vec *p;
	t_vec *d;

	if (e->obj[e->obj_sel].type == 1)
	{
		p = &e->obj[e->obj_sel].sphere.pos;
		d = &e->obj[e->obj_sel].sphere.d_tmp;
	}
	if (e->obj[e->obj_sel].type == 2)
	{
		p = &e->obj[e->obj_sel].plane.pos;
		d = &e->obj[e->obj_sel].plane.normal;
	}
	if (e->obj[e->obj_sel].type == 3)
	{
		p = &e->obj[e->obj_sel].cylinder.pos;
		d = &e->obj[e->obj_sel].cylinder.dir;
	}
	if (e->obj[e->obj_sel].type == 4)
	{
		p = &e->obj[e->obj_sel].cone.pos;
		d = &e->obj[e->obj_sel].cone.dir;
	}
	obj_hooks2(keycode, p, d, e);
}

int		key_hooks(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (e->obj_sel >= 0)
		obj_hooks(keycode, e);
	else
		cam_hooks(keycode, e);
	if (keycode == 49)
		e->obj_sel = -1;
	if (keycode == KEY_MINUS)
		if (e->brightness > 0)
			e->brightness--;
	if (keycode == KEY_PLUS)
		if (e->brightness < 10)
			e->brightness++;
	redraw(e);
	return (0);
}
