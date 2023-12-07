/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:05:42 by fsalimba          #+#    #+#             */
/*   Updated: 2023/11/28 13:05:42 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Loads the map from the specified file into the game structure.
 *
 * @param filename The path to the map file.
 * @param game Pointer to the game structure.
 */
void	load_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_and_exit("Error: Failed to open file\n", 1);
	line = get_next_line(fd);
	load_map_while_loop(fd, line, game);
	game->grid[game->grid_height] = NULL;
	close(fd);
}

/**
 * @brief Helper function for loading the map line by line.
 *
 * @param fd The file descriptor for the map file.
 * @param line The current line being processed.
 * @param game Pointer to the game structure.
 */
void	load_map_while_loop(int fd, char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line != NULL)
	{
		game->grid_width = ft_strlen(line);
		if (ft_strchr(line, '\n'))
			game->grid[i] = ft_strndup(line, game->grid_width - 1);
		else
			game->grid[i] = ft_strndup(line, game->grid_width);
		game->grid_height++;
		free(line);
		line = get_next_line(fd);
		i++;
	}
}
