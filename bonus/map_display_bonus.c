/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:44:35 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/16 12:13:47 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//initiate the starting screen

void	newimg_xpm(char *path, t_img *img, t_game game)
{
	img->ptr = mlx_xpm_file_to_image(game.win.mlx_ptr, path, &img->w, &img->h);
	if (img->ptr == NULL)
	{
		ft_printf("Error\nImage failed to load.\n");
		clearassets(game);
		exit(1);
	}
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, \
	&img->sline, &img->endian);
	if (img->addr == NULL)
	{
		ft_printf("Error\nImage failed to load.\n");
		clearassets(game);
		exit(1);
	}
}

t_img	*newimg(t_game game)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (img == NULL)
		failedgame(game);
	img->ptr = mlx_new_image(game.win.mlx_ptr, IMG_W, IMG_H);
	if (img->ptr == NULL)
	{
		free(img);
		failedgame(game);
	}
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, \
	&img->sline, &img->endian);
	if (img->addr == NULL)
	{
		mlx_destroy_image(game.win.mlx_ptr, img->ptr);
		free(img);
		failedgame(game);
	}
	return (img);
}

void	initsprites(t_game *game)
{
	newimg_xpm(BG, &game->map.img_bg, *game);
	newimg_xpm(PLAYER, &game->map.img_player, *game);
	newimg_xpm(WALL, &game->map.img_wall, *game);
	newimg_xpm(COLLECT, &game->map.img_collect, *game);
	newimg_xpm(EXIT, &game->map.img_exit, *game);
}

void	initimgs(t_game *game)
{
	size_t	i;
	size_t	j;

	game->gameimg.ptr = mlx_new_image(game->win.mlx_ptr, \
	game->map.rowlength * IMG_W, game->map.rows * IMG_H);
	if (game->gameimg.ptr == NULL)
		failedgame(*game);
	game->gameimg.addr = mlx_get_data_addr(game->gameimg.ptr, \
	&game->gameimg.bpp, &game->gameimg.sline, &game->gameimg.endian);
	if (game->gameimg.ptr == NULL)
		failedgame(*game);
	i = 0;
	j = 0;
	while (i < game->map.rows)
	{
		while (j < game->map.rowlength)
		{
			drawimg(&game->gameimg, game->map, j, i);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, \
	game->gameimg.ptr, 0, 0);
}

void	initgame(t_game *game)
{
	game->gameimg.ptr = NULL;
	game->win.mlx_ptr = NULL;
	game->win.win_ptr = NULL;
	game->win.mlx_ptr = mlx_init();
	if (game->win.mlx_ptr == NULL)
		failedgame(*game);
	game->win.win_ptr = mlx_new_window(game->win.mlx_ptr, \
	IMG_W * game->map.rowlength, IMG_H * game->map.rows + 100, \
	"Shibuya Incident!!");
	if (game->win.win_ptr == NULL)
		failedgame(*game);
	initemptyimg(game);
	initsprites(game);
	initimgs(game);
	initenemy(game);
	movementcount(game->map.movement, game);
}
