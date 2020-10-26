/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_vec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:08:31 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/01/09 17:08:33 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		next_num(char *line)
{
	int		i;

	i = 0;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
		i++;
	while ((line[i] < 9 || line[i] > 13) && line[i] != ' ' && line[i] != '\0')
		i++;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
		i++;
	return (i);
}

int		ret_i(char *line)
{
	int		i;

	i = 0;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
		i++;
	if (line[i] == '-' || line[i] == '+')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
		i++;
	i++;
	return (i);
}

double	ft_atoi_double(char *line)
{
	double	a;
	int		b;
	int		i;
	int		n;

	n = 0;
	a = ft_atoi(line);
	i = ret_i(line);
	if (line[i - 1] == '.')
	{
		b = ft_atoi(line + i);
		while (line[i + n] >= '0' && line[i + n] <= '9')
			n++;
		if (a >= 0)
			a += (double)b / pow(10, n);
		else
			a -= (double)b / pow(10, n);
	}
	return (a);
}

t_vec3	read_vec(char *line)
{
	t_vec3	ret;
	int		i;

	ret.x = ft_atoi_double(line);
	i = ret_i(line);
	if (line[i - 1] == '.')
		i += ret_i(line + i);
	ret.y = ft_atoi_double(line + i);
	i += ret_i(line + i);
	if (line[i - 1] == '.')
		i += ret_i(line + i);
	ret.z = ft_atoi_double(line + i);
	return (ret);
}
