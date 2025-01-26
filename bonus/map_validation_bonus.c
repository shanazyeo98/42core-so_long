/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:18:24 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/17 17:58:09 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//parsing, checking elements and row lengths of map. If ok, store into array.

void	maprows(char *map, t_map *map_dets)
{
	int		fd;
	int		rows;
	char	*firstrow;

	fd = open(map, O_RDONLY);
	checkfd(fd);
	firstrow = get_next_line(fd);
	rows = 0;
	map_dets->rowlength = ft_strlen2(firstrow);
	while (firstrow != NULL)
	{
		rows++;
		free(firstrow);
		firstrow = get_next_line(fd);
	}
	map_dets->rows = rows;
	close(fd);
	if (map_dets->rows < 3 || map_dets->rowlength < 3 || \
	map_dets->rows > 9 || map_dets->rowlength > 19)
	{
		ft_printf("Error\nMap invalid. Map is too small / big.\n");
		maperror(NULL, 0, NULL, NULL);
	}
}

int	checkindivele(char *row, size_t row_i, t_map *map_dets)
{
	size_t	i;

	i = 0;
	while (row[i] != '\0' && row[i] != '\n')
	{
		if (row_i == 0 || row_i == map_dets->rows - 1)
		{
			if (row[i] != '1')
				return (0);
		}
		else
		{
			if ((i == 0 || i == map_dets->rowlength -1) && row[i] != '1')
				return (0);
			else
			{
				if (checkelements(row[i]) != 1)
					return (0);
			}
		}
		countelements(row[i], map_dets);
		i++;
	}
	return (1);
}

void	checkmap(char *row, size_t i, t_map *map_dets)
{
	if (ft_strlen2(row) != map_dets->rowlength)
	{
		ft_printf("Error\nRows are not of equal length.\n");
		maperror(map_dets->maparray, map_dets->rows, NULL, NULL);
	}
	if (checkindivele(row, i, map_dets) == 0)
	{
		ft_printf("Error\nCharacters in map are invalid.\n");
		maperror(map_dets->maparray, map_dets->rows, NULL, NULL);
	}
}

void	assignarray(t_map map_dets, int fd)
{
	size_t	i;

	i = 0;
	while (i < map_dets.rows)
	{
		(map_dets.maparray)[i] = get_next_line(fd);
		if ((map_dets.maparray[i]) == NULL)
		{
			ft_printf("Error\nMemory allocation issues.");
			maperror(map_dets.maparray, i + 1, NULL, NULL);
		}
		i++;
	}
}

t_map	parsemap(char *map)
{
	int		fd;
	size_t	i;
	t_map	map_dets;

	initmapdets(&map_dets);
	maprows(map, &map_dets);
	fd = open(map, O_RDONLY);
	checkfd(fd);
	map_dets.maparray = malloc(sizeof(char *) * map_dets.rows);
	assignarray(map_dets, fd);
	i = 0;
	while (i < map_dets.rows)
	{
		checkmap((map_dets.maparray)[i], i, &map_dets);
		i++;
	}
	if (map_dets.collectible < 1 || map_dets.exit != 1 || \
	map_dets.player != 1)
	{
		ft_printf("Error\nIncorrect number of characters.\n");
		maperror(map_dets.maparray, map_dets.rows, NULL, NULL);
	}
	close(fd);
	return (map_dets);
}
