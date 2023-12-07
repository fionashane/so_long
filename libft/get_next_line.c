/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:26:23 by fsalimba          #+#    #+#             */
/*   Updated: 2023/05/11 13:32:57 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_errors(int fd)
{
	return (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0);
}

static char	*ft_extract_chars(char *line)
{
	size_t	i;
	char	*stash;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (0);
	stash = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*stash == '\0')
	{
		free(stash);
		stash = NULL;
	}
	line[i + 1] = '\0';
	return (stash);
}

static char	*ft_gen_line(int fd, char *aux, char *stash)
{
	int		bytes_read;
	char	*temp_stash;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, aux, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
		else if (bytes_read == 0)
			break ;
		aux[bytes_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp_stash = stash;
		stash = ft_strjoin(temp_stash, aux);
		free(temp_stash);
		temp_stash = NULL;
		if (ft_strchr (aux, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*aux;
	char		*line;
	static char	*stash;

	if (ft_check_errors(fd))
	{
		if (stash)
			free(stash);
		return (stash = 0);
	}
	aux = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!aux)
		return (0);
	line = ft_gen_line(fd, aux, stash);
	free(aux);
	aux = NULL;
	if (!line)
		return (NULL);
	stash = ft_extract_chars(line);
	return (line);
}
