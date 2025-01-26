/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_walk_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:56:30 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/15 18:33:48 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	assignimgdwalk(t_game *game)
{
	t_list	*node;

	node = game->a_dwalk.frames;
	newimg_xpm(DWALK1, node->content, *game);
	node = node->next;
	newimg_xpm(DWALK2, node->content, *game);
}

void	assignimguwalk(t_game *game)
{
	t_list	*node;

	node = game->a_uwalk.frames;
	newimg_xpm(UWALK2, node->content, *game);
	node = node->next;
	newimg_xpm(UWALK3, node->content, *game);
}

void	assignimgrwalk(t_game *game)
{
	t_list	*node;

	node = game->a_rwalk.frames;
	newimg_xpm(RWALK1, node->content, *game);
	node = node->next;
	newimg_xpm(RWALK2, node->content, *game);
	node = node->next;
	newimg_xpm(RWALK3, node->content, *game);
	node = node->next;
	newimg_xpm(RWALK4, node->content, *game);
	node = node->next;
	newimg_xpm(RWALK3, node->content, *game);
	node = node->next;
	newimg_xpm(RWALK2, node->content, *game);
	node = node->next;
	newimg_xpm(RWALK1, node->content, *game);
}

void	assignimglwalk(t_game *game)
{
	t_list	*node;

	node = game->a_lwalk.frames;
	newimg_xpm(LWALK1, node->content, *game);
	node = node->next;
	newimg_xpm(LWALK2, node->content, *game);
	node = node->next;
	newimg_xpm(LWALK3, node->content, *game);
	node = node->next;
	newimg_xpm(LWALK4, node->content, *game);
	node = node->next;
	newimg_xpm(LWALK3, node->content, *game);
	node = node->next;
	newimg_xpm(LWALK2, node->content, *game);
	node = node->next;
	newimg_xpm(LWALK1, node->content, *game);
}
