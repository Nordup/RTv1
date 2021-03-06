/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_div.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:59:56 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/01/09 17:00:01 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	ft_vec_div(t_vec3 v1, double x)
{
	t_vec3	sum;

	sum.x = v1.x / x;
	sum.y = v1.y / x;
	sum.z = v1.z / x;
	return (sum);
}
