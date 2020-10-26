/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:04:40 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/01/09 17:04:43 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "libvec.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define WIN_SIZE 950

typedef struct	s_cal_clr
{
	t_vec3		*k;
	t_vec3		*sm_clr;
}				t_cal_clr;

typedef struct	s_cam
{
	t_vec3		pnt;
	t_vec3		dir;
}				t_cam;

typedef	struct	s_obj
{
	t_vec3		pnt;
	t_vec3		dir;
	double		r;
	int			clr;
	double		smth;
}				t_obj;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_mlx;

typedef struct	s_rtv1
{
	t_mlx		mlx;
	char		*name;
	t_cam		cam;
	t_obj		*obj[5];
	char		*obj_name[5];
	int			*num_obj;
	t_obj		(*func[4])(t_vec3 point, t_vec3 dir, t_obj obj);
}				t_rtv1;

t_obj			circle(t_vec3 ray_pnt, t_vec3 ray_dir, t_obj obj);
t_obj			cone(t_vec3 pnt, t_vec3 dir, t_obj cne);
t_obj			cylinder(t_vec3 pnt, t_vec3 dir, t_obj cld);
t_obj			plane(t_vec3 pnt, t_vec3 dir, t_obj pln);
t_obj			sphere(t_vec3 pnt, t_vec3 dir, t_obj sph);

int				fd_return(char *name);
int				ft_exit(int key, void *rt);
int				ft_key_macos(int key, void *rt);
int				ft_key_linux(int key, void *rt);

t_vec3			cone_cylinder_mn(t_vec3 pnt, t_vec3 dir, t_obj cne);
t_obj			new_obj(t_vec3 pnt, t_vec3 dir, double r, int clr);
int				calculate_clr(t_obj	slt, t_rtv1 *rt);
t_vec3			discriminant(double	a, double b, double d);
t_obj			closest_figure(t_rtv1 *rt, t_vec3 pnt, t_vec3 dir);
int				get_color(t_rtv1 *rt, t_vec3 pnt, t_vec3 dir);
void			call_make_picture(t_rtv1 *rt);

double			ft_atoi_double(char *line);
int				next_num(char *line);
t_vec3			read_vec(char *line);
void			init_scene(t_rtv1	*rt);

#endif
