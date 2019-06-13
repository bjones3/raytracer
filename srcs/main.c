/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <bjones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:38:27 by bjones            #+#    #+#             */
/*   Updated: 2018/03/28 22:18:27 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	init_data(t_env *e)
{
	int index;

	index = -1;
	while (++index < 50)
		e->obj[index].type = 0;
	index = -1;
	while (++index < 5)
		e->light[index].swtch = 0;
	e->cam.pos.x = 0;
	e->cam.pos.y = 0;
	e->cam.pos.z = -50;
	e->cam.dir.x = 0;
	e->cam.dir.y = 0;
	e->cam.dir.z = 1;
	e->cam.depth = 2;
	e->cam.ss = 2;
	e->down.x = 0;
	e->down.y = 1;
	e->down.z = 0;
	e->right.x = 1;
	e->right.y = 0;
	e->right.z = 0;
	e->obj_sel = -1;
	e->brightness = 5;
	e->shine = 0;
	e->bg_color.r = 0.1;
	e->bg_color.g = 0.1;
	e->bg_color.b = 0.1;
	e->sr = 0;
	e->obj_ind = 0;
}

t_vec	new_vec(double a, double b, double c)
{
	t_vec vec;

	vec.x = a;
	vec.y = b;
	vec.z = c;
	return (vec);
}

t_col	new_col(double r, double g, double b)
{
	t_col col;

	col.r = r;
	col.g = g;
	col.b = b;
	return (col);
}

t_scol	new_scol(uint8_t r, uint8_t g, uint8_t b)
{
	t_scol scol;

	scol.r = r;
	scol.g = g;
	scol.b = b;
	return (scol);
}

void	set_cam(t_vec pos, t_vec dir, t_env *e)
{
	e->cam.pos = pos;
	e->cam.dir = norm(dir);
	e->down = norm(cross(cross(e->cam.dir, e->down), e->cam.dir));
	if (e->cam.dir.x == 0 && e->cam.dir.y == 1 && e->cam.dir.z == 0)
	{
		e->down.x = 0;
		e->down.y = 0;
		e->down.z = -1;
	}
	if (e->cam.dir.x == 0 && e->cam.dir.y == -1 && e->cam.dir.z == 0)
	{
		e->down.x = 0;
		e->down.y = 0;
		e->down.z = 1;
	}
	e->right = norm(cross(e->down, e->cam.dir));
}

int		main(int argc, char **argv)
{
	t_env	e;
	char	*filename;
	int		fd;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, W, H, "rtv1");
	init_data(&e);
	if (argc != 2)
	{
		ft_putendl("usage: ./rtv1 [obj file path]");
		exit(-1);
	}
	filename = argv[1];
	if ((fd = open(filename, O_RDONLY)) <= 0)
		invalid_file();
	read_file(fd, &e);

	//printf("plane\n");
	//printf("  position: {%f,%f,%f}\n", e.obj[0].plane.pos.x, e.obj[0].plane.pos.y, e.obj[0].plane.pos.z);
	//printf("  normal: {%f,%f,%f}\n", e.obj[0].plane.normal.x, e.obj[0].plane.normal.y, e.obj[0].plane.normal.z);
	//printf("  ambient: {%f,%f,%f}\n", e.obj[0].plane.amb.r, e.obj[0].plane.amb.g, e.obj[0].plane.amb.b);
	//printf("  emissive: {%f,%f,%f}\n", e.obj[0].plane.emi.r, e.obj[0].plane.emi.g, e.obj[0].plane.emi.b);
	//printf("  diffuse: {%f,%f,%f}\n", e.obj[0].plane.dif.r, e.obj[0].plane.dif.g, e.obj[0].plane.dif.b);
	redraw(&e);
	mlx_key_hook(e.win, key_hooks, &e);
	mlx_mouse_hook(e.win, mouse_hooks, &e);
	mlx_hook(e.win, 17, 0, exit_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
