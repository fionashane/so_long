/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:03:22 by fsalimba          #+#    #+#             */
/*   Updated: 2023/11/28 13:03:22 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Handles key presses, including movement and exit.
 * 
 * @param keycode The keycode corresponding to the pressed key.
 * @param game The game structure.
 * @return int Always returns 0.
 */
int	handle_keypress_event(int keycode, t_game *game)
{
	if (keycode == UP_KEY)
		move_up(game);
	else if (keycode == DOWN_KEY)
		move_down(game);
	else if (keycode == LEFT_KEY)
		move_left(game);
	else if (keycode == RIGHT_KEY)
		move_right(game);
	else if (keycode == ESC_KEY)
		handle_window_close();
	return (0);
}

/**
 * @brief Handles the window close event.
 * 
 * @param game The game structure.
 * @return int Always returns 0.
 */
int	handle_window_close(void)
{
	ft_printf("Exited Game\n");
	exit(1);
}
