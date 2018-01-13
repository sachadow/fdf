/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_head.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:36:53 by sderet            #+#    #+#             */
/*   Updated: 2018/01/13 14:48:50 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEAD_H
# define FDF_HEAD_H

# include "libft/libft.h"
# include "minilibx/mlx.h"

# define ABS(x) ((x) > 0 ? x : -(x))

typedef struct	s_image
{
	char	*map;
	int		line_len;
	int		bpp;
	int		t_len;
	int		endian;
	int		maxx;
	int		maxy;
	int		maxz;
	int		minz;
	int		coz;
}				t_image;

typedef struct	s_mmlx
{
	void *mlx;
	void *win;
	void *image;
}				t_mmlx;

typedef struct	s_pos
{
	int tx;
	int ty;
	int tz;
	int x;
	int y;
	int fac_x;
	int fac_y;
}				t_pos;

void			window_creation(t_image *img, t_pos ***tab, t_mmlx *mlx);

int				get_err(t_pos ***pos);

t_pos			***youpi(char *filename, t_image *img, t_mmlx *mlx);

void			printpos(t_pos ***pos);

void			print_pixel(t_image *image, t_pos *pos, int col);

void			print_line(t_image *image, t_pos pos1, t_pos pos);

#endif
