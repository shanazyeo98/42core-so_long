/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:45:29 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/15 18:33:33 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//functions to handle errors and freeing of memory

void	cleararray(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

//functions for lst clearing

void	del(void *content)
{
	free(content);
}

void	clear(t_list **head)
{
	ft_lstclear(head, &del);
	free(head);
}

void	maperror(char **array, int size, t_list **q, t_list **v)
{
	if (array != NULL)
		cleararray(array, size);
	if (q != NULL)
		clear(q);
	if (v != NULL)
		clear(v);
	exit(1);
}
