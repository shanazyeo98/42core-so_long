/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 23:59:56 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/16 12:12:39 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*retrieveimg(t_game *game, int i)
{
	t_img	*img;
	t_list	*node;
	int		index;

	index = 0;
	node = *(game->imgseq);
	img = node->content;
	while (index < i)
	{
		node = node->next;
		img = node->content;
		index++;
	}
	return (img);
}

void	rendermovement(char a, t_game *game)
{
	layerimg(game->map.img_bg, &game->gameimg, game->play_pos_old.x, \
	game->play_pos_old.y);
	if (game->map.maparray[game->play_pos_old.y][game->play_pos_old.x] == 'E')
		layerimg(game->map.img_exit, &game->gameimg, game->play_pos_old.x, \
		game->play_pos_old.y);
	if (game->map.maparray[game->play_pos_old.y][game->play_pos_old.x] == 'C')
		game->map.maparray[game->play_pos_old.y][game->play_pos_old.x] = '0';
	if (a != 'E')
		layerimg(game->map.img_bg, &game->gameimg, game->play_pos_new.x, \
		game->play_pos_new.y);
	layerimg(game->map.img_player, &game->gameimg, game->play_pos_new.x, \
	game->play_pos_new.y);
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, \
	game->gameimg.ptr, 0, 0);
	if (a == 'C')
		game->map.collectible_game++;
}

void	executemovement(char a, t_game *game, int *movement)
{
	(*movement)++;
	ft_printf("movement: %d\n", *movement);
	rendermovement(a, game);
	game->play_pos_old.x = game->play_pos_new.x;
	game->play_pos_old.y = game->play_pos_new.y;
}

/*Right: 65363, Left: 65361, Up: 65362, Down: 65364*/
int	movement(int key, t_game *game)
{
	char		a;
	int			x;
	int			y;
	static int	movement = 0;

	x = 0;
	y = 0;
	if (key == RIGHT && game->play_pos_old.x != game->map.rowlength - 1)
		x++;
	if (key == LEFT && game->play_pos_old.x != 0)
		x--;
	if (key == UP && game->play_pos_old.y != 0)
		y--;
	if (key == DOWN && game->play_pos_old.y != game->map.rows - 1)
		y++;
	game->play_pos_new.x = game->play_pos_old.x + x;
	game->play_pos_new.y = game->play_pos_old.y + y;
	a = game->map.maparray[game->play_pos_new.y][game->play_pos_new.x];
	if (a != '1' && \
	(key == RIGHT || key == LEFT || key == UP || key == DOWN))
		executemovement(a, game, &movement);
	return (0);
}
