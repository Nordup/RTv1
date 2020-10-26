/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:08:38 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/01/09 17:08:41 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj	sphere(t_vec3 pnt, t_vec3 dir, t_obj sph)
{
	t_obj	slt;
	t_vec3	abc;
	t_vec3	dt;
	t_vec3	p0_c;

	slt = new_obj(pnt, ft_vec_init(0), 0, sph.clr);
	p0_c = ft_vec_dif(pnt, sph.pnt);
	abc.x = ft_vec_scpr(dir, dir);
	abc.y = 2 * ft_vec_scpr(dir, p0_c);
	abc.z = ft_vec_scpr(p0_c, p0_c) - pow(sph.r, 2);
	dt.z = pow(abc.y, 2) - 4 * abc.x * abc.z;
	if (dt.z < 0)
		return (slt);
	dt = discriminant(abc.x, abc.y, dt.z);
	if (dt.z <= 0.0000000000001)
		return (slt);
	slt.pnt = ft_vec_sum(pnt, ft_vec_mul(dir, dt.z));
	slt.dir = ft_vec_dif(slt.pnt, sph.pnt);
	slt.smth = sph.smth;
	return (slt);
}
