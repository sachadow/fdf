/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_crea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:05:17 by sderet            #+#    #+#             */
/*   Updated: 2018/01/13 15:16:23 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_head.h"
#include "minilibx/mlx.h"

void	window_creation(t_image *img, t_pos ***tab, t_mmlx *mlx)
{
	int		a;
	int		b;

	a = -1;
	img->maxz = 0;
	img->minz = 0;
	while (tab[++a] != 0)
	{
		b = -1;
		while (tab[a][++b] != 0)
		{
			(tab[a][b]->tz > img->maxz ? (img->maxz = tab[a][b]->tz) :
			 (a = -(-a)));
			(tab[a][b]->tz < img->minz ? (img->minz = tab[a][b]->tz) :
			 (a = -(-a)));
		}
	}
	img->t_len = (a > img->maxz || b > img->maxz ? 1000 / (a + b) :
			700 / (a + b));
	img->maxx = img->t_len * (a + b) + 100;
	img->maxy = (img->t_len - (img->t_len / 3)) * ((ABS(img->maxz) +
				ABS(img->minz))+ a + b) + 100;
	img->maxy = (img->maxy > 1500 ? 1500 : img->maxy + 1 - 1);
	mlx->win = mlx_new_window(mlx->mlx, img->maxx, img->maxy, "FdF");
	mlx->image = mlx_new_image(mlx->mlx, img->maxx, img->maxy);
	img->map = mlx_get_data_addr(mlx->image,
			&img->bpp, &img->line_len, &img->endian);
}
