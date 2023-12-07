/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:34:49 by fsalimba          #+#    #+#             */
/*   Updated: 2023/12/01 10:34:54 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define MAX_HEIGHT_MAP 25
# define UP_KEY 13
# define DOWN_KEY 1
# define LEFT_KEY 0
# define RIGHT_KEY 2
# define ESC_KEY 53

typedef struct s_game
{
	char	**grid;
	char	**grid_copy;
	int		grid_width;
	int		grid_height;
	void	*mlx;
	int		pixels;
	int		moves;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		exit_count;
	int		exit_count_copy;
	void	*window;
	void	*character_sprite;
	void	*space_sprite;
	void	*wall_sprite;
	void	*collect_sprite;
	void	*exit_sprite;
	int		**collectible_coordinates;
	int		collectible_count;
	int		collectible_count_copy;
	int		**wall_coordinates;
}		t_game;

/* GAME MANAGER */
void	init_game_struct(t_game *game);
void	setup_game(char *map, t_game *game);
int		render_game(t_game *game);

/* EVENT HANDLER */
int		handle_keypress_event(int keycode, t_game *game);
int		handle_window_close(void);

/* MAP LOADER */
void	load_map(char *filename, t_game *game);
void	load_map_while_loop(int fd, char *line, t_game *game);

/* WIN HANDLER */
void	find_exit_coordinates(t_game *game);
void	check_win_condition(t_game *game);
void	check_exit_and_collectibles_count(t_game *game);
void	create_game_copy(t_game *game);

/* FLOOR ORGANISER */
void	find_character_pos(t_game *game);
void	set_collectible_coordinates(t_game *game);
void	update_collectibles(t_game *game);
void	player_at_collectible(t_game *game, int i);
void	count_exit_and_collectibles(t_game *game);

/* WALL ORGANISER */
void	set_wall_coordinates(t_game *game);
int		total_wall_elements(t_game *game);
int		is_wall_element(int x, int y, t_game *game);

/* MAP CHECKER */
void	check_map_error(t_game *game);
int		is_valid_map_char(char **grid);
int		is_valid_char(char c);
int		has_consistent_map_shape(char **grid);
int		has_map_walls(t_game *game);

/* DRAWING ENGINE */
void	draw_space_element(void *space_img, t_game *game);
void	draw_character_element(void *character_img, t_game *game);
void	draw_exit_element(void *exit_img, t_game *game);
void	draw_collectible_element(void *collectible_img, t_game *game);
void	draw_wall_element(void *wall_img, t_game *game);

/* DRAWING UTILITY */
void	*read_sprite(char *filename, t_game *game);
void	create_game_window(char *game_name, t_game *game);
void	draw_to_window(void *img_ptr, int j, int i, t_game *game);
int		is_space_element(char element);

/* MALLOC UTILITY */
void	malloc_game_grid(t_game *game);
void	malloc_wall_coordinates(t_game *game);
void	malloc_collectible_coordinates(t_game *game);

/* KEYPRESS UTILITY */
void	move_down(t_game *game);
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

/* WIN UTILITY */
int		no_collectibles_left(t_game *game);
int		player_at_exit(t_game *game);
void	check_and_mark_path(char paint, int y, int x, t_game *game);
void	display_win_message(void);
void	print_and_exit(char *message, int error);

#endif
