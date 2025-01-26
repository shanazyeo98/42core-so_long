/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validpathchecks_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:22:24 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/15 18:32:50 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	checkele(char **array, size_t x, size_t y, t_map *dets)
{
	char	a;

	if (x > dets->rowlength - 1 || y > dets->rows - 1)
		return (0);
	a = array[y][x];
	if (a == '0' || a == 'C' || a == 'E')
	{
		if (a == 'C')
			dets->collectible_c++;
		if (a == 'E')
			dets->exit_c++;
		return (1);
	}
	return (0);
}

int	checkpos(int x, int y, t_list *v, t_list *q)
{
	while (v != NULL)
	{
		if (x == ((int *) v->content)[0] && y == ((int *) v->content)[1])
			return (0);
		v = v->next;
	}
	while (q != NULL)
	{
		if (x == ((int *) q->content)[0] && y == ((int *) q->content)[1])
			return (0);
		q = q->next;
	}
	return (1);
}
