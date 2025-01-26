/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 23:59:56 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/15 18:33:28 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//down

void	layerbackground(t_game *game, t_img img_n, t_img img_o)
{
	layerimg(game->map.img_bg, &game->gameimg, game->p_old.x * IMG_W, \
	game->p_old.y * IMG_H);
	layerimg(img_o, &game->gameimg, game->p_old.x * IMG_W, \
	game->p_old.y * IMG_H);
	layerimg(game->map.img_bg, &game->gameimg, game->p_new.x * IMG_W, \
	game->p_new.y * IMG_H);
	layerimg(img_n, &game->gameimg, game->p_new.x * IMG_W, \
	game->p_new.y * IMG_H);
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, \
	game->gameimg.ptr, 0, 0);
}

void	updatecollectible(t_game *game)
{
	if (game->map.maparray[game->p_old.y][game->p_old.x] == 'C')
		game->map.maparray[game->p_old.y][game->p_old.x] = '0';
}

void	movementcount(int movement, t_game *game)
{
	char	*mov;
	char	*str;

	mov = ft_itoa(movement);
	str = ft_strjoin("Movement: ", mov);
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, \
	game->map.img_empty.ptr, 0, IMG_H * game->map.rows);
	mlx_string_put(game->win.mlx_ptr, game->win.win_ptr, \
	IMG_W * game->map.rowlength / 2, IMG_H * game->map.rows + 50, \
	0xFFFFFF, str);
	free(mov);
	free(str);
}

void	executemovement(char a, t_game *game, int key)
{
	t_img	img_n;
	t_img	img_o;

	game->map.movement++;
	movementcount(game->map.movement, game);
	img_n = game->map.img_bg;
	if (a == 'C')
		img_n = game->map.img_collect;
	if (a == 'E')
		img_n = game->map.img_exit;
	img_o = game->map.img_bg;
	if (game->map.maparray[game->p_old.y][game->p_old.x] == 'E')
		img_o = game->map.img_exit;
	if (key == RIGHT)
		renderright(a, game, img_n, img_o);
	if (key == LEFT)
		renderleft(a, game, img_n, img_o);
	if (key == UP)
		renderup(a, game, img_n, img_o);
	if (key == DOWN)
		renderdown(a, game, img_n, img_o);
	game->p_old.x = game->p_new.x;
	game->p_old.y = game->p_new.y;
}

/*Right: 65363, Left: 65361, Up: 65362, Down: 65364*/
int	movement(int key, t_game *game)
{
	char		a;
	int			x;
	int			y;

	x = 0;
	y = 0;
	updatecoords(game, &x, &y, key);
	game->p_new.x = game->p_old.x + x;
	game->p_new.y = game->p_old.y + y;
	a = game->map.maparray[game->p_new.y][game->p_new.x];
	if (key == RIGHT || key == LEFT || key == UP || key == DOWN)
	{
		if (a != '1')
			executemovement(a, game, key);
		layerimg(game->map.img_player, &game->gameimg, \
		game->p_old.x * IMG_W, game->p_old.y * IMG_H);
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, \
		game->gameimg.ptr, 0, 0);
		enemymove(game);
	}
	return (0);
}
