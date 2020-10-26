/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:08:24 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/01/09 17:08:26 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj	plane(t_vec3 pnt, t_vec3 dir, t_obj pln)
{
	t_obj	slt;
	double	t;
	t_vec3	d;

	slt = new_obj(pnt, ft_vec_init(0), 0, pln.clr);
	t = (ft_vec_scpr(pln.pnt, pln.dir) - ft_vec_scpr(pnt, pln.dir)) /
		ft_vec_scpr(dir, pln.dir);
	if (ft_vec_scpr(dir, pln.dir) == 0 || t <= 0.0000000000001)
		return (slt);
	d = (ft_vec_scpr(dir, pln.dir) < ft_vec_scpr(dir, ft_vec_inv(pln.dir))) ?
		pln.dir : ft_vec_inv(pln.dir);
	slt.dir = d;
	slt.pnt = ft_vec_sum(pnt, ft_vec_mul(dir, t));
	slt.smth = pln.smth;
	return (slt);
}
