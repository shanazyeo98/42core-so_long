/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:28:53 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/17 13:58:31 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
//# include <X11/keysym.h>

# define IMG_H 100
# define IMG_W 100
# define PLAYER "textures/itadori"
# define BG "textures/background"
# define WALL "textures/wall"
# define EXIT "textures/exit"
# define COLLECT "textures/collectible"

//keys for mac
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364

typedef struct s_img
{
	void	*ptr;
	int		w;
	int		h;
	void	*addr;
	int		bpp;
	int		sline;
	int		endian;
}	t_img;

typedef struct s_map
{
	int			collectible;
	int			exit;
	int			player;
	int			collectible_c;
	int			exit_c;
	int			collectible_game;
	size_t		rowlength;
	size_t		rows;
	char		**maparray;
	t_img		img_player;
	t_img		img_bg;
	t_img		img_wall;
	t_img		img_collect;
	t_img		img_exit;
}	t_map;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_win;

typedef struct s_pos
{
	size_t	x;
	size_t	y;
}	t_pos;

typedef struct s_game
{
	t_win	win;
	t_map	map;
	t_pos	play_pos_old;
	t_pos	play_pos_new;
	t_list	**imgseq;
	t_list	**v;
	t_list	**q;
	t_img	gameimg;
}	t_game;

//parse map functions
t_map	parsemap(char *map);
void	countelements(char a, t_map *map_dets);
void	initmapdets(t_map *dets);
size_t	ft_strlen2(const char *a);
void	validpath(char **array, t_map *map_dets, t_game *game);
void	checkfile(char *map);
void	checkfd(int a);
int		checkelements(char a);
int		checkele(char **array, size_t x, size_t y, t_map *dets);
int		checkpos(int x, int y, t_list *v, t_list *q);

//initializing the display and images
void	initgame(t_game *game);

//hook events
void	hookevents(t_game game);

//escaping window functions
int		closescreenesc(int key, t_game *game);
int		closescreencross(t_game *game);

//minimize window function
int		maxwindow(t_game *game);

//movement functions
int		movement(int key, t_game *game);

//draw functions
//void	layerimg(t_img src, t_img *dst);
//void	drawimg(t_img *img, char a, t_map map);

//win functions
int		win(t_game *game);

//clearing functions
void	cleararray(char **array, int size);
void	maperror(char **array, int size, t_list **q, t_list **v);
void	clear(t_list **head);
void	clearimgs(t_list **head, t_win win);
void	clearsprites(t_map map, t_win win);
void	clearassets(t_game game);
void	failedgame(t_game game);

//experiment
void	drawimg(t_img *img, t_map map, int x, int y);
void	layerimg(t_img src, t_img *dst, int x, int y);

#endif
