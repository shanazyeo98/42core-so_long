/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_idle_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:03:24 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/15 18:33:56 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	assignimgexit(t_game *game)
{
	t_list	*node;

	node = game->a_exit.frames;
	newimg_xpm(EXIT, node->content, *game);
	node = node->next;
	newimg_xpm(EXIT2, node->content, *game);
	node = node->next;
	newimg_xpm(EXIT3, node->content, *game);
	node = node->next;
	newimg_xpm(EXIT2, node->content, *game);
}

void	execanim(t_anim *anim, int x, int y, t_game game)
{
	int			frame;
	long int	timenow;

	frame = anim->currentframe;
	if (frame == ft_lstsize(anim->frames) - 1)
		frame = 0;
	else
		frame++;
	timenow = gettime();
	if (timenow - anim->last_updated > 1000 / 2)
	{
		anim->currentframe = frame;
		layerimg(game.map.img_bg, &game.gameimg, x * IMG_W, y * IMG_H);
		updateframe(anim, x * IMG_W, y * IMG_H, game);
	}
}

void	assignplayerimg(t_game *game)
{
	t_list	*node;

	node = game->a_player.frames;
	newimg_xpm(PLAYER, node->content, *game);
	node = node->next;
	newimg_xpm(PBLINK1, node->content, *game);
	node = node->next;
	newimg_xpm(PBLINK2, node->content, *game);
	node = node->next;
	newimg_xpm(PBLINK3, node->content, *game);
	node = node->next;
	newimg_xpm(PBLINK2, node->content, *game);
	node = node->next;
	newimg_xpm(PBLINK1, node->content, *game);
	node = node->next;
	newimg_xpm(PLAYER2, node->content, *game);
}

void	execpanim(t_anim *anim, int x, int y, t_game game)
{
	int			frame;
	long int	delay;
	long int	timenow;

	frame = anim->currentframe;
	if (frame == ft_lstsize(anim->frames) - 1)
		frame = 0;
	else
		frame++;
	if (frame == 1)
		delay = 2;
	else if (frame == 0)
		delay = 2;
	else
		delay = 12;
	timenow = gettime();
	if (timenow - anim->last_updated > 1000 / delay)
	{
		anim->currentframe = frame;
		layerimg(game.map.img_bg, &game.gameimg, x * IMG_W, y * IMG_H);
		if (game.map.maparray[y][x] == 'E')
			layerimg(game.map.img_exit, &game.gameimg, x * IMG_W, y * IMG_H);
		updateframe(anim, x * IMG_W, y * IMG_H, game);
	}
}
