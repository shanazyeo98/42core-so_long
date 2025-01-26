/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:11:16 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/15 18:33:31 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	loopevents(t_game *game)
{
	end(game);
	execpanim(&game->a_player, game->p_old.x, game->p_old.y, \
	*game);
	if (game->map.maparray[game->p_old.y][game->p_old.x] != 'E')
		execanim(&game->a_exit, game->exit.x, game->exit.y, *game);
	enemyidle(game, game->enemy.x, game->enemy.y);
	return (0);
}
