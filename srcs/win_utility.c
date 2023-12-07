/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:03:02 by fsalimba          #+#    #+#             */
/*   Updated: 2023/12/05 11:03:10 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Checks if there are collectibles left in the game.
 * 
 * @param game The game structure.
 * @return int Returns 1 if there are collectibles, 0 otherwise.
 */
int	no_collectibles_left(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->grid[i])
	{
		j = 0;
		while (game->grid[i][j])
		{
			if (game->grid[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Checks if the player is at the exit position.
 *
 * @param game Pointer to the game structure.
 * @return 1 if the player is at the exit, 0 otherwise.
 */
int	player_at_exit(t_game *game)
{
	return (game->player_x == game->exit_x
		&& game->player_y == game->exit_y);
}

/**
 * @brief Checks and marks the path in the game copy grid
 * starting from the specified position.
 * 
 * @param paint The character to paint the path with.
 * @param y The starting row index.
 * @param x The starting column index.
 * @param game Pointer to the game structure.
 */
void	check_and_mark_path(char paint, int y, int x, t_game *game)
{
	if (y < 0 || y >= game->grid_height || x < 0 || x >= game->grid_width)
		return ;
	if (game->grid_copy[y][x] == '1')
		return ;
	else if (game->grid_copy[y][x] == '0' || game->grid_copy[y][x] == 'P'
			|| game->grid_copy[y][x] == 'C' || game->grid_copy[y][x] == 'E')
	{
		if (game->grid_copy[y][x] == 'C')
			game->collectible_count_copy++;
		else if (game->grid_copy[y][x] == 'E')
			game->exit_count_copy++;
		game->grid_copy[y][x] = paint;
		check_and_mark_path(paint, y, x + 1, game);
		check_and_mark_path(paint, y, x - 1, game);
		check_and_mark_path(paint, y + 1, x, game);
		check_and_mark_path(paint, y - 1, x, game);
	}
}

/**
 * @brief Prints a message before exiting the game
 * 
 * @param message The message to print.
 * @param error The integer to pass exit().
 */
void	print_and_exit(char *message, int error)
{
	ft_printf(message);
	exit(error);
}
