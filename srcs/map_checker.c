/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:41:20 by fsalimba          #+#    #+#             */
/*   Updated: 2023/11/28 13:41:20 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Checks for errors in the map and exits the program if errors are found.
 *
 * @param game Pointer to the game structure.
 */
void	check_map_error(t_game *game)
{
	if (!is_valid_map_char(game->grid))
		print_and_exit("Error: Invalid Characters in Map\n", 1);
	if (!has_consistent_map_shape(game->grid))
		print_and_exit("Error: Inconsistent Map Shape\n", 1);
	if (!has_map_walls(game))
		print_and_exit("Error: Invalid Map Walls\n", 1);
}

/**
 * @brief Checks if all characters in the map are valid.
 *
 * @param grid The map grid.
 * @return 1 if all characters are valid, 0 otherwise.
 */
int	is_valid_map_char(char **grid)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (grid[i])
	{
		while (grid[i][j])
		{
			if (is_valid_char(grid[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

/**
 * @brief Checks if a character is a valid map character.
 *
 * @param c The character to check.
 * @return 1 if valid, 0 otherwise.
 */
int	is_valid_char(char c)
{
	return (c != '1' && c != '0' && c != 'C' && c != 'P' && c != 'E');
}

/**
 * @brief Checks if the map has a consistent rectangular shape.
 *
 * @param grid The map grid.
 * @return 1 if the map has a consistent shape, 0 otherwise.
 */
int	has_consistent_map_shape(char **grid)
{
	size_t	first_line;
	int		i;

	i = 1;
	first_line = ft_strlen(grid[0]);
	while (grid[i])
	{
		if (ft_strlen(grid[i]) != first_line)
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Checks if the map has walls around the borders.
 *
 * @param game Pointer to the game structure.
 * @return 1 if the map has walls, 0 otherwise.
 */
int	has_map_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->grid_width)
		if (game->grid[0][i++] != '1')
			return (0);
	i = 0;
	while (i < game->grid_width)
		if (game->grid[game->grid_height - 1][i++] != '1')
			return (0);
	i = 0;
	while (i < game->grid_height)
		if (game->grid[i++][0] != '1')
			return (0);
	i = 0;
	while (i < game->grid_height)
		if (game->grid[i++][game->grid_width - 1] != '1')
			return (0);
	return (1);
}
