/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:09:45 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/16 14:44:43 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	closescreenesc(int key, t_game *game)
{
	if (key == ESC)
		mlx_loop_end(game->win.mlx_ptr);
	return (0);
}

int	closescreencross(t_game *game)
{
	mlx_loop_end(game->win.mlx_ptr);
	return (0);
}

int	maxwindow(t_game *game)
{
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, \
	game->gameimg.ptr, 0, 0);
	movementcount(game->map.movement, game);
	return (0);
}

int	end(t_game *game)
{
	char	position;

	position = game->map.maparray[game->p_old.y][game->p_old.x];
	if (position == 'E' && game->map.collectible == game->map.collectible_game)
	{
		winanim(game);
		mlx_loop_end(game->win.mlx_ptr);
	}
	if (game->p_old.x == game->enemy.x && game->p_old.y == game->enemy.y)
	{
		loseanim(game);
		mlx_loop_end(game->win.mlx_ptr);
	}
	return (0);
}

//mlx key hook's mask is set to keyrelease mask

void	hookevents(t_game game)
{
	mlx_hook(game.win.win_ptr, 02, 1L << 0, &closescreenesc, &game);
	mlx_hook(game.win.win_ptr, 17, 1L << 20, &closescreencross, &game);
	mlx_hook(game.win.win_ptr, 15, 1L << 16, &maxwindow, &game);
	mlx_key_hook(game.win.win_ptr, &movement, &game);
	mlx_loop_hook(game.win.mlx_ptr, &loopevents, &game);
}
