/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:44:34 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/16 12:05:19 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//functions to clear the linked list of imgs

void	clearimgs(t_list **head, t_win win)
{
	t_list	*node;
	t_img	*img;

	node = *head;
	while (node != NULL)
	{
		img = node->content;
		mlx_destroy_image(win.mlx_ptr, img->ptr);
		node = node->next;
	}
	clear(head);
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
}

void	clearassets(t_game game)
{
	clearsprites(game.map, game.win);
	if (game.gameimg.ptr != NULL)
		mlx_destroy_image(game.win.mlx_ptr, game.gameimg.ptr);
	cleararray(game.map.maparray, game.map.rows);
	if (game.win.win_ptr != NULL)
		mlx_destroy_window(game.win.mlx_ptr, game.win.win_ptr);
	if (game.win.mlx_ptr != NULL)
		mlx_destroy_display(game.win.mlx_ptr);
	free(game.win.mlx_ptr);
}

void	failedgame(t_game game)
{
	ft_printf("Error\nFiles failed to create.\n");
	clearassets(game);
	exit(1);
}
