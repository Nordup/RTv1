/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_clr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:06:35 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/01/09 17:06:37 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	compare(t_vec3 a, double n)
{
	if (a.x > n)
		a.x = n;
	if (a.y > n)
		a.y = n;
	if (a.z > n)
		a.z = n;
	return (a);
}

void	add_if(t_vec3 *k, t_vec3 tmp)
{
	if (tmp.x > 0)
		k->x += tmp.x;
	if (tmp.y > 0)
		k->y += tmp.y;
	if (tmp.z > 0)
		k->z += tmp.z;
}

int		is_shadow(t_vec3 pnt, t_vec3 lgt_pnt, t_rtv1 *rt)
{
	t_obj	slt;
	t_vec3	dir;

	dir = ft_vec_dif(lgt_pnt, pnt);
	slt = closest_figure(rt, pnt, dir);
	if (ft_vec_is_zero(slt.dir))
		return (0);
	else if (ft_vec_scpr(ft_vec_dif(pnt, slt.pnt),
			ft_vec_dif(pnt, slt.pnt)) > ft_vec_scpr(dir, dir))
		return (0);
	return (1);
}

void	for_every_light(t_obj slt, t_obj lgt, t_cal_clr c, t_rtv1 *rt)
{
	t_vec3	n;
	t_vec3	l;
	t_vec3	tmp;
	double	smth;

	if (!is_shadow(slt.pnt, lgt.pnt, rt))
	{
		n = ft_vec_unit(slt.dir);
		l = ft_vec_unit(ft_vec_dif(lgt.pnt, slt.pnt));
		tmp.x = ft_vec_scpr(l, n) * ((double)((lgt.clr >> 16) & 0xff) / 255);
		tmp.y = ft_vec_scpr(l, n) * ((double)((lgt.clr >> 8) & 0xff) / 255);
		tmp.z = ft_vec_scpr(l, n) * ((double)(lgt.clr & 0xff) / 255);
		n = ft_vec_dif(ft_vec_mul(ft_vec_mul(n, ft_vec_scpr(n, l)), 2), l);
		l = ft_vec_dif(rt->cam.pnt, slt.pnt);
		add_if(c.k, tmp);
		if (ft_vec_scpr(n, l) / (ft_vec_mod(l) *
			ft_vec_mod(n)) > 0 && slt.smth > 0)
		{
			smth = pow(ft_vec_scpr(n, l) / (ft_vec_mod(l) *
				ft_vec_mod(n)), slt.smth);
			c.sm_clr->x += ((double)((lgt.clr >> 16) & 0xff) / 255) * smth;
			c.sm_clr->y += ((double)((lgt.clr >> 8) & 0xff) / 255) * smth;
			c.sm_clr->z += ((double)(lgt.clr & 0xff) / 255) * smth;
		}
	}
}

int		calculate_clr(t_obj slt, t_rtv1 *rt)
{
	t_vec3		k;
	t_vec3		sm_clr;
	t_vec3		rgb;
	t_cal_clr	c;
	int			i;

	i = 0;
	k = ft_vec_init(0);
	sm_clr = ft_vec_init(0);
	c.k = &k;
	c.sm_clr = &sm_clr;
	while (i < rt->num_obj[4])
	{
		for_every_light(slt, rt->obj[4][i], c, rt);
		i++;
	}
	k = compare(k, 1);
	rgb.x = ((slt.clr >> 16) & 0xff) * k.x + 255 * sm_clr.x;
	rgb.y = ((slt.clr >> 8) & 0xff) * k.y + 255 * sm_clr.y;
	rgb.z = (slt.clr & 0xff) * k.z + 255 * sm_clr.z;
	rgb = compare(rgb, 255);
	return ((((int)rgb.x & 0xff) << 16) | (((int)rgb.y &
		0xff) << 8) | ((int)rgb.z & 0xff));
}
