/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <bjones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 01:29:40 by bjones            #+#    #+#             */
/*   Updated: 2018/03/30 15:32:00 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double	max(double x, double y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

double	min(double x, double y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

/*t_color2	norm_color(t_color2 color)
{
	t_color2	new;

	new.r = ((color >> 16) & 0xFF) / 255.0;
	new.g = ((color >> 8) & 0xFF) / 255.0;
	new.b = (color & 0xFF) / 255.0;

	return (new);
}*/

double	sRGB_to_linear(uint8_t s) //float?
{
	double normal_s = s / 255.0;
	if (normal_s <= 0.04045)
		return (normal_s / 12.92);
	else
		return pow(((normal_s + 0.055) / 1.055), 2.4);
}

uint8_t		linear_to_sRGB(double l) //float?
{
	if (l <= 0.0)
		return (0);
	if (l <= 0.0031308)
		return (round(l * 12.92 * 255)); //rounding?
	else
	{
		if (l >= 1.0)
			return (255);
		return (round((1.055 * pow(l, 1 / 2.4) - 0.055) * 255)); //rounding?
	}
}

t_col	scol_to_lcol(t_scol s)
{
	t_col lcol;

	lcol.r = sRGB_to_linear(s.r);
	lcol.g = sRGB_to_linear(s.g);
	lcol.b = sRGB_to_linear(s.b);
	return (lcol);
}

t_scol	lcol_to_scol(t_col l)
{
	t_scol scol;

	scol.r = linear_to_sRGB(l.r);
	scol.g = linear_to_sRGB(l.g);
	scol.b = linear_to_sRGB(l.b);
	return (scol);
}		
		

t_col	vec_to_col(t_vec vec)
{
	t_col col;

	col.r = vec.x;
	col.g = vec.y;
	col.b = vec.z;

	return (col);
}

t_col	norm_color(t_scol color)
{
	t_col	new;

	new.r = color.r / 255.0;
	new.g = color.g / 255.0;
	new.b = color.b / 255.0;

	return (new);
}

t_col	add_col(t_col col1, t_col col2)
{
	t_col new;

	new.r = col1.r + col2.r;
	new.g = col1.g + col2.g;
	new.b = col1.b + col2.b;

	if (new.r > 1)    //no cap?
		new.r = 1;
	if (new.g > 1)
		new.g = 1;
	if (new.b > 1)
		new.b = 1;
	return (new);
}

t_col	scale_col(t_col col, double scale)
{
	t_col new;

	new.r = scale * col.r;
	new.g = scale * col.g;
	new.b = scale * col.b;

	if (new.r > 1)
		new.r = 1;
	if (new.g > 1)
		new.g = 1;
	if (new.b > 1)
		new.b = 1;
	return (new);
}

t_vec	halfway(t_vec l, t_vec v)
{
	return (norm(add(l, v)));
}

int 	scol_to_hex(t_scol color)
{
	return ((color.r << 16) | (color.g << 8) | (color.b));
}

int d_max = 50;
//t_col bg_color;
//bg_color.r = 0.1;
//bg_color.g = 0.1;
//bg_color.b = 0.1;

//intersect could be optimized by exiting after finding an object closer than lightsource,
//instead of going through all objects first.
t_scol	fetch_property(char *str, t_env *e)
{
	if (e->obj[e->obj_ind].type == 1)
	{
		//if (!ft_strcmp(str, "roughness"))
		//	return ()
		if (!ft_strcmp(str, "ambient"))
			return (e->obj[e->obj_ind].sphere.amb);
		else if (!ft_strcmp(str, "emissive"))
			return (e->obj[e->obj_ind].sphere.emi);
		else if (!ft_strcmp(str, "diffuse"))
			return (e->obj[e->obj_ind].sphere.dif);	
		else if (!ft_strcmp(str, "specular"))
			return (e->obj[e->obj_ind].sphere.spec);	
		else if (!ft_strcmp(str, "reflective"))
			return (e->obj[e->obj_ind].sphere.refl);	
		else if (!ft_strcmp(str, "refractive"))
			return (e->obj[e->obj_ind].sphere.refr);
	}
	else if (e->obj[e->obj_ind].type == 2)
	{
	    if (!ft_strcmp(str, "ambient"))
			return (e->obj[e->obj_ind].plane.amb);
		else if (!ft_strcmp(str, "emissive"))
			return (e->obj[e->obj_ind].plane.emi);
		else if (!ft_strcmp(str, "diffuse"))
			return (e->obj[e->obj_ind].plane.dif);	
		else if (!ft_strcmp(str, "specular"))
			return (e->obj[e->obj_ind].plane.spec);	
		else if (!ft_strcmp(str, "reflective"))
			return (e->obj[e->obj_ind].plane.refl);	
		else if (!ft_strcmp(str, "refractive"))
			return (e->obj[e->obj_ind].plane.refr);
	}
	else if (e->obj[e->obj_ind].type == 3)
	{
	    if (!ft_strcmp(str, "ambient"))
			return (e->obj[e->obj_ind].cylinder.amb);
		else if (!ft_strcmp(str, "emissive"))
			return (e->obj[e->obj_ind].cylinder.emi);
		else if (!ft_strcmp(str, "diffuse"))
			return (e->obj[e->obj_ind].cylinder.dif);	
		else if (!ft_strcmp(str, "specular"))
			return (e->obj[e->obj_ind].cylinder.spec);	
		else if (!ft_strcmp(str, "reflective"))
			return (e->obj[e->obj_ind].cylinder.refl);	
		else if (!ft_strcmp(str, "refractive"))
			return (e->obj[e->obj_ind].cylinder.refr);
	}
	else if (e->obj[e->obj_ind].type == 4)
	{
	    if (!ft_strcmp(str, "ambient"))
			return (e->obj[e->obj_ind].cone.amb);
		else if (!ft_strcmp(str, "emissive"))
			return (e->obj[e->obj_ind].cone.emi);
		else if (!ft_strcmp(str, "diffuse"))
			return (e->obj[e->obj_ind].cone.dif);	
		else if (!ft_strcmp(str, "specular"))
			return (e->obj[e->obj_ind].cone.spec);	
		else if (!ft_strcmp(str, "reflective"))
			return (e->obj[e->obj_ind].cone.refl);	
		else if (!ft_strcmp(str, "refractive"))
			return (e->obj[e->obj_ind].cone.refr);
	}
		t_scol xd;
		xd.r = 0;
		xd.g =0;
		xd.b = 0;
		return (xd);
}

t_col	f_schlick_approx(t_vec l_dir, t_vec h_norm, t_env *e)
{
	t_col	s_approx;
	t_col	fres = scol_to_lcol(fetch_property("specular", e));

	s_approx.r = fres.r + (1.0 - fres.r) * pow(1.0 - dot(l_dir, h_norm), 5);
	s_approx.g = fres.g + (1.0 - fres.g) * pow(1.0 - dot(l_dir, h_norm), 5);
	s_approx.b = fres.b + (1.0 - fres.b) * pow(1.0 - dot(l_dir, h_norm), 5);
	
	return (s_approx);
}

double	phong_NDF(t_vec h_norm, t_vec s_norm, t_env *e)
{
	double	roughness = fetch_property("reflective", e).r;
	//if (roughness > 300)
	//	roughness = 100.0;
	t_scol compile = fetch_property("specular", e);
	(void)compile;
	return((roughness + 2.0) / (2.0 * M_PI) * pow(dot(s_norm, h_norm), roughness));
}

double	geometry(t_vec l, t_vec v, t_vec h, t_vec n) // 0 -> infinity (perfectly smooth)
{
	return (min(min(1, 2.0 * dot(n, h) * dot(n, v) / dot(v, h)), 2.0 * dot(n, h) * dot(n, l) / dot(v, h)));
}

int i;

t_col	specular_BRDF(t_vec l, t_vec v, t_vec n, t_env *e)
{
	t_vec 	h = halfway(l, v);
	t_col	spec;
	t_col	fres = f_schlick_approx(l, h, e);

	double	num = geometry(l, v, h, n) * phong_NDF(h, n, e);
	double denom = 4 * dot(n, l) * dot(n, v);
	spec.r = fres.r * num / denom;
	spec.g = fres.g * num / denom;
	spec.b = fres.b * num / denom;

	return (spec);
}



t_col	acc_light_source(t_vec ray_pos, t_vec ray_dir, t_env *e)
{
	t_col c;
	c.r = 0;
	c.g = 0;
	c.b = 0;
	//double c = ambient intensity + own emission;
	//int i = 0;
	t_light	*light;

	light = e->lights;
	//printf("Accumulating light at object index: %d\n", e->obj_ind);
	while (light)
	{
		//direction from object surface point to light source
		t_vec l_dir = norm(sub(light->pos, ray_pos));
		t_vec obj_normal = find_normal(ray_pos, e, ray_dir);
		e->hit_ptt = add(ray_pos, scale(0.001, obj_normal));
		//printf("--Checking shadow ray\n");
		e->sr = 1;
		t_vec intersection = *intersect(e->hit_ptt, l_dir, e);
		if (dist(intersection, e->hit_ptt) > dist(e->hit_ptt, light->pos))
		{
			t_col spec = specular_BRDF(l_dir, scale(-1, ray_dir), obj_normal, e);
			//printf("%f\n", spec.r);
			//t_col diff = scol_to_lcol(fetch_property("diffuse", e));
			//diff.r /= M_PI;
			//diff.g /= M_PI;
			//diff.b /= M_PI;
			t_col cc;
			//cc.r = add_col(spec, diff).r * (scol_to_lcol(light->emi).r * dot(obj_normal, l_dir));
			//cc.g = add_col(spec, diff).g * (scol_to_lcol(light->emi).g * dot(obj_normal, l_dir));
			//cc.b = add_col(spec, diff).b * (scol_to_lcol(light->emi).b * dot(obj_normal, l_dir));

			cc.r = spec.r * (scol_to_lcol(light->emi).r * dot(obj_normal, l_dir)); //too many parens?
			cc.g = spec.g * (scol_to_lcol(light->emi).g * dot(obj_normal, l_dir));
			cc.b = spec.b * (scol_to_lcol(light->emi).b * dot(obj_normal, l_dir));

			t_col diff = scol_to_lcol(fetch_property("diffuse", e));
			diff.r /= M_PI;
			diff.g /= M_PI;
			diff.b /= M_PI;

			diff.r = diff.r * scol_to_lcol(light->emi).r * dot(obj_normal, l_dir);
			diff.g = diff.g * scol_to_lcol(light->emi).g * dot(obj_normal, l_dir);
			diff.b = diff.b * scol_to_lcol(light->emi).b * dot(obj_normal, l_dir);

			cc.r += diff.r;
			cc.g += diff.g;
			cc.b += diff.b;

			//Avoiding back-facing light directions
			if (dot(obj_normal, l_dir) < 0 || dot(obj_normal, scale(-1, ray_dir)) < 0)
			{
				cc.r = 0;
				cc.g = 0;
				cc.b = 0;
			}
			//t_col cc;
			//diffuse intensity
			//cc.r = norm_color(light->emi).r * norm_color(e->obj[e->obj_ind].color).r
			//* max(0, dot(obj_normal, l_dir));
			//cc.g = norm_color(light->emi).g * norm_color(e->obj[e->obj_ind].color).g
			//* max(0, dot(obj_normal, l_dir));
			//cc.b = norm_color(light->emi).b * norm_color(e->obj[e->obj_ind].color).b
			//* max(0, dot(obj_normal, l_dir));

			//specular intensity
			//t_col spec_coeff = norm_color(fetch_property("specular", e));
			//t_vec h = norm(add(l_dir, scale(-1, ray_dir)));
			//double angle = 2 * (dot(obj_normal, h) * dot(obj_normal, h)) - 1;
			//if (angle < 0)
			//{
			//	spec_coeff.r = 0.0;
			//	spec_coeff.g = 0.0;
			//	spec_coeff.b = 0.0;
			//}
			//cc.r += norm_color(light->emi).r * spec_coeff.r * pow(angle, 12.0);
			//cc.g += norm_color(light->emi).g * spec_coeff.g * pow(angle, 12.0);
			//cc.b += norm_color(light->emi).b * spec_coeff.b * pow(angle, 12.0);

			//light distance falloff
			double l_dist = dist(e->hit_ptt, light->pos);
			cc.r *= 20 * light->flux / (l_dist * l_dist);
			cc.g *= 20 *light->flux / (l_dist * l_dist);
			cc.b *= 20 *light->flux / (l_dist * l_dist);

			//clamp to 1
			if (cc.r > 1) //clamp????
				cc.r = 1;
			if (cc.g > 1)
				cc.g = 1;
			if (cc.b > 1)
				cc.b = 1;

			c = add_col(c, cc);
		}
		light = light->next;
		//i++;
	}
	return (c);
}

t_col	trace(t_vec ray_pos, t_vec ray_dir, int d, t_env *e)
{
	//printf("Entering trace function...\nray_pos -- x: %f y: %f z: %f\n", ray_pos.x, ray_pos.y, ray_pos.z);
	//printf("ray_dir -- x: %f y: %f z: %f\n", ray_dir.x, ray_dir.y, ray_dir.z);
	//printf("ray_depth: %d\n", d);
	if (d > d_max)
		return (e->bg_color);
	//printf("Looking for primary ray intersection...\n");
	e->sr = 0;
	t_vec *q = intersect(ray_pos, ray_dir, e);   //q: object surface point
	if (!q)
	{
		//printf("  no intersection found\n");
		return (e->bg_color);
	}
	//printf("  found primary intersection at {%f,%f,%f}\n", q->x, q->y, q->z);
	t_col c = acc_light_source(*q, ray_dir, e); //this function is also based on intersect
	//printf("%d\n", e->obj_ind);

	t_col refl_coeff = scol_to_lcol(fetch_property("reflective", e));
	if (refl_coeff.b > 0)
	{
		t_vec obj_norm = find_normal(*q, e, ray_dir);
		t_vec r_refl = sub(ray_dir , scale(2 * dot(ray_dir, obj_norm), obj_norm) );

		e->hit_ptt = add(*q, scale(0.001, obj_norm));

		//c = add_col(norm_color(refl_coeff), c);
		//c.r = refl_coeff.r * c.r;
		//c.g = refl_coeff.g * c.g;
		//c.b = refl_coeff.b * c.b;

		c = add_col(c, trace(e->hit_ptt, r_refl, d + 1, e));
	}
	/*if (q is refractive (coherently))
	{
		r_rfr = ray towards inverse direction of refraction;
		c += trace(r_rfr pos (q), r_rfr dir, d + 1, e);
	}*/
	return (c);
}

void	ray_trace(int x, int y, t_env *e)
{
	double	m_sx;
	double	m_sy;
	t_vec	ray_dir;
	t_vec	ray_pos;
	int	col;
	//printf("pixel x: %d\n", x);
	//printf("pixel y: %d\n", y);

	m_sx = -1.0 * (e->cam.ss / 2.0) + x / ((W - 1.0) / 2.0);
	m_sy = -1.0 * (e->cam.ss / 2.0) + y / ((H - 1.0) / 2.0);
	ray_dir = add(add(e->v_cam, scale(m_sx, e->right)), scale(m_sy, e->down));
	ray_pos = add(e->cam.pos, ray_dir);
	ray_dir = norm(ray_dir);

	col = scol_to_hex(lcol_to_scol(trace(ray_pos, ray_dir, 0, e)));
	*(unsigned int *)(e->img_data + ((W * y) + x) *
		(e->bits_per_pixel / 8)) = col;
}

/*void	ray_trace(int x, int y, t_env *e)
{
	double	m_sx;
	double	m_sy;
	t_vec	ray_dir;
	t_vec	ray_pos;
	double	col;

	m_sx = -1.0 * (e->cam.ss / 2.0) + x / ((W - 1.0) / 2.0);
	m_sy = -1.0 * (e->cam.ss / 2.0) + y / ((H - 1.0) / 2.0);
	ray_dir = add(add(e->v_cam, scale(m_sx, e->right)), scale(m_sy, e->down));
	ray_pos = add(e->cam.pos, ray_dir);
	ray_dir = norm(ray_dir);
	if ((e->obj_ind = intersect(ray_pos, ray_dir, e)) >= 0)
	{
		e->hit_pt = add(ray_pos, scale(e->ray_dir_scalar, ray_dir));

		//facing ratio shading
		//double product = dot(scale(-1, ray_dir), find_normal(e->hit_pt, e, ray_dir));
		//if (product < 0)
		//	product = 0;
		//col = color_interpolate2(0x000000, e->obj[e->obj_ind].color, product);
		int i = 0;
		t_col sum;
		sum.r = 0;
		sum.g = 0;
		sum.b = 0;
		while (e->light[i].swtch)
		{
		//lambertian shading
		t_vec l_dir = norm(sub(e->light[i].pos, e->hit_pt));
		t_vec obj_normal = find_normal(e->hit_pt, e, ray_dir);
		//double albedo = 0.18;

		t_col cc;
		cc.r = norm_color(e->light[i].color).r * norm_color(e->obj[e->obj_ind].color).r
			* max(0, dot(obj_normal, l_dir));
		cc.g = norm_color(e->light[i].color).g * norm_color(e->obj[e->obj_ind].color).g
			* max(0, dot(obj_normal, l_dir));
		cc.b = norm_color(e->light[i].color).b * norm_color(e->obj[e->obj_ind].color).b
			* max(0, dot(obj_normal, l_dir));
			
		//light distance falloff
		double l_dist = dist(e->hit_pt, e->light[i].pos);
		cc.r *= e->light[i].intensity / l_dist;
		cc.g *= e->light[i].intensity / l_dist;
		cc.b *= e->light[i].intensity / l_dist;
		//clamp to 1
		if (cc.r > 1)
			cc.r = 1;
		if (cc.g > 1)
			cc.g = 1;
		if (cc.b > 1)
			cc.b = 1;

		//shadowing
		e->hit_ptt = add(e->hit_pt, scale(0.001, obj_normal));
		if (intersect(e->hit_ptt, l_dir, e) >= 0)
		{
			if (dist(e->hit_pt, e->light[i].pos) > dist(e->hit_pt, add(e->hit_pt, scale(e->ray_dir_scalar, l_dir))))
			{
				cc.r = 0;
				cc.g = 0;
				cc.b = 0;
			}
		}
		sum = add_col(sum, cc);
		i++;
		}
		col = tcol2_to_hex(sum);
		
		*(unsigned int *)(e->img_data + ((W * y) + x) *
			(e->bits_per_pixel / 8)) = col;
	}
}*/

void	ray_pixel(t_env *e)
{
	double x;
	double y;

	e->v_cam = scale(e->cam.depth, e->cam.dir);
	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			ray_trace(x, y, e);
			x++;
		}
		y++;
	}
}

void	redraw(t_env *e)
{
	int	size_line;
	int	endian;
	i = 0;
	e->img = mlx_new_image(e->mlx, W, H);
	e->img_data = mlx_get_data_addr(e->img,
		&e->bits_per_pixel, &size_line, &endian);
	ray_pixel(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}
