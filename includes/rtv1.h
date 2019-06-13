/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <bjones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:39:29 by bjones            #+#    #+#             */
/*   Updated: 2018/03/29 22:45:33 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"

# define W 1000
# define H 1000
# define PI 3.14159265
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_Q 12
# define KEY_E 14
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37
# define KEY_I 34
# define KEY_U 32
# define KEY_O 31
# define KEY_SPACE 49
# define KEY_MINUS 78
# define KEY_PLUS 69

typedef struct	s_scol
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
}				t_scol;

typedef struct	s_col
{
	double r;
	double g;
	double b;
}				t_col;

typedef struct	s_vec
{
	double x;
	double y;
	double z;
}				t_vec;

typedef struct	s_cam
{
	t_vec	pos;
	t_vec	dir;
	t_vec	angle;
	double	depth;
	double	ss;
}				t_cam;

typedef struct	s_sphere
{
	t_vec	pos;
	double	r;
	t_scol	amb;
	t_scol	emi;
	t_scol	dif;
	t_scol	spec;
	t_scol	refl;
	t_scol	refr;
	t_vec	d_tmp;
}				t_sphere;

typedef struct	s_plane
{
	t_vec	pos;
	t_vec	normal;
	t_scol	amb;
	t_scol	emi;
	t_scol	dif;
	t_scol	spec;
	t_scol	refl;
	t_scol	refr;
}				t_plane;

typedef struct	s_cylinder
{
	t_vec	pos;
	t_vec	dir;
	double	r;
	t_scol	amb;
	t_scol	emi;
	t_scol	dif;
	t_scol	spec;
	t_scol	refl;
	t_scol	refr;
}				t_cylinder;

typedef struct	s_cone
{
	t_vec	pos;
	t_vec	dir;
	double	a;
	t_scol	amb;
	t_scol	emi;
	t_scol	dif;
	t_scol	spec;
	t_scol	refl;
	t_scol	refr;
}				t_cone;

typedef struct	s_light
{
	t_vec	pos;
	double	flux;
	t_scol	emi;
	double	swtch;
	struct s_light	*next;
}				t_light;

typedef struct	s_plight
{
	t_vec	pos;
	double	flux;
	t_scol	emi;
	double	swtch;
}				t_plight;

typedef struct	s_dist_light
{
	t_vec	dir;
	double	color;
	double	intensity;
	double	swtch;
}				t_dist_light;

typedef struct	s_obj
{
	int			type;
	t_sphere	sphere;
	t_plane		plane;
	t_cone		cone;
	t_cylinder	cylinder;
	t_plight	light;
	t_scol		color;
}				t_obj;

typedef struct	s_lighting
{
	int		shadows;
	double	l_val;
	double	l_dist;
	double	l_angle;
	t_vec	l_dir;
	t_vec	obj_normal;
	t_vec	hit_pt2;
}				t_lighting;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_cam	cam;
	t_vec	down;
	t_vec	right;
	t_vec	v_cam;
	void	*img;
	char	*img_data;
	int		bits_per_pixel;
	t_obj	obj[50];
	t_light	light[5];
	int		obj_ind;
	int		obj_ind2;
	t_vec	ray_dir;
	double	ray_dir_scalar;
	t_vec	hit_pt;
	int		obj_sel;
	int		brightness;
	t_vec	hit_ptt;
	double	shine;
	t_col	bg_color;
	int		sr;
	t_obj	*objs;
	t_light	*lights;
}				t_env;

int				key_hooks(int keycode, t_env *e);
int				mouse_hooks(int button, int x, int y, t_env *e);
int				exit_hook(t_env *e);

t_vec			*intersect(t_vec ray_pos, t_vec ray_dir, t_env *e);
double			check_sphere(t_sphere sphere, t_vec rp, t_vec rd);
void			redraw(t_env *e);
void			ray_trace(int x, int y, t_env *e);

void			rot(t_vec a, t_vec *v, double r);
double			dot(t_vec v1, t_vec v2);
t_vec			cross(t_vec u, t_vec v);
t_vec			add(t_vec a, t_vec b);
t_vec			sub(t_vec a, t_vec b);
t_vec			scale(double scalar, t_vec vec);
t_vec			norm(t_vec v);
double			dist(t_vec v1, t_vec v2);
double			rad(double degrees);

t_vec			new_vec(double a, double b, double c);
t_sphere		new_sphere(t_vec v, double r, t_scol color);
t_plane			new_plane(t_vec point, t_vec normal, t_scol color);
t_cylinder		new_cylinder(t_vec pos, t_vec dir, double r, t_scol color);
t_cone			new_cone(t_vec pos, t_vec dir, double a, t_scol color);
t_light			new_light(t_vec pos, double intensity, t_scol color);
t_col			new_col(double r, double g, double b);
t_scol			new_scol(uint8_t r, uint8_t g, uint8_t b);

void			add_sphere(t_sphere sphere, t_env *e);
void			add_plane(t_plane plane, t_env *e);
void			add_cylinder(t_cylinder cylinder, t_env *e);
void			add_cone(t_cone cone, t_env *e);
void			add_light(t_light light, t_env *e);

t_vec			find_normal(t_vec hit_pt, t_env *e, t_vec ray_dir);

void			invalid_file(void);
void			read_file(int fd, t_env *e);

void			set_cam(t_vec pos, t_vec dir, t_env *e);

double			lighting(t_vec ray_dir, t_env *e);
int				color_interpolate2(int color1, int color2, double fraction);
int				color_interpolate(int color, double fraction);

#endif
