/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shayeo <shayeo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:28:53 by shayeo            #+#    #+#             */
/*   Updated: 2024/08/17 13:58:24 by shayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include <sys/time.h>
# include <time.h>
//# include <X11/keysym.h>

# define IMG_H 100
# define IMG_W 100
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define PLAYER "textures/itadori_idle_2.xpm"
# define PLAYER2 "textures/itadori_idle_1.xpm"
# define RWALK1 "textures/rwalk_1.xpm"
# define RWALK2 "textures/rwalk_2.xpm"
# define RWALK3 "textures/rwalk_3.xpm"
# define RWALK4 "textures/rwalk_4.xpm"
# define LWALK1 "textures/lwalk_1"
# define LWALK2 "textures/lwalk_2"
# define LWALK3 "textures/lwalk_3"
# define LWALK4 "textures/lwalk_4"
# define UWALK2 "textures/uwalk_2.xpm"
# define UWALK3 "textures/uwalk_3.xpm"
# define DWALK1 "textures/dwalk_1.xpm"
# define DWALK2 "textures/dwalk_2.xpm"
# define PBLINK1 "textures/itadori_blink2"
# define PBLINK2 "textures/itadori_blink1"
# define PBLINK3 "textures/itadori_blink3"
# define BG "textures/background"
# define WALL "textures/wall"
# define EXIT "textures/exit_1.xpm"
# define EXIT2 "textures/exit_2.xpm"
# define EXIT3 "textures/exit_3"
# define COLLECT "textures/finger_1.xpm"
# define ENEMY "textures/sukuna"
# define ENEMY2 "textures/sukuna2.xpm"
# define ENEMY3 "textures/sukuna3.xpm"
# define ENEMY4 "textures/sukuna4.xpm"
# define ENEMY5 "textures/sukuna5.xpm"
# define ENEMY6 "textures/sukuna6.xpm"
# define ENEMYMOVE1 "textures/enemy_move1.xpm"
# define ENEMYMOVE2 "textures/enemy_move2.xpm"
# define ENEMYMOVE3 "textures/enemy_move3.xpm"
# define ENEMYMOVE4 "textures/enemy_move4.xpm"
# define ENEMYMOVE5 "textures/enemy_move5.xpm"
# define ENEMYMOVE6 "textures/enemy_move6.xpm"
# define ENEMYMOVE7 "textures/enemy_move7.xpm"
# define ENEMYMOVE8 "textures/enemy_move8.xpm"
# define ENEMYMOVE9 "textures/enemy_move9.xpm"
# define ENEMYMOVE10 "textures/enemy_move10.xpm"
# define LOSE1 "textures/lose1.xpm"
# define LOSE2 "textures/lose2.xpm"
# define LOSE3 "textures/lose3.xpm"
# define LOSE4 "textures/lose4.xpm"
# define LOSE5 "textures/lose5.xpm"
# define LOSE6 "textures/lose6.xpm"
# define LOSE7 "textures/lose7.xpm"
# define LOSE8 "textures/lose8.xpm"
# define LOSE9 "textures/lose9.xpm"
# define LOSE10 "textures/lose10.xpm"
# define WIN1 "textures/win1"
# define WIN2 "textures/win2"
# define WIN3 "textures/win3"
# define WIN4 "textures/win4"
# define WIN5 "textures/win5"

//keys for mac
# define ESC 65307

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
	int			movement;
	size_t		rowlength;
	size_t		rows;
	char		**maparray;
	t_img		img_player;
	t_img		img_bg;
	t_img		img_wall;
	t_img		img_collect;
	t_img		img_exit;
	t_img		img_enemy;
	t_img		img_empty;
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

typedef struct s_anim
{
	t_list		*frames;
	long int	last_updated;
	int			currentframe;
}	t_anim;

typedef struct s_game
{
	t_win	win;
	t_map	map;
	t_pos	p_old;
	t_pos	p_new;
	t_pos	exit;
	t_pos	enemy;
	t_list	**imgseq;
	t_list	**v;
	t_list	**q;
	t_img	gameimg;
	t_anim	a_player;
	t_anim	a_exit;
	t_anim	a_rwalk;
	t_anim	a_lwalk;
	t_anim	a_uwalk;
	t_anim	a_dwalk;
	t_anim	a_enemymove;
	t_anim	a_enemy;
	t_anim	a_lose;
	t_anim	a_win;
}	t_game;

//parse map functions
t_map		parsemap(char *map);
void		countelements(char a, t_map *map_dets);
void		initmapdets(t_map *dets);
size_t		ft_strlen2(const char *a);
void		validpath(char **array, t_map *map_dets, t_game *game);
void		checkfile(char *map);
void		checkfd(int a);
int			checkelements(char a);
int			checkele(char **array, size_t x, size_t y, t_map *dets);
int			checkpos(int x, int y, t_list *v, t_list *q);

//initializing the display and images
void		initgame(t_game *game);
void		initemptyimg(t_game *game);
void		setimgsnull(t_game *game);

//create images functions
void		newimg_xpm(char *path, t_img *img, t_game game);

//hook events
void		hookevents(t_game game);

//escaping window functions
int			closescreenesc(int key, t_game *game);
int			closescreencross(t_game *game);

//minimize window function
int			maxwindow(t_game *game);

//movement functions
int			movement(int key, t_game *game);
void		updatecoords(t_game *game, int *x, int *y, int key);

//draw functions
void		drawimg(t_img *img, t_map map, int x, int y);
void		layerimg(t_img src, t_img *dst, int x, int y);

//end functions
int			end(t_game *game);

//animations
void		initanimations(t_game *game);
void		initanim(t_game *game, t_anim *anim, int frames);
void		execanimation(t_anim *anim, int x, int y, t_game game);
void		execpanim(t_anim *anim, int x, int y, t_game game);
int			loopevents(t_game *game);
void		initexit(t_game *game);
long int	gettime(void);
void		updateframe(t_anim *anim, int x, int y, t_game game);
void		assignplayerimg(t_game *game);
void		assignimgexit(t_game *game);
void		execanim(t_anim *anim, int x, int y, t_game game);
void		assignimgrwalk(t_game *game);
void		assignimglwalk(t_game *game);
void		assignimguwalk(t_game *game);
void		assignimgdwalk(t_game *game);
void		layerbackground(t_game *game, t_img img_n, t_img img_o);
void		updatecollectible(t_game *game);
void		renderdown(char a, t_game *game, t_img img_n, t_img img_o);
void		renderup(char a, t_game *game, t_img img_n, t_img img_o);
void		renderleft(char a, t_game *game, t_img img_n, t_img img_o);
void		renderright(char a, t_game *game, t_img img_n, t_img img_o);
void		assignemovanim(t_game *game);
void		enemymove(t_game *game);
void		enemyidle(t_game *game, int x, int y);
void		assignloseimg(t_game *game);
void		loseanim(t_game *game);
void		assignwinimg(t_game *game);
void		winanim(t_game *game);

//clearing functions
void		cleararray(char **array, int size);
void		maperror(char **array, int size, t_list **q, t_list **v);
void		clear(t_list **head);
void		clearimgs(t_list *head, t_win win);
void		clearsprites(t_map map, t_win win);
void		clearassets(t_game game);
void		failedgame(t_game game);
void		del(void *content);

//enemy
void		initenemy(t_game *game);
void		enemycoords(t_game *game, size_t *x, size_t *y);

//counter
void		movementcount(int movement, t_game *game);

#endif
