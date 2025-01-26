/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:25:56 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/15 18:33:24 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	updatecoords(t_game *game, int *x, int *y, int key)
{
	if (key == RIGHT && game->p_old.x != game->map.rowlength - 1)
		(*x)++;
	if (key == LEFT && game->p_old.x != 0)
		(*x)--;
	if (key == UP && game->p_old.y != 0)
		(*y)--;
	if (key == DOWN && game->p_old.y != game->map.rows - 1)
		(*y)++;
}
