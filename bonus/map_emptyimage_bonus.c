/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_emptyimage_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:32:45 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/15 18:33:07 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initemptyimg(t_game *game)
{
	t_img	empty;
	size_t	x;
	size_t	y;

	empty = game->map.img_empty;
	game->map.img_empty.ptr = mlx_new_image(game->win.mlx_ptr, \
	IMG_W * game->map.rowlength, 100);
	if (game->map.img_empty.ptr == NULL)
		failedgame(*game);
	empty.addr = mlx_get_data_addr(game->map.img_empty.ptr, &empty.bpp, \
	&empty.sline, &empty.endian);
	if (empty.addr == NULL)
		failedgame(*game);
	x = 0;
	y = 0;
	while (y < 100)
	{
		while (x < game->map.rowlength * IMG_W)
		{
			*((unsigned int *) empty.addr + x * empty.bpp / 8 + \
			y * empty.sline) = 0x000000;
			x++;
		}
		y++;
	}
}
