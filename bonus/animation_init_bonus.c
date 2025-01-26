/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_init_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:27:31 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/16 16:29:47 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exitpos(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	while (y < game->map.rows)
	{
		while (x < game->map.rowlength)
		{
			if (game->map.maparray[y][x] == 'E')
			{
				game->exit.x = x;
				game->exit.y = y;
				break ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	assignemovanim(t_game *game)
{
	t_list	*node;

	node = game->a_enemymove.frames;
	newimg_xpm(ENEMYMOVE1, node->content, *game);
	node = node->next;
	newimg_xpm(ENEMYMOVE2, node->content, *game);
	node = node->next;
	newimg_xpm(ENEMYMOVE3, node->content, *game);
	node = node->next;
	newimg_xpm(ENEMYMOVE4, node->content, *game);
	node = node->next;
	newimg_xpm(ENEMYMOVE5, node->content, *game);
	node = node->next;
	newimg_xpm(ENEMYMOVE6, node->content, *game);
	node = node->next;
	newimg_xpm(ENEMYMOVE7, node->content, *game);
	node = node->next;
	newimg_xpm(ENEMYMOVE8, node->content, *game);
	node = node->next;
	newimg_xpm(ENEMYMOVE9, node->content, *game);
	node = node->next;
	newimg_xpm(ENEMYMOVE10, node->content, *game);
}

void	assignenemy(t_game *game)
{
	t_list	*node;

	node = game->a_enemy.frames;
	newimg_xpm(ENEMY, node->content, *game);
	node = node->next;
	newimg_xpm(ENEMY2, node->content, *game);
	node = node->next;
	newimg_xpm(ENEMY3, node->content, *game);
	node = node->next;
	newimg_xpm(ENEMY4, node->content, *game);
	node = node->next;
	newimg_xpm(ENEMY5, node->content, *game);
	node = node->next;
	newimg_xpm(ENEMY6, node->content, *game);
}

void	initaddanim(t_game *game)
{
	assignenemy(game);
	initanim(game, &game->a_enemymove, 10);
	assignemovanim(game);
	initanim(game, &game->a_lose, 10);
	assignloseimg(game);
	initanim(game, &game->a_win, 5);
	assignwinimg(game);
}

void	initanimations(t_game *game)
{
	exitpos(game);
	initanim(game, &game->a_player, 7);
	assignplayerimg(game);
	initanim(game, &game->a_exit, 4);
	assignimgexit(game);
	initanim(game, &game->a_rwalk, 7);
	assignimgrwalk(game);
	initanim(game, &game->a_lwalk, 7);
	assignimglwalk(game);
	initanim(game, &game->a_uwalk, 2);
	assignimguwalk(game);
	initanim(game, &game->a_dwalk, 2);
	assignimgdwalk(game);
	initanim(game, &game->a_enemy, 6);
	initaddanim(game);
}
