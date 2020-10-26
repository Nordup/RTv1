/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_figure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:07:00 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/01/09 17:07:02 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj	closest_obj(t_vec3 pnt, t_vec3 dir, t_rtv1 *rt, int j)
{
	t_obj	slt;
	t_obj	tmp;
	double	s;
	double	t;
	int		i;

	i = 0;
	slt = new_obj(pnt, ft_vec_init(0), 0, 0);
	while (i < rt->num_obj[j])
	{
		tmp = (*rt->func[j])(pnt, dir, rt->obj[j][i]);
		s = ft_vec_scpr(ft_vec_dif(slt.pnt, pnt), ft_vec_dif(slt.pnt, pnt));
		t = ft_vec_scpr(ft_vec_dif(tmp.pnt, pnt), ft_vec_dif(tmp.pnt, pnt));
		if (!ft_vec_is_zero(tmp.dir) && (s == 0 || (s > t && t != 0)))
			slt = tmp;
		i++;
	}
	return (slt);
}

t_obj	closest_figure(t_rtv1 *rt, t_vec3 pnt, t_vec3 dir)
{
	t_obj	slt;
	t_obj	tmp;
	double	s;
	double	t;
	int		i;

	i = 0;
	slt = new_obj(pnt, ft_vec_init(0), 0, 0);
	while (i < 4)
	{
		tmp = closest_obj(pnt, dir, rt, i);
		s = ft_vec_scpr(ft_vec_dif(slt.pnt, pnt), ft_vec_dif(slt.pnt, pnt));
		t = ft_vec_scpr(ft_vec_dif(tmp.pnt, pnt), ft_vec_dif(tmp.pnt, pnt));
		if (!ft_vec_is_zero(tmp.dir) && (s == 0 || (s > t && t != 0)))
			slt = tmp;
		i++;
	}
	return (slt);
}
