/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_linux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:08:05 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/01/09 17:08:07 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	print_usage(void)
{
	ft_putendl("Usage ./RTv1 [name_of_scene]");
	exit(0);
}

int		fd_return(char *name)
{
	int		fd;

	if ((fd = open(name, O_RDONLY)) < 0)
	{
		ft_putendl("unable to open file");
		exit(1);
	}
	return (fd);
}

void	init_mlx(t_rtv1 *rt)
{
	if (!rt)
		exit(0);
	if (!(rt->mlx.mlx_ptr = mlx_init()))
		exit(0);
	if (!(rt->mlx.win_ptr = mlx_new_window(rt->mlx.mlx_ptr,
		WIN_SIZE, WIN_SIZE, "RTv1")))
		exit(0);
	if (!(rt->mlx.img_ptr = mlx_new_image(rt->mlx.mlx_ptr, WIN_SIZE, WIN_SIZE)))
		exit(0);
	if (!(rt->mlx.data = (int*)mlx_get_data_addr(rt->mlx.img_ptr,
		&rt->mlx.bpp, &rt->mlx.size_l, &rt->mlx.endian)))
		exit(0);
}

int		main(int ac, char *av[])
{
	t_rtv1	*rt;

	if (ac != 2)
		print_usage();
	rt = (t_rtv1*)malloc(sizeof(t_rtv1));
	init_mlx(rt);
	rt->name = av[1];
	init_scene(rt);
	call_make_picture(rt);
	mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win_ptr,
		rt->mlx.img_ptr, 0, 0);
	mlx_hook(rt->mlx.win_ptr, 2, 1L << 0, ft_key_linux, rt);
	mlx_loop(rt->mlx.mlx_ptr);
	return (0);
}
