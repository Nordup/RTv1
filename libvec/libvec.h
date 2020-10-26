/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:01:27 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/01/09 17:01:29 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

# include <math.h>

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

t_vec3			ft_vec_sum(t_vec3 v1, t_vec3 v2);
t_vec3			ft_vec_dif(t_vec3 v1, t_vec3 v2);
t_vec3			ft_vec_mul(t_vec3 v1, double x);
t_vec3			ft_vec_div(t_vec3 v1, double x);
double			ft_vec_scpr(t_vec3 v, t_vec3 w);
t_vec3			ft_vec_init(double l);
t_vec3			ft_vec_inv(t_vec3 v1);
int				ft_vec_is_zero(t_vec3	dir);
double			ft_vec_mod(t_vec3 v);
t_vec3			ft_vec_unit(t_vec3 v);

#endif
