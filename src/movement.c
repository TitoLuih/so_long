/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:21:05 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/03/13 17:55:20 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	images(t_game *g, int x, int y, void *img)
{
	if (g->map[g->p_position.y][g->p_position.x] == 'E')
	{
		mlx_image_to_window(g->mlx, g->i_floor, g->p_position.x * 64,
			g->p_position.y * 64);
		mlx_image_to_window(g->mlx, g->i_c_exit, g->p_position.x * 64,
			g->p_position.y * 64);
	}
	if (g->map[g->p_position.y][g->p_position.x] != 'E' &&
		g->map[g->p_position.y][g->p_position.x] != '1')
		mlx_image_to_window(g->mlx, g->i_floor,
			g->p_position.x * 64, g->p_position.y * 64);
	g->p_position.x = x;
	g->p_position.y = y;
	if (g->map[g->p_position.y][g->p_position.x] == 'C')
	{
		mlx_image_to_window(g->mlx, g->i_floor,
			g->p_position.x * 64, g->p_position.y * 64);
		g->map[g->p_position.y][g->p_position.x] = '0';
		g->coin--;
		if (g->coin == 0)
			mlx_image_to_window(g->mlx, g->i_o_exit,
				g->e_position.x * 64, g->e_position.y * 64);
	}
	mlx_image_to_window(g->mlx, img, g->p_position.x * 64,
		g->p_position.y * 64);
}

static void	keypress(t_game *g, int x, int y, void *img)
{
	if (g->map[y][x] == 'E' && g->coin == 0)
	{
		mlx_close_window(g->mlx);
		ft_printf("\nYou have won\n");
	}
	else if (g->map[y][x] != '1')
	{
		images (g, x, y, img);
		g->moves++;
		ft_printf("Number of movements: %d\n", g->moves);
	}
}

void	player_move(mlx_key_data_t keydata, void *param)
{
	t_game	*g;

	g = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(g->mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		keypress(g, g->p_position.x, g->p_position.y - 1, g->i_player);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		keypress(g, g->p_position.x - 1, g->p_position.y, g->i_player);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		keypress(g, g->p_position.x, g->p_position.y + 1, g->i_player);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		keypress(g, g->p_position.x + 1, g->p_position.y, g->i_player);
}
