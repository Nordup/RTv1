/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:06:51 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/01/09 17:06:53 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj	new_obj(t_vec3 pnt, t_vec3 dir, double r, int clr)
{
	t_obj	slt;

	slt.pnt = pnt;
	slt.dir = dir;
	slt.r = r;
	slt.clr = clr;
	return (slt);
}

t_obj	circle(t_vec3 ray_pnt, t_vec3 ray_dir, t_obj obj)
{
	t_obj	slt;
	t_vec3	d;
	t_vec3	p_c;
	double	t;

	slt = new_obj(ray_pnt, ft_vec_init(0), 0, obj.clr);
	t = (ft_vec_scpr(obj.pnt, obj.dir) - ft_vec_scpr(ray_pnt, obj.dir))
		/ ft_vec_scpr(ray_dir, obj.dir);
	if (ft_vec_scpr(ray_dir, obj.dir) == 0 || t <= 0.0000000000001)
		return (slt);
	p_c = ft_vec_dif(ft_vec_sum(ft_vec_mul(ray_dir, t), ray_pnt), obj.pnt);
	if (ft_vec_scpr(p_c, p_c) > pow(obj.r, 2))
		return (slt);
	d = (ft_vec_scpr(ray_dir, obj.dir) < ft_vec_scpr(ray_dir,
		ft_vec_inv(obj.dir))) ? obj.dir : ft_vec_inv(obj.dir);
	slt.dir = d;
	slt.pnt = ft_vec_sum(ray_pnt, ft_vec_mul(ray_dir, t));
	return (slt);
}
