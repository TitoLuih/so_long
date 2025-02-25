/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:21:05 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/02/26 12:11:27 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	images(t_game *g, int x, int y, void *img)
{
	if (g->map[g->p_position.y][g->p_position.x] == 'E')
		mlx_image_to_window(g->mlx, g->i_closed_exit, g->p_position.x * 50,
			g->p_position.y * 50);
	if (g->map[g->p_position.y][g->p_position.x] != 'E' &&
		g->map[g->p_position.y][g->p_position.x] != '1')
		mlx_image_to_window(g->mlx, g->i_floor,
			g->p_position.x * 50, g->p_position.y * 50);
	g->p_position.x = x;
	g->p_position.y = y;
	if (g->map[g->p_position.y][g->p_position.x] == 'C')
	{
		mlx_image_to_window(g->mlx, g->i_floor,
			g->p_position.x * 50, g->p_position.y * 50);
		g->map[g->p_position.y][g->p_position.x] = '0';
		g->coin--;
		if (g->coin == 0)
			mlx_image_to_window(g->mlx, g->i_open_exit,
				g->e_position.x * 50, g->e_position.y * 50);
	}
	mlx_image_to_window(g->mlx, img, g->p_position.x * 50,
		g->p_position.y * 50);
}

static void	keypress(t_game *g, int x, int y, void *img)
{
	g->moves++;
	ft_printf("Número de movimientos: %d\n", g->moves);
	if (g->map[y][x] == 'E' && g->coin == 0)
	{
		mlx_close_window(g->mlx);
		ft_printf("\nHas ganado\n");
	}
	else if (g->map[y][x] != '1')
		images (g, x, y, img);
}

void	player_move(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x, game->p_position.y - 1, game->i_player_r);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x - 1, game->p_position.y, game->i_player_l);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x, game->p_position.y + 1, game->i_player_r);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x + 1, game->p_position.y, game->i_player_r);
}