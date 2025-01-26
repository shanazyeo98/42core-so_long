/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:01:01 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/16 11:53:37 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

long int	gettime(void)
{
	struct timeval	tv;
	long int		time;

	gettimeofday(&tv, NULL);
	time = (1000 * tv.tv_sec) + (tv.tv_usec / 1000);
	return (time);
}

void	updateframe(t_anim *anim, int x, int y, t_game game)
{
	t_list	*node;
	int		i;

	node = anim->frames;
	i = 0;
	while (i < anim->currentframe)
	{
		node = node->next;
		i++;
	}
	layerimg(*((t_img *) node->content), &game.gameimg, x, y);
	mlx_put_image_to_window(game.win.mlx_ptr, game.win.win_ptr, \
	game.gameimg.ptr, 0, 0);
	mlx_do_sync(game.win.mlx_ptr);
	anim->last_updated = gettime();
}

void	initanim(t_game *game, t_anim *anim, int frames)
{
	t_img	*frame;
	t_list	*node;
	int		i;

	i = 0;
	while (i < frames)
	{
		frame = malloc(sizeof(t_img));
		if (frame == NULL)
			failedgame(*game);
		frame->ptr = NULL;
		if (i == 0)
			anim->frames = ft_lstnew(frame);
		else
		{
			node = ft_lstnew(frame);
			ft_lstadd_back(&anim->frames, node);
		}
		i++;
	}
	anim->currentframe = 0;
	anim->last_updated = gettime();
}
