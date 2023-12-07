/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:25:20 by fsalimba          #+#    #+#             */
/*   Updated: 2023/11/28 13:25:20 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Finds and sets the exit coordinates in the game structure.
 *
 * @param game Pointer to the game structure.
 */
void	find_exit_coordinates(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->grid[i])
	{
		while (game->grid[i][j])
		{
			if (game->grid[i][j] == 'E')
			{
				game->exit_x = j;
				game->exit_y = i;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

/**
 * @brief Checks if the player has won the game.
 * 
 * @param game The game structure.
 */
void	check_win_condition(t_game *game)
{
	if (player_at_exit(game) && no_collectibles_left(game))
		print_and_exit("Thank You! You helped Panda sleep!\n", 0);
}

/**
 * @brief Checks if the count of exits and collectibles matches
 * the count in the copy, indicating a valid map path.
 *
 * @param game Pointer to the game structure.
 */
void	check_exit_and_collectibles_count(t_game *game)
{
	check_and_mark_path('F', game->player_y, game->player_x, game);
	if (game->collectible_count_copy != game->collectible_count
		|| game->exit_count_copy != game->exit_count)
		print_and_exit("Error: Map has no valid path\n", 1);
	else
		ft_printf("Map has valid path\n");
}

/**
 * @brief Creates a copy of the input grid and assigns it to the output grid.
 *
 * @param in The input grid to be copied.
 * @param out Pointer to the output grid where the copy will be stored.
 */
void	create_game_copy(t_game *game)
{
	int	i;
	int	grid_len;

	i = 0;
	grid_len = ft_lstlen(game->grid) + 1;
	game->grid_copy = (char **)malloc(sizeof(char *) * (grid_len));
	if (!game->grid_copy)
		return ;
	while (game->grid[i])
	{
		game->grid_copy[i] = ft_strdup(game->grid[i]);
		i++;
	}
	game->grid_copy[i] = NULL;
}
