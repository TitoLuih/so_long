/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_to_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:58:31 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/02/25 16:19:09 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_textures(t_game *game)
{
	mlx_delete_texture(game->t_coin);
	mlx_delete_texture(game->t_floor);
	mlx_delete_texture(game->t_player_r);
	mlx_delete_texture(game->t_player_l);
	mlx_delete_texture(game->t_open_exit);
	mlx_delete_texture(game->t_closed_exit);
	mlx_delete_texture(game->t_wall);
}

int	img_error(t_game *g)
{
	if (!g->t_coin || !g->t_floor || !g->t_player_r || !g->t_player_l
		|| !g->t_closed_exit || !g->t_open_exit || !g->t_wall || !g->i_coin
		|| !g->i_floor || !g->i_player_r || !g->i_player_l || !g->i_open_exit
		|| !g->i_closed_exit || !g->i_wall)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	text_to_img(t_game *game)
{
	game->t_coin = mlx_load_png("./sprites/coin.png");
	game->t_floor = mlx_load_png("./sprites/floor.png");
	game->t_player_r = mlx_load_png("./sprites/ralphd.png");
	game->t_player_l = mlx_load_png("./sprites/ralphi.png");
	game->t_closed_exit = mlx_load_png("./sprites/c_door.png");
	game->t_open_exit = mlx_load_png("./sprites/o_door.png");
	game->t_wall = mlx_load_png("./sprites/wall.png");
	game->i_coin = mlx_texture_to_image(game->mlx, game->t_coin);
	game->i_floor = mlx_texture_to_image(game->mlx, game->t_floor);
	game->i_player_r = mlx_texture_to_image(game->mlx, game->t_player_r);
	game->i_player_l = mlx_texture_to_image(game->mlx, game->t_player_l);
	game->i_open_exit = mlx_texture_to_image(game->mlx, game->t_open_exit);
	game->i_closed_exit = mlx_texture_to_image(game->mlx, game->t_closed_exit);
	game->i_wall = mlx_texture_to_image(game->mlx, game->t_wall);
	clean_textures(game);
	if (image_error(game) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
