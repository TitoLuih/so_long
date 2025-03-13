/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_to_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:58:31 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/03/13 17:56:13 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_textures(t_game *game)
{
	mlx_delete_texture(game->t_coin);
	mlx_delete_texture(game->t_floor);
	mlx_delete_texture(game->t_player);
	mlx_delete_texture(game->t_o_exit);
	mlx_delete_texture(game->t_c_exit);
	mlx_delete_texture(game->t_wall);
}

int	text_to_img(t_game *game)
{
	game->t_coin = mlx_load_png("./sprites/coin.png");
	game->t_floor = mlx_load_png("./sprites/floor.png");
	game->t_player = mlx_load_png("./sprites/isaac.png");
	game->t_c_exit = mlx_load_png("./sprites/c_door.png");
	game->t_o_exit = mlx_load_png("./sprites/o_door.png");
	game->t_wall = mlx_load_png("./sprites/wall.png");
	if (!game->t_coin || !game->t_floor || !game->t_player
		|| !game->t_c_exit || !game->t_o_exit || !game->t_wall)
		return (ft_error("Could not load the textures"));
	else
	{
		game->i_coin = mlx_texture_to_image(game->mlx, game->t_coin);
		game->i_floor = mlx_texture_to_image(game->mlx, game->t_floor);
		game->i_player = mlx_texture_to_image(game->mlx, game->t_player);
		game->i_o_exit = mlx_texture_to_image(game->mlx, game->t_o_exit);
		game->i_c_exit = mlx_texture_to_image(game->mlx, game->t_c_exit);
		game->i_wall = mlx_texture_to_image(game->mlx, game->t_wall);
		clean_textures(game);
		if (!game->i_coin || !game->i_floor || !game->i_player
			|| !game->i_o_exit || !game->i_c_exit || !game->i_wall)
			return (ft_error("Could not load the images"));
	}
	return (EXIT_SUCCESS);
}
