/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:44:34 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/16 12:07:00 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//functions to clear the linked list of imgs

void	clearimgs(t_list *head, t_win win)
{
	t_list	*node;
	t_img	*img;

	node = head;
	while (node != NULL)
	{
		img = node->content;
		if (img->ptr != NULL)
			mlx_destroy_image(win.mlx_ptr, img->ptr);
		node = node->next;
	}
	ft_lstclear(&head, &del);
}

void	clearsprites(t_map map, t_win win)
{
	if (map.img_bg.ptr != NULL)
		mlx_destroy_image(win.mlx_ptr, map.img_bg.ptr);
	if (map.img_player.ptr != NULL)
		mlx_destroy_image(win.mlx_ptr, map.img_player.ptr);
	if (map.img_wall.ptr != NULL)
		mlx_destroy_image(win.mlx_ptr, map.img_wall.ptr);
	if (map.img_exit.ptr != NULL)
		mlx_destroy_image(win.mlx_ptr, map.img_exit.ptr);
	if (map.img_collect.ptr != NULL)
		mlx_destroy_image(win.mlx_ptr, map.img_collect.ptr);
	if (map.img_enemy.ptr != NULL)
		mlx_destroy_image(win.mlx_ptr, map.img_enemy.ptr);
	if (map.img_empty.ptr != NULL)
		mlx_destroy_image(win.mlx_ptr, map.img_empty.ptr);
}

void	clearanimations(t_game game)
{
	if (game.a_dwalk.frames != NULL)
		clearimgs(game.a_dwalk.frames, game.win);
	if (game.a_uwalk.frames != NULL)
		clearimgs(game.a_uwalk.frames, game.win);
	if (game.a_rwalk.frames != NULL)
		clearimgs(game.a_rwalk.frames, game.win);
	if (game.a_lwalk.frames != NULL)
		clearimgs(game.a_lwalk.frames, game.win);
	if (game.a_player.frames != NULL)
		clearimgs(game.a_player.frames, game.win);
	if (game.a_exit.frames != NULL)
		clearimgs(game.a_exit.frames, game.win);
	if (game.a_enemymove.frames != NULL)
		clearimgs(game.a_enemymove.frames, game.win);
	if (game.a_enemy.frames != NULL)
		clearimgs(game.a_enemy.frames, game.win);
	if (game.a_win.frames != NULL)
		clearimgs(game.a_win.frames, game.win);
	if (game.a_lose.frames != NULL)
		clearimgs(game.a_lose.frames, game.win);
}

void	clearassets(t_game game)
{
	clearsprites(game.map, game.win);
	cleararray(game.map.maparray, game.map.rows);
	clearanimations(game);
	if (game.gameimg.ptr != NULL)
		mlx_destroy_image(game.win.mlx_ptr, game.gameimg.ptr);
	if (game.win.win_ptr != NULL)
		mlx_destroy_window(game.win.mlx_ptr, game.win.win_ptr);
	if (game.win.mlx_ptr != NULL)
		mlx_destroy_display(game.win.mlx_ptr);
	free(game.win.mlx_ptr);
}

void	failedgame(t_game game)
{
	ft_printf("Error\nImage failed to create.\n");
	clearassets(game);
	exit(1);
}
