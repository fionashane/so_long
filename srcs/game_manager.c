/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:57:52 by fsalimba          #+#    #+#             */
/*   Updated: 2023/11/28 12:57:52 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Initializes the game and handles user input.
 *
 * Entry point for the program, sets up the game.
 * Registers event handlers for keypress and window close.
 *
 * @param ac Number of command-line arguments.
 * @param av Array of command-line arguments.
 * @return 0 on success, 1 on failure.
 */
int	main(int ac, char **av)
{
	t_game	*game;

	if (ac == 2)
	{
		game = malloc(sizeof(t_game));
		if (!game)
			print_and_exit("Error: Memory allocation for struct\n", 1);
		init_game_struct(game);
		setup_game(av[1], game);
		mlx_hook(game->window, 2, 1L << 0, handle_keypress_event, game);
		mlx_hook(game->window, 17, 1L << 17, handle_window_close, NULL);
		mlx_loop_hook(game->mlx, render_game, game);
		mlx_loop(game->mlx);
	}
	else
		print_and_exit("Error: No map added\n", 1);
}

/**
 * @brief Initialises the game structure with default values and loads
 *        sprites for the space, exit, character, collectible, and wall.
 *
 * @param game Pointer to the game structure.
 */
void	init_game_struct(t_game *game)
{
	game->grid = NULL;
	game->grid_copy = NULL;
	game->grid_width = 0;
	game->grid_height = 0;
	game->mlx = mlx_init();
	game->pixels = 32;
	game->moves = 0;
	game->player_x = -1;
	game->player_y = -1;
	game->window = NULL;
	game->exit_x = -1;
	game->exit_y = -1;
	game->exit_count = 0;
	game->exit_count_copy = 0;
	game->space_sprite = read_sprite("img/space.xpm", game);
	game->exit_sprite = read_sprite("img/exit.xpm", game);
	game->character_sprite = read_sprite("img/character.xpm", game);
	game->collect_sprite = read_sprite("img/collectible.xpm", game);
	game->wall_sprite = read_sprite("img/wall.xpm", game);
	game->collectible_coordinates = NULL;
	game->collectible_count = 0;
	game->collectible_count_copy = 0;
	game->wall_coordinates = NULL;
}

/**
 * @brief Sets up the game environment, including allocating memory,
 *        loading the map, creating the game window, and initialising
 *        various game-related parameters.
 *
 * @param map A string representing the path to the map file.
 * @param game Pointer to the game structure.
 */
void	setup_game(char *map, t_game *game)
{
	malloc_game_grid(game);
	load_map(map, game);
	create_game_copy(game);
	create_game_window("Panda Day", game);
	find_character_pos(game);
	count_exit_and_collectibles(game);
	check_exit_and_collectibles_count(game);
	malloc_wall_coordinates(game);
	malloc_collectible_coordinates(game);
	set_wall_coordinates(game);
	set_collectible_coordinates(game);
	check_map_error(game);
	find_exit_coordinates(game);
}

/**
 * @brief Renders the game, updating the window and sprites.
 * 
 * @param game The game structure.
 * @return int Always returns 0.
 */
int	render_game(t_game *game)
{
	check_win_condition(game);
	update_collectibles(game);
	mlx_clear_window(game->mlx, game->window);
	draw_wall_element(game->wall_sprite, game);
	draw_space_element(game->space_sprite, game);
	draw_exit_element(game->exit_sprite, game);
	draw_collectible_element(game->collect_sprite, game);
	draw_character_element(game->character_sprite, game);
	return (0);
}
