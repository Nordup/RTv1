/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:07:56 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/01/09 17:07:58 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_func(t_rtv1 *rt)
{
	rt->func[0] = &cone;
	rt->func[1] = &cylinder;
	rt->func[2] = &plane;
	rt->func[3] = &sphere;
	rt->obj_name[0] = ft_strdup("cne");
	rt->obj_name[1] = ft_strdup("cld");
	rt->obj_name[2] = ft_strdup("pln");
	rt->obj_name[3] = ft_strdup("sph");
	rt->obj_name[4] = ft_strdup("lgt");
}

void	init_cam(char *line, t_rtv1 *rt)
{
	int		i;

	i = 3;
	rt->cam.pnt = read_vec(line + i);
	i += next_num(line + i);
	rt->cam.dir = read_vec(line + i);
}

void	init_obj(char *line, t_rtv1 *rt, int n)
{
	int		i;
	int		num;
	t_obj	*obj;

	i = 3;
	obj = rt->obj[n];
	num = rt->num_obj[n];
	obj[num].pnt = read_vec(line + i);
	i += next_num(line + i);
	obj[num].dir = read_vec(line + i);
	i += next_num(line + i);
	obj[num].r = ft_atoi_double(line + i);
	i += next_num(line + i) + 2;
	obj[num].clr = ft_atoi_base(line + i, 16);
	i += next_num(line + i);
	obj[num].smth = ft_atoi_double(line + i);
	rt->num_obj[n] += 1;
}

void	count(int fd, t_rtv1 *rt)
{
	char	*line;
	int		gnl;
	int		i;

	i = -1;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		while (++i < 5)
			if (ft_strncmp(line, rt->obj_name[i], 3) == 0)
				rt->num_obj[i] += 1;
		i = -1;
		free(line);
	}
	if (gnl == -1)
	{
		ft_putendl("unable to open file");
		exit(0);
	}
	while (++i < 5)
	{
		rt->obj[i] = malloc(sizeof(t_obj) * rt->num_obj[i]);
		rt->num_obj[i] = 0;
	}
	close(fd);
}

void	init_scene(t_rtv1 *rt)
{
	char	*line;
	int		fd;
	int		gnl;
	int		i;

	i = -1;
	rt->num_obj = (int*)malloc(sizeof(int) * 5);
	while (++i < 5)
		rt->num_obj[i] = 0;
	i = -1;
	init_func(rt);
	count(fd_return(rt->name), rt);
	fd = fd_return(rt->name);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		if (ft_strncmp(line, "cam", 3) == 0)
			init_cam(line, rt);
		while (++i < 5)
			if (ft_strncmp(line, rt->obj_name[i], 3) == 0)
				init_obj(line, rt, i);
		i = -1;
		free(line);
	}
	if (gnl == -1)
		exit(0);
}
