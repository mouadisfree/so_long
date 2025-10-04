/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_map_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 02:36:10 by mokatfi           #+#    #+#             */
/*   Updated: 2025/04/08 11:00:29 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_coll(char **map2, t_so *p)
{
	int	i;
	int	j;

	i = 0;
	while (map2[i])
	{
		j = 0;
		while (map2[i][j])
		{
			if (map2[i][j] == 'C')
				ft_putstrerror("Error\ncan't reach all collectibles\n", p);
			if (map2[i][j] == 'E' && (map2[i + 1][j] != '*' && map2[i
					- 1][j] != '*' && map2[i][j + 1] != '*' && map2[i][j
					- 1] != '*'))
				ft_putstrerror("Error\ncan't reach the exit\n", p);
			j++;
		}
		i++;
	}
}

void	check_path(int pos_x, int pos_y, char **map)
{
	map[pos_x][pos_y] = '*';
	if (map[pos_x - 1][pos_y] == '0' || map[pos_x - 1][pos_y] == 'C')
		check_path(pos_x - 1, pos_y, map);
	if (map[pos_x + 1][pos_y] == '0' || map[pos_x + 1][pos_y] == 'C')
		check_path(pos_x + 1, pos_y, map);
	if (map[pos_x][pos_y - 1] == '0' || map[pos_x][pos_y - 1] == 'C')
		check_path(pos_x, pos_y - 1, map);
	if (map[pos_x][pos_y + 1] == '0' || map[pos_x][pos_y + 1] == 'C')
		check_path(pos_x, pos_y + 1, map);
}

void	check_map_lines(char **str, t_so *p)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_strlen(str[i]) != ft_strlen(str[0]))
			ft_putstrerror("Error\nnot the same length\n", p);
		i++;
	}
}
