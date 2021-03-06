/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:00:38 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/01/09 17:00:40 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

double	ft_vec_mod(t_vec3 v)
{
	return (sqrt(ft_vec_scpr(v, v)));
}
