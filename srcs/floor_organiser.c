/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_organiser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:35:56 by fsalimba          #+#    #+#             */
/*   Updated: 2023/11/28 13:35:56 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Finds and sets the position of the character 'P' in the game grid.
 *
 * @param game Pointer to the game structure.
 */
void	find_character_pos(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (game->grid[i])
	{
		while (game->grid[i][j])
		{
			if (game->grid[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				count++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (count != 1)
		print_and_exit("Error: Map should have 1 starting position\n", 1);
}

/**
 * @brief Updates the game grid when a collectible is picked up.
 * 
 * @param game The game structure.
 */
void	update_collectibles(t_game *game)
{
	int	i;

	i = 0;
	while (game->collectible_coordinates[i] != NULL)
	{
		player_at_collectible(game, i);
		i++;
	}
}

/**
 * @brief Checks if the player is at a collectible
 * position and updates the game grid.
 *
 * @param game Pointer to the game structure.
 * @param i Index of the collectible in the collectible coordinates array.
 */
void	player_at_collectible(t_game *game, int i)
{
	if (game->collectible_coordinates[i][0] == game->player_x
		&& game->collectible_coordinates[i][1] == game->player_y)
		game->grid[game->player_y][game->player_x] = '0';
}

/**
 * @brief Sets the coordinates of collectibles in the game structure.
 *
 * @param game Pointer to the game structure.
 */
void	set_collectible_coordinates(t_game *game)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (game->grid[i])
	{
		j = 0;
		while (game->grid[i][j])
		{
			if (game->grid[i][j] == 'C')
			{
				game->collectible_coordinates[c] = (int *)malloc
					(sizeof(int) * 2);
				game->collectible_coordinates[c][0] = j;
				game->collectible_coordinates[c][1] = i;
				c++;
			}
			j++;
		}
		i++;
	}
	game->collectible_coordinates[c] = NULL;
}

/**
 * @brief Counts the number of 'E' (exit) and
 * 'C' (collectible) elements in the game grid.
 *
 * @param game Pointer to the game structure.
 */
void	count_exit_and_collectibles(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (game->grid[i])
	{
		while (game->grid[i][j])
		{
			if (game->grid[i][j] == 'E')
				game->exit_count++;
			if (game->grid[i][j] == 'C')
				game->collectible_count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (game->exit_count != 1)
		print_and_exit("Error: Map should have 1 exit\n", 1);
}
