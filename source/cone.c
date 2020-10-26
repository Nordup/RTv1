/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:07:09 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/01/09 17:07:11 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	cone_abc(t_vec3 pnt, t_vec3 dir, t_obj cne, t_vec3 mn)
{
	t_vec3	abc;

	abc.x = ft_vec_scpr(ft_vec_dif(dir, ft_vec_mul(cne.dir, mn.x)), ft_vec_dif(
		dir, ft_vec_mul(cne.dir, mn.x))) - pow(cne.r * mn.x, 2);
	abc.y = 2 * ft_vec_scpr(ft_vec_dif(dir, ft_vec_mul(cne.dir, mn.x)),
		ft_vec_dif(ft_vec_dif(pnt, ft_vec_mul(cne.dir, mn.y)), cne.pnt)) -
			2 * mn.x * mn.y * pow(cne.r, 2);
	abc.z = ft_vec_scpr(ft_vec_dif(ft_vec_dif(pnt, ft_vec_mul(cne.dir, mn.y)),
		cne.pnt), ft_vec_dif(ft_vec_dif(pnt, ft_vec_mul(cne.dir, mn.y)),
			cne.pnt)) - pow(cne.r * mn.y, 2);
	return (abc);
}

t_vec3	cone_cylinder_mn(t_vec3 pnt, t_vec3 dir, t_obj cne)
{
	t_vec3	mn;

	mn.x = ft_vec_scpr(dir, cne.dir) / ft_vec_scpr(cne.dir, cne.dir);
	mn.y = ft_vec_scpr(ft_vec_dif(pnt, cne.pnt), cne.dir) /
		ft_vec_scpr(cne.dir, cne.dir);
	return (mn);
}

t_obj	cone(t_vec3 pnt, t_vec3 dir, t_obj cne)
{
	t_obj	slt;
	t_vec3	mn;
	t_vec3	abc;
	t_vec3	dt;

	slt = new_obj(pnt, ft_vec_init(0), 0, cne.clr);
	mn = cone_cylinder_mn(pnt, dir, cne);
	abc = cone_abc(pnt, dir, cne, mn);
	dt.z = pow(abc.y, 2) - 4 * abc.x * abc.z;
	if (dt.z < 0)
		return (slt);
	dt = discriminant(abc.x, abc.y, dt.z);
	if (dt.z <= 0.0000000000001 || dt.z * mn.x + mn.y < 0)
		return (slt);
	slt.pnt = ft_vec_sum(pnt, ft_vec_mul(dir, dt.z));
	abc = ft_vec_sum(ft_vec_mul(dir, dt.z), ft_vec_dif(pnt, cne.pnt));
	dt.x = ft_vec_scpr(abc, abc) / ft_vec_scpr(cne.dir, abc);
	slt.dir = ft_vec_dif(slt.pnt, ft_vec_sum(cne.pnt,
		ft_vec_mul(cne.dir, dt.x)));
	if (dt.z * mn.x + mn.y > 1)
		slt = circle(pnt, dir, new_obj(ft_vec_sum(cne.pnt, cne.dir),
			cne.dir, cne.r, cne.clr));
	slt.smth = cne.smth;
	return (slt);
}
