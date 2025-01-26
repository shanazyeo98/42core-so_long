/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:26:44 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/17 13:52:42 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initenemy(t_game *game)
{
	size_t	x;
	size_t	y;

	newimg_xpm(ENEMY, &game->map.img_enemy, *game);
	x = 0;
	y = 0;
	srand(time(NULL));
	while (1)
	{
		x = rand() % game->map.rowlength;
		y = rand() % game->map.rows;
		if (x < game->map.rowlength && y < game->map.rows && \
		game->map.maparray[y][x] == '0')
		{
			game->enemy.x = x;
			game->enemy.y = y;
			break ;
		}
	}
	layerimg(game->map.img_enemy, &game->gameimg, x * IMG_W, y * IMG_H);
}

void	enemyidle(t_game *game, int x, int y)
{
	int			frame;
	long int	delay;
	long int	timenow;

	frame = game->a_enemy.currentframe;
	if (frame == ft_lstsize(game->a_enemy.frames) - 1)
		frame = 0;
	else
		frame++;
	if (frame == 0)
		delay = 2;
	else
		delay = 12;
	timenow = gettime();
	if (timenow - game->a_enemy.last_updated > 1000 / delay)
	{
		game->a_enemy.currentframe = frame;
		layerimg(game->map.img_bg, &game->gameimg, x * IMG_W, y * IMG_H);
		if (game->map.maparray[y][x] == 'C')
			layerimg(game->map.img_collect, &game->gameimg, \
			x * IMG_W, y * IMG_H);
		updateframe(&game->a_enemy, x * IMG_W, y * IMG_H, *game);
	}
}

void	layerbg(t_game *game)
{
	layerimg(game->map.img_bg, &game->gameimg, game->enemy.x * IMG_W, \
	game->enemy.y * IMG_H);
	if (game->map.maparray[game->enemy.y][game->enemy.x] == 'C')
		layerimg(game->map.img_collect, &game->gameimg, \
		game->enemy.x * IMG_W, game->enemy.y * IMG_H);
}

void	enemymovanim(t_game *game)
{
	int			frame;
	long int	timenow;
	long int	fps;

	frame = 0;
	while (frame < ft_lstsize(game->a_enemymove.frames))
	{
		timenow = gettime();
		fps = 72;
		if (frame > 4)
			fps = 64;
		if (timenow - game->a_enemymove.last_updated > 1000 / fps)
		{
			game->a_enemymove.currentframe = frame;
			layerbg(game);
			updateframe(&game->a_enemymove, game->enemy.x * IMG_W, \
			game->enemy.y * IMG_H, *game);
			frame++;
		}
	}
	layerbg(game);
}

void	enemymove(t_game *game)
{
	size_t	x;
	size_t	y;

	x = game->enemy.x;
	y = game->enemy.y;
	enemycoords(game, &x, &y);
	if (game->map.maparray[y][x] != '1' && game->map.maparray[y][x] != 'E' \
	&& !(x == game->enemy.x && y == game->enemy.y))
	{
		enemymovanim(game);
		game->enemy.x = x;
		game->enemy.y = y;
		layerimg(game->map.img_enemy, &game->gameimg, \
		game->enemy.x * IMG_W, game->enemy.y * IMG_H);
	}
}
