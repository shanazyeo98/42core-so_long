/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:09:52 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/16 11:47:07 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkfile(char *map)
{
	char	**split;
	int		i;

	split = ft_split(map, '.');
	if (split == NULL)
	{
		ft_printf("Error\nMap invalid. Please check whether it is .ber file.\n");
		exit (1);
	}
	i = 0;
	while (split[i] != NULL)
		i++;
	if (ft_strcmp(split[i - 1], "ber") != 0)
	{
		cleararray(split, i);
		ft_printf("Error\nMap invalid. Please check whether it is .ber file.\n");
		exit (1);
	}
	cleararray(split, i);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nPlease provide one file.\n");
		exit(1);
	}
	checkfile(argv[1]);
	game.map = parsemap(argv[1]);
	validpath(game.map.maparray, &game.map, &game);
	initgame(&game);
	hookevents(game);
	mlx_loop(game.win.mlx_ptr);
	clearassets(game);
}
