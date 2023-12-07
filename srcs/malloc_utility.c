/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:48:19 by fsalimba          #+#    #+#             */
/*   Updated: 2023/11/28 13:48:19 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Allocates memory for the game grid.
 *
 * @param game Pointer to the game structure.
 */
void	malloc_game_grid(t_game *game)
{
	game->grid = (char **)malloc(sizeof(char *) * MAX_HEIGHT_MAP);
	if (!game->grid)
		print_and_exit("Error: Malloc for game grid\n", 1);
}

/**
 * @brief Allocates memory for the wall coordinates array in the game structure.
 *
 * @param game Pointer to the game structure.
 */
void	malloc_wall_coordinates(t_game *game)
{
	int	wall_count;

	wall_count = total_wall_elements(game) + 1;
	game->wall_coordinates = (int **)malloc(sizeof(int *) * (wall_count));
	if (!game->wall_coordinates)
		print_and_exit("Error: Malloc for wall coordinates\n", 1);
}

/**
 * @brief Allocates memory for the collectible coordinates
 * array in the game structure.
 * 
 * @param game Pointer to the game structure.
 */
void	malloc_collectible_coordinates(t_game *game)
{
	game->collectible_coordinates = (int **)malloc(sizeof(int *)
			* (game->collectible_count + 1));
	if (!game->collectible_coordinates)
		print_and_exit("Error: Malloc for collectible coordinates\n", 1);
}
