/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:01:26 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/02/20 15:30:41 by lruiz-to         ###   ########.fr       */
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

int	check_wall(t_game *game, int i, int j)
{
	while (j < game->lines - 1)
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
			else if (game->map[j][i] != '0' && game->map[j][i] != '1'
				&& game->map[j][i] != 'C' && game->map[j][i] != 'P'
				&& game->map[j][i] != 'E')
				return (EXIT_FAILURE);
			else
				object_checker(game, i, j);
		i++;
	}
	if (game->player != 1 || game->exit != 1 || game->coin == 0)
		return (ft_printf("Numero de objetos invalido"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	object_checker(t_game *game, int i, int j)
{
	if (game->map[j][i] == 'C')
		game->coin++;
	else if (game->map[j][i] == 'P')
	{
		game->p_position.x = i;
		game->p_position.y = j;
		game->player++;
	}
	else if (game->map[j][i] == 'E')
	{
		game->e_position.x = i;
		game->e_position.y = j;
		game->exit++;
	}
}

int	way_checker(t_game *game)
{
	int	x;
	int	y;

	x = game->p_position.x;
	y = game->p_position.y;
	if (game->map[x + 1][y] == '1' || game->map[x - 1][y] == '1'
	|| game->map[x][y + 1] == '1' || game->map[x][y - 1] == '1' )
		return (EXIT_FAILURE);
	else
	{
		x = game->e_position.x;
		y = game->e_position.y;
		if (game->map[x + 1][y] == '1' || game->map[x - 1][y] == '1'
			|| game->map[x][y + 1] == '1' || game->map[x][y - 1] == '1' )
				return (EXIT_FAILURE);
		else
			return (EXIT_SUCCESS);
	}
}

int	map_checker(t_game *game)
{
	if (game-> lines != game->columns)
		return (ft_printf ("Error, the map is not rectangular"), EXIT_FAILURE);
	if (check_wall(game, 0, 1) == 1)
		return (EXIT_FAILURE);

}
