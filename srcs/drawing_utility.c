/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:46:02 by fsalimba          #+#    #+#             */
/*   Updated: 2023/11/28 13:46:02 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Reads a sprite from the given filename using mlx_png_file_to_image.
 *
 * @param filename The path to the sprite image file.
 * @param game Pointer to the game structure.
 * @return A pointer to the loaded sprite.
 */
void	*read_sprite(char *filename, t_game *game)
{
	int	p;

	p = game->pixels;
	return (mlx_xpm_file_to_image(game->mlx, filename, &p, &p));
}

/**
 * @brief Creates a new window for the game with the specified name.
 *
 * @param game_name The name of the game.
 * @param game Pointer to the game structure.
 */
void	create_game_window(char *game_name, t_game *game)
{
	int	x;
	int	y;

	x = game->grid_width * game->pixels;
	y = game->grid_height * game->pixels;
	game->window = mlx_new_window(game->mlx, x, y, game_name);
}

/**
 * @brief Draws the specified image at the given coordinates in the game window.
 *
 * @param img_ptr The image pointer.
 * @param j The column index.
 * @param i The row index.
 * @param game Pointer to the game structure.
 */
void	draw_to_window(void *img_ptr, int j, int i, t_game *game)
{
	void	*m;
	void	*w;
	int		p;

	m = game->mlx;
	w = game->window;
	p = game->pixels;
	mlx_put_image_to_window(m, w, img_ptr, j * p, i * p);
}

/**
 * @brief Checks if the given character represents a space element.
 * 
 * @param element The character to check.
 * @return 1 if the character represents a space element, 0 otherwise.
 */
int	is_space_element(char element)
{
	return (element == '0' || element == 'C'
		|| element == 'E' || element == 'P');
}
