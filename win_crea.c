/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_crea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:05:17 by sderet            #+#    #+#             */
/*   Updated: 2018/01/12 19:23:09 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_head.h"
#include "minilibx/mlx.h"

void	*window_creation(t_image *img, t_pos ***tab, t_mmlx *mlx)
{
	int		a;
	int		b;

	a = -1;
	img->maxz = 0;
	while (tab[++a] != 0)
	{
		b = -1;
		while (tab[a][++b] != 0)
			(tab[a][b]->tz > img->maxz ? (img->maxz = tab[a][b]->tz) :
			 (a = -(-a)));
	}
	img->t_len = 20;
//	img->t_len = 2000 / (a + b + 2);
	mlx->win = mlx_new_window(mlx->mlx, 2000, 1300, "FdF");
	mlx->image = mlx_new_image(mlx->mlx, 2000, 1300);
	img->map = mlx_get_data_addr(mlx->image,
			&img->bpp, &img->line_len, &img->endian);
//	mlx->win = mlx_new_window(mlx->mlx, img->maxx, img->maxy, "FdF");
//	mlx->image = mlx_new_image(mlx->mlx, img->maxx, img->maxy);
//	img->map = mlx_get_data_addr(mlx->image,
//			&img->bpp, &img->line_len, &img->endian);
	return (mlx);
}
