/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:48:02 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/02/25 18:30:40 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	image_to_window(t_game *g)
{
	int	i;
	int	j;

	j = 0;
	while (g->map[j] != NULL)
	{
		i = 0;
		while (g->map[j][i] != '\n' && g->map[j][i] != '\0')
		{
			mlx_image_to_window (g->mlx, g->i_floor, i * 50, j * 50);
			if (g->map[j][i] == '1')
				mlx_image_to_window (g->mlx, g->i_wall, i * 50, j * 50);
			if (g->map[j][i] == 'C')
				mlx_image_to_window (g->mlx, g->i_coin, i * 50, j * 50);
			if (g->map[j][i] == 'P')
				mlx_image_to_window (g->mlx, g->i_player_r, i * 50, j * 50);
			if (g->map[j][i] == 'E')
				mlx_image_to_window (g->mlx, g->i_closed_exit, i * 50, j * 50);
			i++;
		}
		j++;
	}
	return (EXIT_SUCCESS);
}