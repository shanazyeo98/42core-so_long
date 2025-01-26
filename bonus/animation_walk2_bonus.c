/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_walk2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:23:48 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/15 18:33:45 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	renderdown(char a, t_game *game, t_img img_n, t_img img_o)
{
	int			y;
	long int	timenow;
	int			frame;

	y = 0;
	while (y < IMG_H)
	{
		timenow = gettime();
		frame = game->a_dwalk.currentframe;
		frame++;
		if (frame == ft_lstsize(game->a_dwalk.frames))
			frame = 0;
		if (timenow - game->a_dwalk.last_updated > 1000 / 16)
		{
			game->a_dwalk.currentframe = frame;
			updatecollectible(game);
			layerbackground(game, img_n, img_o);
			updateframe(&game->a_dwalk, (game->p_old.x * IMG_W), \
			game->p_old.y * IMG_H + y, *game);
			y += 15;
		}
	}
	layerbackground(game, img_n, img_o);
	if (a == 'C')
		game->map.collectible_game++;
}

//up

void	renderup(char a, t_game *game, t_img img_n, t_img img_o)
{
	int			y;
	long int	timenow;
	int			frame;

	y = 0;
	while (y < IMG_H)
	{
		timenow = gettime();
		frame = game->a_uwalk.currentframe;
		frame++;
		if (frame == ft_lstsize(game->a_uwalk.frames))
			frame = 0;
		if (timenow - game->a_uwalk.last_updated > 1000 / 16)
		{
			game->a_uwalk.currentframe = frame;
			updatecollectible(game);
			layerbackground(game, img_n, img_o);
			updateframe(&game->a_uwalk, (game->p_old.x * IMG_W), \
			game->p_old.y * IMG_H - y, *game);
			y += 15;
		}
	}
	layerbackground(game, img_n, img_o);
	if (a == 'C')
		game->map.collectible_game++;
}

//right

void	renderright(char a, t_game *game, t_img img_n, t_img img_o)
{
	int			x;
	long int	timenow;
	int			frame;

	x = 0;
	while (x < IMG_W)
	{
		timenow = gettime();
		frame = game->a_rwalk.currentframe;
		frame++;
		if (frame == ft_lstsize(game->a_rwalk.frames))
			frame = 0;
		if (timenow - game->a_rwalk.last_updated > 1000 / 16)
		{
			game->a_rwalk.currentframe = frame;
			updatecollectible(game);
			layerbackground(game, img_n, img_o);
			updateframe(&game->a_rwalk, (game->p_old.x * IMG_W) + x, \
			game->p_old.y * IMG_H, *game);
			x += 15;
		}
	}
	layerbackground(game, img_n, img_o);
	if (a == 'C')
		game->map.collectible_game++;
}

void	renderleft(char a, t_game *game, t_img img_n, t_img img_o)
{
	int			x;
	long int	timenow;
	int			frame;

	x = 0;
	while (x < IMG_W)
	{
		timenow = gettime();
		frame = game->a_lwalk.currentframe;
		frame++;
		if (frame == ft_lstsize(game->a_lwalk.frames))
			frame = 0;
		if (timenow - game->a_lwalk.last_updated > 1000 / 16)
		{
			game->a_lwalk.currentframe = frame;
			updatecollectible(game);
			layerbackground(game, img_n, img_o);
			updateframe(&game->a_lwalk, (game->p_old.x * IMG_W) - x, \
			game->p_old.y * IMG_H, *game);
			x += 15;
		}
	}
	layerbackground(game, img_n, img_o);
	if (a == 'C')
		game->map.collectible_game++;
}
