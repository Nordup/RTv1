/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:07:49 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/01/09 17:07:50 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_color(t_rtv1 *rt, t_vec3 pnt, t_vec3 dir)
{
	t_obj	slt;
	int		clr;

	slt = closest_figure(rt, pnt, dir);
	if (ft_vec_is_zero(slt.dir))
		return (0);
	clr = calculate_clr(slt, rt);
	return (clr);
}
