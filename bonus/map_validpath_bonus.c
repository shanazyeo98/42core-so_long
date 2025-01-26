/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validpath_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:48:31 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/15 18:32:53 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//purpose: to find if there is a valid path to reach all the objective tiles
//using breadth first search

void	retrievestart(t_game *game, int *startpos)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < game->map.rows)
	{
		while (x < game->map.rowlength)
		{
			if (game->map.maparray[y][x] == 'P')
			{
				startpos[0] = x;
				startpos[1] = y;
				game->p_old.x = x;
				game->p_old.y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	createcoord(int x, int y, t_game *game, int start)
{
	int		*result;
	t_list	*node;

	result = malloc(sizeof(int) * 2);
	if (result == NULL)
	{
		ft_printf("Error\nMemory allocation failed.\n");
		maperror(game->map.maparray, game->map.rows, game->q, game->v);
	}
	result[0] = x;
	result[1] = y;
	node = ft_lstnew(result);
	if (node == NULL)
	{
		ft_printf("Error\nMemory allocation failed.\n");
		maperror(game->map.maparray, game->map.rows, game->q, game->v);
	}
	if (start == 0)
	{
		retrievestart(game, result);
		*(game->q) = node;
	}
	else
		ft_lstadd_back(game->q, node);
}

void	createqueue(char **a, t_map *map, t_game *game)
{
	int		x;
	int		y;
	int		i;
	t_list	*target;

	target = *(game->q);
	x = ((int *) target->content)[0];
	y = ((int *) target->content)[1];
	i = -1;
	while (i >= -1 && i <= 1)
	{
		if (checkpos(x + i, y, *(game->v), *(game->q)) == 1 \
		&& checkele(a, x + i, y, map) == 1)
			createcoord(x + i, y, game, 1);
		if (checkpos(x, y + i, *(game->v), *(game->q)) == 1 \
		&& checkele(a, x, y + i, map) == 1)
			createcoord(x, y + i, game, 1);
		i++;
	}
}

void	shifttovisited(t_list **v, t_list **q)
{
	t_list	*nodetoshift;
	t_list	*secondnode;

	nodetoshift = *q;
	secondnode = nodetoshift->next;
	nodetoshift->next = NULL;
	ft_lstadd_back(v, nodetoshift);
	*q = secondnode;
}

void	validpath(char **array, t_map *map_dets, t_game *game)
{
	game->v = malloc(sizeof(t_list *));
	game->q = malloc(sizeof(t_list *));
	if (game->q == NULL || game->v == NULL)
		maperror(array, map_dets->rows, game->q, game->v);
	*(game->v) = NULL;
	createcoord(0, 0, game, 0);
	while (ft_lstsize(*game->q) > 0)
	{
		createqueue(array, map_dets, game);
		shifttovisited(game->v, game->q);
	}
	if (!(map_dets->collectible == map_dets->collectible_c \
	&& map_dets->exit == map_dets->exit_c))
	{
		ft_printf("Error\nMap is not playable.\n");
		maperror(array, map_dets->rows, game->q, game->v);
	}
	clear(game->v);
	clear(game->q);
}
