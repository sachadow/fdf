/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:27:51 by sderet            #+#    #+#             */
/*   Updated: 2018/01/12 18:56:23 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf_head.h"
#include <stdlib.h>
#include "libft/libft.h"
#include "minilibx/mlx.h"
#include <string.h>

int		std_err(int err)
{
	if (err == 1)
		ft_putendl("usage :	./fdf <source_file>");
	if (err == 2)
		ft_putendl("Error : source file format may be incorrect.");
	return (1);
}

int		escape_exit(int keycode, void *param)
{
	if (param != 0)
		;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

void	printimg(t_pos ***tab, t_image img)
{
	int a;
	int b;

	a = 0;
	while (tab[a] != 0)
	{
		b = 0;
		while (tab[a][b] != 0)
		{
			if (a > 0)
				print_line(&img, *tab[a - 1][b], *tab[a][b]);
			if (b > 0)
				print_line(&img, *tab[a][b - 1], *tab[a][b]);
			b++;
		}
		a++;
	}
}

int		get_err(t_pos ***pos)
{
	int a;
	int b;
	int bb;

	a = 0;
	while (pos[a] != 0)
	{
		b = 0;
		while (pos[a][b] != 0)
			b++;
		(a == 0 ? (bb = b) : (bb = bb + 1 - 1));
		if (bb != b)
			return (-1);
		a++;
	}
	if (a == 0 || b == 0)
		return (-1);
	return (1);
}

int		main(int argc, char **argv)
{
//	void *mlx;
//	void *win;
//	void *imag;
	t_mmlx	mlx;
//	char *image;
	t_image img;
//	int bpp;
//	int l_s;
//	int endian;
	t_pos ***pos;

	if (argc != 2)
		return (std_err(argc != 2 ? 1 : 2));
	mlx.mlx = mlx_init();
//	win = mlx_new_window(mlx, 900, 900, "tests");
//	imag = mlx_new_image(mlx, 900, 900);
//	image = mlx_get_data_addr(imag, &bpp, &l_s, &endian);
//	img.map = image;
//	img.line_len = l_s;
//	img.bpp = bpp;
//	img.t_len = 10;
//	img.maxx = 900;
//	img.maxy = 900;
	if ((pos = youpi(argv[1], &img, &mlx)) == NULL)
		return (std_err(2));
	if (get_err(pos) != 1)
		return (std_err(2));
	printimg(pos, img);
	free(pos);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image, 0, 0);
	mlx_key_hook(mlx.win, &escape_exit, 0);
	mlx_loop(mlx.mlx);
}
