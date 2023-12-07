/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_organiser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:51:28 by fsalimba          #+#    #+#             */
/*   Updated: 2023/11/28 13:51:28 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Sets the wall coordinates in the game structure
 * based on the positions of '1' in the grid.
 * 
 * @param game Pointer to the game structure.
 */
void	set_wall_coordinates(t_game *game)
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
			if (game->grid[i][j] == '1')
			{
				game->wall_coordinates[c] = (int *)malloc(sizeof(int) * 2);
				game->wall_coordinates[c][0] = j;
				game->wall_coordinates[c][1] = i;
				c++;
			}
			j++;
		}
		i++;
	}
	game->wall_coordinates[c] = NULL;
}

/**
 * @brief Counts the number of walls in the game grid.
 *
 * @param game Pointer to the game structure.
 * @return The count of walls.
 */
int	total_wall_elements(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->grid[i])
	{
		j = 0;
		while (game->grid[i][j])
		{
			if (game->grid[i][j] == '1')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

/**
 * @brief Checks if the given position is a wall.
 * 
 * @param x The x-coordinate.
 * @param y The y-coordinate.
 * @param game The game structure.
 * @return int Returns 1 if the position is a wall, 0 otherwise.
 */
int	is_wall_element(int x, int y, t_game *game)
{
	int	i;

	i = total_wall_elements(game) - 1;
	while (i >= 0)
	{
		if (x == game->wall_coordinates[i][0]
			&& y == game->wall_coordinates[i][1])
			return (1);
		i--;
	}
	return (0);
}
