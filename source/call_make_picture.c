/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_make_picture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:06:43 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/01/09 17:06:44 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	make_picture(t_rtv1 *rt, t_vec3 n, t_vec3 m)
{
	t_vec3	ray;
	int		x;
	int		y;

	x = -WIN_SIZE / 2;
	y = -WIN_SIZE / 2;
	while (y < WIN_SIZE / 2)
	{
		while (x < WIN_SIZE / 2)
		{
			ray = ft_vec_sum(ft_vec_sum(rt->cam.dir, ft_vec_div(ft_vec_mul(
				ft_vec_mul(m, 4), x), WIN_SIZE)), ft_vec_div(
					ft_vec_mul(ft_vec_mul(n, 4), y), WIN_SIZE));
			rt->mlx.data[(x + WIN_SIZE / 2) + (y + WIN_SIZE / 2) * WIN_SIZE] =
				get_color(rt, rt->cam.pnt, ray);
			x++;
		}
		x = -WIN_SIZE / 2;
		y++;
	}
}

void	call_make_picture(t_rtv1 *rt)
{
	t_vec3	m;
	t_vec3	n;
	double	k;
	double	l;

	k = pow(rt->cam.dir.y, 2) + pow(rt->cam.dir.x, 2);
	l = pow(rt->cam.dir.x, 2) + pow(rt->cam.dir.y, 2) + pow(rt->cam.dir.z, 2);
	m.x = (-1) * rt->cam.dir.y / sqrt(k);
	m.y = rt->cam.dir.x / sqrt(k);
	m.z = 0;
	n.z = (-1) * sqrt(k / l);
	n.x = n.z * ((-1) * rt->cam.dir.z * rt->cam.dir.x) / k;
	n.y = n.z * ((-1) * rt->cam.dir.z * rt->cam.dir.y) / k;
	make_picture(rt, n, m);
}
