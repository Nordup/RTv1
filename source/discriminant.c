/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discriminant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:07:25 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/01/09 17:07:27 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	closest_solution(double t1, double t2)
{
	double	ret;

	ret = -1;
	if (t1 > 0 && t2 > 0)
		ret = (t1 > t2) ? t2 : t1;
	else if (t1 > 0)
		ret = t1;
	else if (t2 > 0)
		ret = t2;
	return (ret);
}

t_vec3	discriminant(double a, double b, double d)
{
	t_vec3	ret;

	ret.x = ((-1) * b + sqrt(d)) / (2 * a);
	ret.y = ((-1) * b - sqrt(d)) / (2 * a);
	ret.z = closest_solution(ret.x, ret.y);
	return (ret);
}
