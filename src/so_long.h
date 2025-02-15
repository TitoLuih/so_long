/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:01:17 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/02/10 13:10:15 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libs/libft/libft.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game
{
	char			**map;
	char			**map_copy;
	int				lines;
	int				columns;
	int				c;
	int				e;
	int				p;
	t_point			p_position;
	int				c_copy;
	int				e_copy;
	int				moves;
	t_point			local_exit;
	mlx_t			*mlx;
	mlx_texture_t	*t_coin;
	mlx_image_t		*i_coin;
	mlx_texture_t	*t_floor;
	mlx_image_t		*i_floor;
	mlx_texture_t	*t_player_r;
	mlx_image_t		*i_player_r;
	mlx_texture_t	*t_player_l;
	mlx_image_t		*i_player_l;
	mlx_texture_t	*t_open_exit;
	mlx_image_t		*i_open_exit;
	mlx_texture_t	*t_closed_exit;
	mlx_image_t		*i_closed_exit;
	mlx_texture_t	*t_wall;
	mlx_image_t		*i_wall;
}	t_game;

#endif