/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:54:50 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/15 18:33:10 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	layerimg(t_img src, t_img *dst, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	j = 0;
	while (i < IMG_H)
	{
		while (j < IMG_W)
		{
			color = *((unsigned int *)(src.addr + (i * src.sline) + \
			j * src.bpp / 8));
			if (color != (unsigned int) 0xFF000000)
				*((unsigned int *)(dst->addr + ((y + i) * dst->sline) + \
				(x + j) * (dst->bpp / 8))) = color;
			j++;
		}
		j = 0;
		i++;
	}
}

void	drawimg(t_img *img, t_map map, int x, int y)
{
	t_img	src;
	char	a;

	a = map.maparray[y][x];
	layerimg(map.img_bg, img, x * IMG_W, y * IMG_H);
	if (a != '0')
	{
		if (a == 'P')
			src = map.img_player;
		if (a == '1')
			src = map.img_wall;
		if (a == 'C')
			src = map.img_collect;
		if (a == 'E')
			src = map.img_exit;
		layerimg(src, img, x * IMG_W, y * IMG_H);
	}
}
