/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_macos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:07:41 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/01/09 17:07:42 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_key_macos(int key, void *rt)
{
	(void)rt;
	if (key == 53)
		exit(0);
	return (0);
}

int		ft_exit(int key, void *rt)
{
	(void)rt;
	(void)key;
	exit(0);
	return (0);
}
