/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:43:18 by fsalimba          #+#    #+#             */
/*   Updated: 2023/11/28 13:43:18 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Draws the space elements on the window.
 * 
 * @param space_img Pointer to the space image.
 * @param game The game structure.
 */
void	draw_space_element(void *space_img, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->grid[i])
	{
		j = 0;
		while (game->grid[i][j])
		{
			if (is_space_element(game->grid[i][j]))
				draw_to_window(space_img, j, i, game);
			j++;
		}
		i++;
	}
}

/**
 * @brief Draws the character on the window.
 * 
 * @param character_img Pointer to the character image.
 * @param game The game structure.
 */
void	draw_character_element(void *character_img, t_game *game)
{
	draw_to_window(character_img, game->player_x, game->player_y, game);
}

/**
 * @brief Draws the exit on the window.
 * 
 * @param exit_img Pointer to the exit image.
 * @param game The game structure.
 */
void	draw_exit_element(void *exit_img, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->grid[i])
	{
		j = 0;
		while (game->grid[i][j])
		{
			if (game->grid[i][j] == 'E')
				draw_to_window(exit_img, j, i, game);
			j++;
		}
		i++;
	}
}

/**
 * @brief Draws the collectible on the window.
 * 
 * @param collectible_img Pointer to the collectible image.
 * @param game The game structure.
 */
void	draw_collectible_element(void *collectible_img, t_game *game)
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
				draw_to_window(collectible_img, j, i, game);
			j++;
		}
		i++;
	}
}

/**
 * @brief Draws the wall on the window.
 * 
 * @param wall_img Pointer to the wall image.
 * @param game The game structure.
 */
void	draw_wall_element(void *wall_img, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->grid[i])
	{
		j = 0;
		while (game->grid[i][j])
		{
			if (game->grid[i][j] == '1')
				draw_to_window(wall_img, j, i, game);
			j++;
		}
		i++;
	}
}
