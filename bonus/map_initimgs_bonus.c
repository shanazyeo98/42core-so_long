/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initimgs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:58:08 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/16 12:00:38 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	setimgsnull(t_game *game)
{
	game->map.img_bg.ptr = NULL;
	game->map.img_collect.ptr = NULL;
	game->map.img_empty.ptr = NULL;
	game->map.img_enemy.ptr = NULL;
	game->map.img_exit.ptr = NULL;
	game->map.img_player.ptr = NULL;
	game->map.img_wall.ptr = NULL;
	game->a_player.frames = NULL;
	game->a_exit.frames = NULL;
	game->a_rwalk.frames = NULL;
	game->a_lwalk.frames = NULL;
	game->a_uwalk.frames = NULL;
	game->a_dwalk.frames = NULL;
	game->a_enemymove.frames = NULL;
	game->a_lose.frames = NULL;
	game->a_win.frames = NULL;
	game->a_enemy.frames = NULL;
}
