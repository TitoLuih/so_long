/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:35:12 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/02/11 15:27:01 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
}

static int	read_column(char *line, t_game *game, int fd, char *map_name)
{
	int	index;

	index = 0;
	fd = open(map_name, 0);
	line = get_next_line(fd);
	if (index < game->lines)
	{
		game->columns = ft_strlen(line);
		if (line[game->columns - 1] != " \n")
			game->columns++;
		game->map[index] = ft_calloc(game->columns, sizeof(char *));
		game->map_copy[index] = ft_calloc(game->columns, sizeof(char *));
		if (!game->map || !game->map_copy)
			return (free(line), EXIT_FAILURE);
		ft_strlcpy(game->map[index], line, game->columns);
		ft_strlcpy(game->map_copy[index], line, game->columns);
		free(line);
		line = get_next_line(fd);
		index++;
	}
	game->columns--;
	game->map[index] = NULL;
	game->map_copy[index] = NULL;
	return (close(fd), free(line), EXIT_SUCCESS);
}

static int	read_lines(char *line, t_game *game, int fd, char *map_name)
{
	fd = open(map_name, 0);
	line = get_next_line(fd);
	if (line == NULL)
		return (ft_printf("Fallo al leer el mapa"), EXIT_FAILURE);
	while (line != NULL)
	{
		game->lines++;
		free(line);
		line = get_next_line(fd);
	}
	game->map = ft_calloc (game->lines + 1, sizeof(char *));
	game->map_copy = ft_calloc (game->lines + 1, sizeof(char *));
	if (!game->map || game->map_copy)
		return (free(line), EXIT_FAILURE);
	close(fd);
	if (read_column(line, game, fd, map_name) == 1)
		return (free(line), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	read_map(t_game *game, char *map_name)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(map_name, 0);
	if (fd < 0)
		return (ft_printf("Error, no se pudo leer el mapa\n"), EXIT_FAILURE);
	close (fd);
	if (read_line(line, game, fd, map_name) == 1)
		return (free(line), EXIT_FAILURE);
}
