/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:55:09 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/09/15 13:55:12 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int n)
{
	int		i;

	i = 1;
	if (n == -2147483648)
		return (10);
	while (ft_abs(n) > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
