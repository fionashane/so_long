/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:50:15 by fsalimba          #+#    #+#             */
/*   Updated: 2023/11/28 13:50:15 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Moves the player down if possible.
 * 
 * @param game The game structure.
 */
void	move_down(t_game *game)
{
	if (!is_wall_element(game->player_x, game->player_y + 1, game))
	{
		game->moves++;
		game->player_y++;
		ft_printf("Moves: %d\n", game->moves);
	}
}

/**
 * @brief Moves the player up if possible.
 * 
 * @param game The game structure.
 */
void	move_up(t_game *game)
{
	if (!is_wall_element(game->player_x, game->player_y - 1, game))
	{
		game->moves++;
		game->player_y--;
		ft_printf("Moves: %d\n", game->moves);
	}
}

/**
 * @brief Moves the player left if possible.
 * 
 * @param game The game structure.
 */
void	move_left(t_game *game)
{
	if (!is_wall_element(game->player_x - 1, game->player_y, game))
	{
		game->moves++;
		game->player_x--;
		ft_printf("Moves: %d\n", game->moves);
	}
}

/**
 * @brief Moves the player right if possible.
 * 
 * @param game The game structure.
 */
void	move_right(t_game *game)
{
	if (!is_wall_element(game->player_x + 1, game->player_y, game))
	{
		game->moves++;
		game->player_x++;
		ft_printf("Moves: %d\n", game->moves);
	}
}
