/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:07:17 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/01/09 17:07:19 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	cylinder_abc(t_vec3 pnt, t_vec3 dir, t_obj cld, t_vec3 mn)
{
	t_vec3	abc;

	abc.x = ft_vec_scpr(ft_vec_dif(dir, ft_vec_mul(cld.dir, mn.x)), ft_vec_dif(
		dir, ft_vec_mul(cld.dir, mn.x)));
	abc.y = 2 * ft_vec_scpr(ft_vec_dif(dir, ft_vec_mul(cld.dir, mn.x)),
		ft_vec_dif(ft_vec_dif(pnt, ft_vec_mul(cld.dir, mn.y)), cld.pnt));
	abc.z = ft_vec_scpr(ft_vec_dif(ft_vec_dif(pnt, ft_vec_mul(cld.dir, mn.y)),
		cld.pnt), ft_vec_dif(ft_vec_dif(pnt, ft_vec_mul(cld.dir, mn.y)),
			cld.pnt)) - pow(cld.r, 2);
	return (abc);
}

t_obj	cylinder(t_vec3 pnt, t_vec3 dir, t_obj cld)
{
	t_obj	slt;
	t_vec3	mn;
	t_vec3	abc;
	t_vec3	dt;

	slt = new_obj(pnt, ft_vec_init(0), 0, cld.clr);
	mn = cone_cylinder_mn(pnt, dir, cld);
	abc = cylinder_abc(pnt, dir, cld, mn);
	dt.z = pow(abc.y, 2) - 4 * abc.x * abc.z;
	if (dt.z < 0)
		return (slt);
	dt = discriminant(abc.x, abc.y, dt.z);
	if (dt.z <= 0.0000000000001)
		return (slt);
	slt.pnt = ft_vec_sum(pnt, ft_vec_mul(dir, dt.z));
	slt.dir = ft_vec_dif(slt.pnt, ft_vec_sum(cld.pnt, ft_vec_mul(cld.dir,
		dt.z * mn.x + mn.y)));
	if (dt.z * mn.x + mn.y > 1)
		slt = circle(pnt, dir, new_obj(ft_vec_sum(cld.pnt, cld.dir), cld.dir,
			cld.r, cld.clr));
	if (dt.z * mn.x + mn.y < 0)
		slt = circle(pnt, dir, new_obj(cld.pnt, cld.dir, cld.r, cld.clr));
	slt.smth = cld.smth;
	return (slt);
}
