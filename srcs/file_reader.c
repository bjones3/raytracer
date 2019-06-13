/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <bjones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 01:18:44 by bjones            #+#    #+#             */
/*   Updated: 2018/03/28 22:16:14 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	invalid_file(void)
{
	ft_putendl("error: invalid file");
	exit(-1);
}

void	init_buf(double b[11])
{
	b[0] = 0;
	b[1] = 0;
	b[2] = 0;
	b[3] = 0;
	b[4] = 0;
	b[5] = 0;
	b[6] = 0;
	b[7] = 0;
	b[8] = 0;
	b[9] = 0;
	b[10] = 0;
}

/*void	pull_data(double b[11], char *obj_name, t_env *e)
{
	if (!ft_strcmp(obj_name, "camera"))
		set_cam(new_vec(b[1], b[2], b[3]), new_vec(b[4], b[5], b[6]), e);
	else if (!ft_strcmp(obj_name, "plane"))
		add_plane(new_plane(new_vec(b[1], b[2], b[3]),
			new_vec(b[4], b[5], b[6]), new_scol(b[7], b[8], b[9])), e);
	else if (!ft_strcmp(obj_name, "sphere"))
		add_sphere(new_sphere(new_vec(b[1], b[2], b[3]), b[4], new_scol(b[5], b[6], b[7])), e);
	else if (!ft_strcmp(obj_name, "cylinder"))
		add_cylinder(new_cylinder(new_vec(b[1], b[2], b[3]),
			new_vec(b[4], b[5], b[6]), b[7], new_scol(b[8], b[9], b[10])), e);
	else if (!ft_strcmp(obj_name, "cone"))
		add_cone(new_cone(new_vec(b[1], b[2], b[3]),
			new_vec(b[4], b[5], b[6]), rad(b[7]), new_scol(b[8], b[9], b[10])), e);
	else if (!ft_strcmp(obj_name, "light"))
		add_light(new_light(new_vec(b[1], b[2], b[3]), b[4], new_scol(b[5], b[6], b[7])), e);
	else
		invalid_file();
}*/

char	*find_nb(char *s)
{
	while (!ft_isdigit(*s) && *s != '-' && *s)
		s++;
	return (s);
}

void	camera(int fd, t_env *e)
{
	char *sub_line;
	char **s;

	get_next_line(fd, &sub_line);
	s = ft_strsplit(find_nb(sub_line), ',');
	if (ft_strstr(sub_line, "position"))
		e->cam.pos = new_vec(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
	ft_strdel(&sub_line);
	ft_strarrdel(&s);
	get_next_line(fd, &sub_line);
	s = ft_strsplit(find_nb(sub_line), ',');
	if (ft_strstr(sub_line, "direction"))
		e->cam.dir = new_vec(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
	ft_strdel(&sub_line);
	ft_strarrdel(&s);
}

void	plane(int fd, t_env *e)
{
	char *sub_line;
	int i;
	t_plane plane;
	char **s;

	//plane = malloc(sizeof(t_plane));
	i = 0;
	while (i++ < 8)
	{
		get_next_line(fd, &sub_line);
		s = ft_strsplit(find_nb(sub_line), ',');
		if (ft_strstr(sub_line, "position"))
			plane.pos = new_vec(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "normal"))
			plane.normal = new_vec(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "ambient"))
			plane.amb = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "emissive"))
			plane.emi = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "diffuse"))
			plane.dif = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "specular"))
			plane.spec = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "reflective"))
			plane.refl = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "refractive"))
			plane.refr = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		ft_strdel(&sub_line);
		ft_strarrdel(&s);
	}
	//ft_lstadd(&e->objs, ft_lstnew(plane, sizeof(t_plane)));
	e->obj[e->obj_ind].type = 2;
	e->obj[e->obj_ind].plane = plane;
	e->obj[e->obj_ind].color = plane.dif;
	e->obj_ind++;
}

void	cylinder(int fd, t_env *e)
{
	char *sub_line;
	int i;
	t_cylinder cylinder;
	char **s;

	//cylinder = malloc(sizeof(t_cylinder));
	i = 0;
	while (i++ < 9)
	{
		get_next_line(fd, &sub_line);
		s = ft_strsplit(find_nb(sub_line), ',');
		if (ft_strstr(sub_line, "position"))
			cylinder.pos = new_vec(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "direction"))
			cylinder.dir = new_vec(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "radius"))
			cylinder.r = ft_atof(s[0]);
		else if (ft_strstr(sub_line, "ambient"))
			cylinder.amb = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "emissive"))
			cylinder.emi = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "diffuse"))
			cylinder.dif = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "specular"))
			cylinder.spec = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "reflective"))
			cylinder.refl = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "refractive"))
			cylinder.refr = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		ft_strdel(&sub_line);
		ft_strarrdel(&s);
	}
	//ft_lstadd(&e->objs, ft_lstnew(cylinder, sizeof(t_cylinder)));
	e->obj[e->obj_ind].type = 3;
	e->obj[e->obj_ind].cylinder = cylinder;
	e->obj[e->obj_ind].color = cylinder.dif;
	e->obj_ind++;
}

void	cone(int fd, t_env *e)
{
	char *sub_line;
	int i;
	t_cone cone;
	char **s;

	//cone = malloc(sizeof(t_cone));
	i = 0;
	while (i++ < 9)
	{
		get_next_line(fd, &sub_line);
		s = ft_strsplit(find_nb(sub_line), ',');
		if (ft_strstr(sub_line, "position"))
			cone.pos = new_vec(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "direction"))
			cone.dir = new_vec(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "angle"))
			cone.a = rad(ft_atof(s[0]));
		else if (ft_strstr(sub_line, "ambient"))
			cone.amb = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "emissive"))
			cone.emi = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "diffuse"))
			cone.dif = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "specular"))
			cone.spec = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "reflective"))
			cone.refl = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "refractive"))
			cone.refr = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		ft_strdel(&sub_line);
		ft_strarrdel(&s);
	}
	//ft_lstadd(&e->objs, ft_lstnew(cone, sizeof(t_cone)));
	e->obj[e->obj_ind].type = 4;
	e->obj[e->obj_ind].cone = cone;
	e->obj[e->obj_ind].color = cone.dif;
	e->obj_ind++;
}

void	sphere(int fd, t_env *e)
{
	char *sub_line;
	int i;
	t_sphere sphere;
	char **s;

	//sphere = malloc(sizeof(t_sphere));
	i = 0;
	while (i++ < 8)
	{
		get_next_line(fd, &sub_line);
		s = ft_strsplit(find_nb(sub_line), ',');
		if (ft_strstr(sub_line, "position"))
			sphere.pos = new_vec(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "radius"))
			sphere.r = ft_atof(s[0]);
		else if (ft_strstr(sub_line, "ambient"))
			sphere.amb = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "emissive"))
			sphere.emi = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "diffuse"))
			sphere.dif = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "specular"))
			sphere.spec = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "reflective"))
			sphere.refl = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "refractive"))
			sphere.refr = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		ft_strdel(&sub_line);
		ft_strarrdel(&s);
	}
	//ft_lstadd(&e->objs, ft_lstnew(sphere, sizeof(t_sphere)));
	e->obj[e->obj_ind].type = 1;
	e->obj[e->obj_ind].sphere = sphere;
	e->obj[e->obj_ind].color = sphere.dif;
	e->obj_ind++;
}

void	light(int fd, t_env *e)
{
	char *sub_line;
	int i;
	t_light *light;
	char **s;

	light = malloc(sizeof(t_light));
	i = 0;
	while (i++ < 3)
	{
		get_next_line(fd, &sub_line);
		s = ft_strsplit(find_nb(sub_line), ',');
		if (ft_strstr(sub_line, "position"))
			light->pos = new_vec(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		else if (ft_strstr(sub_line, "flux"))
			light->flux = ft_atof(s[0]);
		else if (ft_strstr(sub_line, "emissive"))
			light->emi = new_scol(ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2]));
		ft_strdel(&sub_line);
		ft_strarrdel(&s);
	}
	light->swtch = 1;
	light->next = e->lights;
	e->lights = light;
	//ft_lstadd(&e->lights, ft_lstnew(light, sizeof(t_light)));
}

void	pull(char *line, int fd, t_env *e)
{
	//char	*sub_line;
	//printf("%d\n", obj_i);
	if (!ft_strcmp(line, "camera"))
		camera(fd, e);
	else if (!ft_strcmp(line, "plane"))
		plane(fd, e);
	else if (!ft_strcmp(line, "cylinder"))
		cylinder(fd, e);
	else if (!ft_strcmp(line, "cone"))
		cone(fd, e);
	else if (!ft_strcmp(line, "sphere"))
		sphere(fd, e);
	else if (!ft_strcmp(line, "light"))
		light(fd, e);
}

void	read_file(int fd, t_env *e)
{
	char	*line;
	//static int	obj_i = 0;
	//double	b[11];
	//char	**s;
	int		ret;

	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			invalid_file();
		//init_buf(b);
		//i = 0;
		//s = ft_strsplit(line, ' ');
		if (!*line /*|| !s[0]*/)
			invalid_file();
		pull(line, fd, e);
		//while (s[++i] && i < 11)
		//	b[i] = ft_atof(s[i]);
		//pull_data(b, s[0], e);
		ft_strdel(&line);
		//ft_strarrdel(&s);
		
	}
	e->obj_ind = 0;
}
