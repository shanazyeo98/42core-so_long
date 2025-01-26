/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:19:09 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/17 13:46:48 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkfd(int a)
{
	if (a == -1)
	{
		ft_printf("Error\nUnable to find file.\n");
		maperror(NULL, 0, NULL, NULL);
	}
}

size_t	ft_strlen2(const char *a)
{
	size_t	length;

	length = 0;
	while (*a != '\0' && *a != '\n')
	{
		length++;
		a++;
	}
	return (length);
}

void	initmapdets(t_map *dets)
{
	dets->collectible = 0;
	dets->exit = 0;
	dets->collectible_c = 0;
	dets->exit_c = 0;
	dets->maparray = NULL;
	dets->player = 0;
	dets->rowlength = 0;
	dets->rows = 0;
	dets->collectible_game = 0;
	dets->img_bg.ptr = NULL;
	dets->img_collect.ptr = NULL;
	dets->img_exit.ptr = NULL;
	dets->img_player.ptr = NULL;
	dets->img_wall.ptr = NULL;
}

void	countelements(char a, t_map *map_dets)
{
	if (a == 'P')
		map_dets->player++;
	if (a == 'E')
		map_dets->exit++;
	if (a == 'C')
		map_dets->collectible++;
}

int	checkelements(char a)
{
	char	elements[5];
	int		i;

	elements[0] = '0';
	elements[1] = '1';
	elements[2] = 'C';
	elements[3] = 'E';
	elements[4] = 'P';
	i = 0;
	while (i < 5)
	{
		if (a == elements[i])
			return (1);
		i++;
	}
	return (0);
}
