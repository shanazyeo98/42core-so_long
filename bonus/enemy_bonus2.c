/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:52:12 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/17 13:52:44 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemycoords(t_game *game, size_t *x, size_t *y)
{
	int		mov;

	while (1)
	{
		*x = game->enemy.x;
		*y = game->enemy.y;
		mov = rand() % 4;
		if (mov == 0 && *x != game->map.rowlength - 1)
			(*x)++;
		if (mov == 1 && *x != 0)
			(*x)--;
		if (mov == 2 && *y != game->map.rows - 1)
			(*y)++;
		if (mov == 3 && *y != 0)
			(*y)--;
		if (game->map.maparray[*y][*x] != '1' && game->map.maparray[*y][*x] \
		!= 'E' && !(*x == game->enemy.x && *y == game->enemy.y))
			break ;
	}
}
