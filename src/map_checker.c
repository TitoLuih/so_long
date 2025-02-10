/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:01:26 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/02/10 13:11:12 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ext_checker(char *map_name)
{
	int i;
	
	i = ft_strlen(map_name);
	if ((map_name[i - 1] == 'r' && map_name[i - 2] == 'e')
		&& (map_name[i - 3] == 'b' && map_name[i - 4] == '.'))
		{
			write(1, "g",1);
			return (EXIT_SUCCESS);
		}
	else
		return (EXIT_FAILURE);
}

int main (int argc, char **argv)
{
	char *map_name;

	if (argc == 2)
	{
		ext_checker(&argv[1][0]);
	}
	else
		write (1, "x",1);
}