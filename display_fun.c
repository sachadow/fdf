/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:11:13 by sderet            #+#    #+#             */
/*   Updated: 2018/01/13 14:07:18 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_head.h"

void	print_pixel(t_image *img, t_pos *pos, int col)
{
	int a;

	a = 0;
	while (a < 3)
	{
		img->map[((pos->x * 4) + a) +
			(pos->y * img->line_len)] = (char)col;
		a++;
	}
}

void	init_pos_tmp(t_pos *tmp, t_pos pos1, t_pos pos2)
{
	tmp->x = pos1.x;
	tmp->y = pos1.y;
	tmp->fac_x = (pos1.x - pos2.x > 0 ? -1 : 1);
	tmp->fac_y = (pos1.y - pos2.y > 0 ? -1 : 1);
}

void	print_line(t_image *img, t_pos pos1, t_pos pos2)
{
	t_pos	tmp;
	float	hdiff;
	float	ldiff;
	float	a;
	float	b;

	b = 0;
	init_pos_tmp(&tmp, pos1, pos2);
	hdiff = (float)(ABS(pos1.y - pos2.y));
	ldiff = (float)(ABS(pos1.x - pos2.x));
	if (ldiff == 0 && hdiff == 0)
		return ;
	if (hdiff != 0 && ldiff != 0)
		a = (hdiff > ldiff ? hdiff / ldiff : ldiff / hdiff);
	while ((tmp.x != pos2.x || ldiff == 0) && (tmp.y != pos2.y || hdiff == 0))
	{
		if (a <= b && hdiff != 0 && ldiff != 0)
			(ldiff > hdiff ? (tmp.y += tmp.fac_y) : (tmp.x += tmp.fac_x));
		b = (a <= b ? b - a : b);
		if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < img->maxx &&
				tmp.y < img->maxy)
			print_pixel(img, &tmp, 255);
		(ldiff > hdiff ? (tmp.x += tmp.fac_x) : (tmp.y += tmp.fac_y));
		b++;
	}
}
