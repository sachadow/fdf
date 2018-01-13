/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:39:48 by sderet            #+#    #+#             */
/*   Updated: 2018/01/13 15:58:14 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_head.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

char	*genl(char *filename)
{
	int		fd;
	int		err;
	char	*tmp;
	char	*tab;
	char	*line;

	tab = "";
	if (!(fd = open(filename, O_RDONLY)))
		return (NULL);
	while ((err = get_next_line(fd, &line)) > 0)
	{
		tmp = tab;
		tab = ft_strjoin(tab, line);
		(*tmp != 0 ? (free(tmp)) : (tmp = tmp + 1 - 1));
		tmp = tab;
		tab = ft_strjoin(tab, "\n");
		(*tmp != 0 ? (free(tmp)) : (tmp = tmp + 1 - 1));
	}
	if (err != 0)
		return (NULL);
	return (tab);
}

char	***sstrsplit(char *gnltab)
{
	char	***split;
	char	**minisplit;
	int		mal_size;
	int		a;

	mal_size = 0;
	if (!(minisplit = ft_strsplit(gnltab, '\n')))
		return (NULL);
	while (minisplit[mal_size] != 0)
		mal_size++;
	split = (char***)malloc(sizeof(char**) * (mal_size + 1));
	split[mal_size] = 0;
	a = 0;
	while (a < mal_size)
	{
		if (!(split[a] = ft_strsplit(minisplit[a], ' ')))
			return (NULL);
		a++;
	}
	mal_size = -1;
	while (minisplit[++mal_size] != 0)
		free(minisplit[mal_size]);
	free(minisplit[mal_size]);
	return (split);
}

int		pre_postab(char ***split, t_pos ****tab)
{
	int a;
	int b;

	a = -1;
	while (split[++a] != 0)
	{
		b = -1;
		while (split[a][++b] != 0)
			(*tab)[a][b] = (t_pos*)malloc(sizeof(t_pos));
	}
	a = -1;
	while (split[++a] != 0)
	{
		b = -1;
		while (split[a][++b] != 0)
		{
			(*tab)[a][b]->tx = a;
			(*tab)[a][b]->ty = b;
			(*tab)[a][b]->tz = ft_atoi(split[a][b]);
		}
		(*tab)[a][b] = 0;
	}
	(*tab)[a] = 0;
	return (b);
}

t_pos	***postab(char ***split)
{
	int		a;
	int		b;
	t_pos	***tab;

	a = 0;
	while (split[a] != 0)
		a++;
	tab = (t_pos***)malloc(sizeof(t_pos**) * (a + 1));
	tab[a] = 0;
	a = -1;
	while (split[++a] != 0)
	{
		b = -1;
		while (split[a][++b] != 0)
			;
		if (!(tab[a] = (t_pos**)malloc(sizeof(t_pos*) * (b + 1))))
			return (NULL);
		tab[a][b] = 0;
	}
	b = pre_postab(split, &tab);
	return (tab);
}

void	fin_postab(t_pos ****tab, t_image img)
{
	int a;
	int b;
	int y;

	y = 0;
	while ((*tab)[0][y] != 0)
		y++;
	a = 0;
	while ((*tab)[a] != 0)
	{
		b = 0;
		while ((*tab)[a][b] != 0)
		{
//			(*tab)[a][b]->x = ((b + y - a) * img.t_len) + 50;
//			(*tab)[a][b]->y = ((b + a) * (img.t_len - img.t_len / 3)
//				- ((*tab)[a][b]->tz * (img.t_len)))
//				+ (img.t_len * img.maxz);
			(*tab)[a][b]->x = ((b + a) * img.t_len) + 50;
			(*tab)[a][b]->y = ((a - b) * (img.t_len - img.t_len / 3)
				- ((*tab)[a][b]->tz * (img.t_len))) + ((img.t_len -
				img.t_len / 3) * ((img.maxz + y))) - ABS(img.minz - img.maxz);
			b++;
		}
		a++;
	}
}

t_pos	***youpi(char *filename, t_image *img, t_mmlx *mlx)
{
	char	*gnl;
	char	***split;
	t_pos	***tab;
	int		a;
	int		b;

	if ((gnl = genl(filename)) == NULL)
		return (NULL);
	if ((split = sstrsplit(gnl)) == NULL)
		return (NULL);
	if ((tab = postab(split)) == NULL || get_err(tab) != 1)
		return (NULL);
	a = -1;
	window_creation(img, tab, mlx);
	while (split[++a] != 0)
	{
		b = -1;
		while (split[a][++b] != 0)
			free(split[a][b]);
		free(split[a]);
	}
	fin_postab(&tab, *img);
	return (tab);
}
