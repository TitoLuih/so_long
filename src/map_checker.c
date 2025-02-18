/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:01:26 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/02/18 18:21:33 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ext_checker(char *map_name)
{
	int	i;

	i = ft_strlen(map_name);
	if ((map_name[i - 1] == 'r' && map_name[i - 2] == 'e')
		&& (map_name[i - 3] == 'b' && map_name[i - 4] == '.'))
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	check_wall(t_game *game)
{
	int i;
	int	j;
	
	i = 0;
	j = 0;
	while (j < game->lines)
	{	
		if (game->map[j][i] == "\n")
		{
			i = 0;
			j++;
		}
		if (j == 0 || j == game->lines - 1)
			if (game->map[j][i] != '1' && game->map[j][i] != "\n")
				return (EXIT_FAILURE);
		else
			if (game->map[j][0] != '1' && game->map[j][game->columns -1] != '1')
				return (EXIT_FAILURE);
		i++;		
	}
}

int map_checker (t_game *game)
{
}
