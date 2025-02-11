/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:35:12 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/02/11 13:00:07 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(t_game *game)
{
	
}

static int read_column(char *line, t_game *game, int fd, char *map_name)
{
	
}

static int read_lines(char *line, t_game *game, int fd, char *map_name)
{
	fd = open(map_name, 0);
	line = get_next_line(fd);
	if (line == NULL)
		return(ft_printf("Fallo al leer el mapa"), EXIT_FAILURE);
	while (line != NULL)
	{
		game->lines++;
		free(line);
		line = get_next_line(fd);
	}
	
}

int read_map(t_game *game, char *map_name)
{
	int	fd;
	char *line;
	
	line = NULL;
	fd = open(map_name, 0);
	if (fd < 0)
		return (ft_printf("Error, no se pudo leer el mapa\n"), EXIT_FAILURE);
	close (fd);
	
}

/*
	hay que leer el mapa y copiarlo en map y en map_copy
	leerlo por lineas y por columna
*/