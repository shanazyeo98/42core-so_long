CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = so_long
BONUSNAME = so_long_bonus
SRCS_TEST = main.c
SRCS = srcs/errors_game.c \
srcs/errors_map.c \
srcs/event_move.c \
srcs/events.c \
srcs/map_display.c \
srcs/map_draw.c \
srcs/map_validation.c \
srcs/map_validation2.c \
srcs/map_validpath.c \
srcs/map_validpathchecks.c \
srcs/so_long.c
BONUS_SRCS = bonus/animation_bonus.c \
bonus/animation_ending_bonus.c \
bonus/animation_idle_bonus.c \
bonus/animation_init_bonus.c \
bonus/animation_walk_bonus.c \
bonus/animation_walk2_bonus.c \
bonus/enemy_bonus.c \
bonus/enemy_bonus2.c \
bonus/errors_game_bonus.c \
bonus/errors_map_bonus.c \
bonus/event_loop_bonus.c \
bonus/event_move_bonus.c \
bonus/event_move2_bonus.c \
bonus/events_bonus.c \
bonus/map_display_bonus.c \
bonus/map_draw_bonus.c \
bonus/map_emptyimage_bonus.c \
bonus/map_initimgs_bonus.c \
bonus/map_validation_bonus.c \
bonus/map_validation2_bonus.c \
bonus/map_validpath_bonus.c \
bonus/map_validpathchecks_bonus.c \
bonus/so_long_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
LIBFTDIR = libft
MINILIBXDIR = minilibx-linux
MLXURL = https://github.com/42Paris/minilibx-linux.git
LIBFT = libft.a
MINILIBX = libmlx.a
LINUX_FLAGS = -lX11 -lXext -lm libft.a libmlx.a
MAC_FLAGS = libmlx.a libft.a -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
HEADERS = srcs/so_long.h
HEADERS_BONUS = bonus/so_long_bonus.h

all: $(NAME)

bonus: $(BONUSNAME)

$(NAME): $(MINILIBX) $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(MAC_FLAGS) -o $(NAME)

$(BONUSNAME): $(MINILIBX) $(LIBFT) $(BONUS_OBJS)
	$(CC) $(FLAGS) $(BONUS_OBJS) $(MAC_FLAGS) -o $(BONUSNAME)

$(LIBFT):
	make bonus -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) $(LIBFT)

$(MINILIBX):
	rm -rf $(MINILIBXDIR)
	echo "Getting Minilibx library!"
	git clone $(MLXURL) $(MINILIBXDIR)
	make -C $(MINILIBXDIR)
	cp $(MINILIBXDIR)/$(MINILIBX) $(MINILIBX)

srcs/%.o: srcs/%.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@ -I/opt/X11/include -I$(MINILIBXDIR)

bonus/%.o: bonus/%.c $(HEADERS_BONUS)
	$(CC) $(FLAGS) -c $< -o $@ -I/opt/X11/include -I$(MINILIBXDIR)

clean:
	make clean -C ./$(LIBFTDIR)
	make clean -C ./$(MINILIBXDIR)
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	make fclean -C ./libft
	rm -rf $(MINILIBXDIR)
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(MINILIBX)
	rm -f $(BONUSNAME)

re: fclean all

.PHONY: all clean fclean re
