/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_ending_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 20:04:36 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/15 18:33:59 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	assignloseimg(t_game *game)
{
	t_list	*node;

	node = game->a_lose.frames;
	newimg_xpm(LOSE1, node->content, *game);
	node = node->next;
	newimg_xpm(LOSE2, node->content, *game);
	node = node->next;
	newimg_xpm(LOSE3, node->content, *game);
	node = node->next;
	newimg_xpm(LOSE4, node->content, *game);
	node = node->next;
	newimg_xpm(LOSE5, node->content, *game);
	node = node->next;
	newimg_xpm(LOSE6, node->content, *game);
	node = node->next;
	newimg_xpm(LOSE7, node->content, *game);
	node = node->next;
	newimg_xpm(LOSE8, node->content, *game);
	node = node->next;
	newimg_xpm(LOSE9, node->content, *game);
	node = node->next;
	newimg_xpm(LOSE10, node->content, *game);
}

void	loseanim(t_game *game)
{
	int			frame;
	long int	timenow;
	t_pos		e;

	frame = 0;
	e = game->enemy;
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, \
	game->map.img_empty.ptr, 0, IMG_H * game->map.rows);
	mlx_string_put(game->win.mlx_ptr, game->win.win_ptr, IMG_W * \
	game->map.rowlength / 2, IMG_H * game->map.rows + 50, 0xFFFFFF, "LOSE");
	while (frame < ft_lstsize(game->a_lose.frames))
	{
		timenow = gettime();
		if (timenow - game->a_lose.last_updated > 1000 / 12)
		{
			game->a_lose.currentframe = frame;
			layerimg(game->map.img_bg, &game->gameimg, \
			e.x * IMG_W, e.y * IMG_H);
			layerimg(game->map.img_enemy, &game->gameimg, \
			e.x * IMG_W, e.y * IMG_H);
			updateframe(&game->a_lose, e.x * IMG_W, e.y * IMG_H, *game);
			frame++;
		}
	}
	sleep(5);
}

void	assignwinimg(t_game *game)
{
	t_list	*node;

	node = game->a_win.frames;
	newimg_xpm(WIN1, node->content, *game);
	node = node->next;
	newimg_xpm(WIN2, node->content, *game);
	node = node->next;
	newimg_xpm(WIN3, node->content, *game);
	node = node->next;
	newimg_xpm(WIN4, node->content, *game);
	node = node->next;
	newimg_xpm(WIN5, node->content, *game);
}

void	winanim(t_game *game)
{
	int			frame;
	long int	timenow;
	t_pos		p;

	frame = 0;
	p = game->p_new;
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, \
	game->map.img_empty.ptr, 0, IMG_H * game->map.rows);
	mlx_string_put(game->win.mlx_ptr, game->win.win_ptr, IMG_W * \
	game->map.rowlength / 2, IMG_H * game->map.rows + 50, 0xFFFFFF, "WIN");
	while (frame < ft_lstsize(game->a_win.frames))
	{
		timenow = gettime();
		if (timenow - game->a_win.last_updated > 1000 / 12)
		{
			game->a_win.currentframe = frame;
			layerimg(game->map.img_bg, &game->gameimg, p.x * IMG_W, \
			p.y * IMG_H);
			layerimg(game->map.img_exit, &game->gameimg, p.x * IMG_W, \
			p.y * IMG_H);
			updateframe(&game->a_win, p.x * IMG_W, p.y * IMG_H, *game);
			frame++;
		}
	}
	sleep(5);
}
