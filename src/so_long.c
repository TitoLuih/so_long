/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:00:31 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/03/12 20:20:42 by lruiz-to         ###   ########.fr       */
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

static void	init_struct(t_game *game)
{
	game->map = NULL;
	game->map_copy = NULL;
	game->lines = 0;
	game->columns = 0;
	game->coin = 0;
	game->exit = 0;
	game->moves = 0;
	game->player = 0;
}

int	main(int argc, char **argv)
{
	t_game	*g;

	if (argc != 2)
		return (ft_error("Not enough arguments"));
	if (ext_checker(argv[1]) == EXIT_FAILURE)
		return (ft_error("Not the correct extension"));
	g = ft_calloc(1, sizeof(t_game));
	init_struct(g);
	if (read_map(g, argv[1]) == EXIT_FAILURE)
		return (free_maps(g), EXIT_FAILURE);
	if (map_checker(g) == 1)
		return (free_maps(g), EXIT_FAILURE);
	g->mlx = mlx_init(64 * g->columns, 64 * g->lines, "SO_LONG", false);
	if (!g->mlx)
		return (free_maps(g), EXIT_FAILURE);
	if (text_to_img(g) == 1 || image_to_window(g) == 1)
		return (free_maps(g), EXIT_FAILURE);
	mlx_key_hook(g->mlx, &player_move, g);
	mlx_loop(g->mlx);
	mlx_terminate(g->mlx);
	return (free_maps(g), EXIT_SUCCESS);
}
